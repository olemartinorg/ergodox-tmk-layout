/*
Copyright 2015 Ole Martin Handeland <tmk_contact@olemartin.org>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "recorder.h"
#include "print.h"
#include "action.h"
#include "action_util.h"
#include "debug.h"
#include "wait.h"
#include <stdbool.h>

#define NUM_SLOTS 5
#define NUM_RECORDS 100

typedef struct {
    recorded_event_t event;
    bool send;
    uint8_t code;
} record_t;

static bool is_recording = false;
static bool is_playing = false;

static uint8_t r_slot = 0;
static uint16_t r_idx = 0;
static uint16_t r_idx_max[NUM_SLOTS];
static uint8_t r_interval = 0;
static record_t r_arr[NUM_SLOTS][NUM_RECORDS];

void recorder_add(recorded_event_t event, uint8_t code)
{
    if(!is_recording || r_idx > NUM_RECORDS - 1)
        return;

    if(code == 0 &&
        (event == E_ADD_KEY || event == E_ADD_MOD || event == E_DEL_KEY || event == E_DEL_MOD))
        // If not adding or removing anything, don't waste the space!
        return;

    if(r_idx &&
        r_arr[r_slot][r_idx-1].send &&
        event == E_DEL_KEY &&
        r_arr[r_slot][r_idx-1].event == E_ADD_KEY &&
        r_arr[r_slot][r_idx-1].code == code)
    {
        // A simple D(key) and U(key) kan be combined to save space
        r_arr[r_slot][r_idx-1].event = E_TYPE;
        return;
    }

    if(r_idx && event == E_DEL_MOD &&
        r_arr[r_slot][r_idx-1].event == E_ADD_MOD &&
        r_arr[r_slot][r_idx-1].code == code)
    {
        // Adding and then removing a mod is pretty much useless
        r_idx--;
        r_idx_max[r_slot]--;
    }

    if(r_idx && (
            (event == E_ADD_MOD && r_arr[r_slot][r_idx-1].event == E_ADD_MOD) ||
            (event == E_DEL_MOD && r_arr[r_slot][r_idx-1].event == E_DEL_MOD)
        ))
    {
        // Adding mods can be combined, to use less space
        r_arr[r_slot][r_idx-1].code |= code;
        return;
    }

    dprintf("Recorder: Adding type(%u), code(%u) to index %u\n", event, code, r_idx);

    record_t e;
    e.event = event;
    e.code = code;

    r_arr[r_slot][r_idx] = e;
    r_idx++;
    r_idx_max[r_slot]++;
}

void recorder_send(void)
{
    if(!is_recording || r_idx > NUM_RECORDS - 1)
        return;
    if(r_idx)
        r_arr[r_slot][r_idx-1].send = true;
}

static void recorder_set_slot(uint8_t new_slot)
{
    if(new_slot > NUM_SLOTS - 1)
        return;
    dprintf("Recorder: setting slot to %u\n", new_slot);
    r_slot = new_slot;
    r_idx = 0;
}

bool recorder_is_recording(void)
{
    if(is_recording && r_idx < NUM_RECORDS)
        return true;
    return false;
}

bool recorder_is_playing(void)
{
    return is_playing;
}

void recorder_start(uint8_t slot)
{
    recorder_set_slot(slot);
    dprintf("Recorder: Started recording\n");
    is_recording = true;
    r_idx = 0;
    r_idx_max[r_slot] = 0;
}

void recorder_stop(uint8_t slot)
{
    recorder_set_slot(slot);
    dprintf("Recorder: Stopped recording\n");
    is_recording = false;
    r_idx = 0;
}

void recorder_toggle(uint8_t slot)
{
    if(is_recording)
        recorder_stop(slot);
    else
        recorder_start(slot);
}

void recorder_clear(uint8_t slot)
{
    recorder_stop(slot);
    dprintf("Recorder: clearing slot\n");
    r_idx_max[r_slot] = 0;
}

void recorder_set_interval(uint8_t interval)
{
    interval *= 16;
    r_interval = interval;
    dprintf("Recorder: Setting interval to %u\n", interval);
}

void recorder_incr_interval(uint8_t interval)
{
    interval *= 16;
    uint8_t remaining = UINT8_MAX - r_interval;
    if(interval > remaining) {
        interval = remaining;
    }

    r_interval += interval;
    dprintf("Recorder: Increasing interval to %u\n", r_interval);
}

void recorder_decr_interval(uint8_t interval)
{
    interval *= 16;
    if(interval > r_interval) {
        interval = r_interval;
    }

    r_interval -= interval;
    dprintf("Recorder: Decreasing interval to %u\n", r_interval);
}

void recorder_play(uint8_t slot)
{
    if (is_playing)
        return;
    is_playing = true;

    recorder_stop(slot);
    dprintf("Recorder: starting playing\n");
    uint16_t i;

    for (i = 0; i <= r_idx_max[r_slot]; i++) {
        dprintf(
            "   type(%u), code(%u) from index %u",
            r_arr[r_slot][i].event, r_arr[r_slot][i].code, i
        );
        switch(r_arr[r_slot][i].event) {
            case E_ADD_KEY:
                add_key(r_arr[r_slot][i].code);
                break;
            case E_DEL_KEY:
                del_key(r_arr[r_slot][i].code);
                break;
            case E_ADD_MOD:
                add_mods(r_arr[r_slot][i].code);
                break;
            case E_DEL_MOD:
                del_mods(r_arr[r_slot][i].code);
                break;
            case E_TYPE:
                add_key(r_arr[r_slot][i].code);
                send_keyboard_report();
                del_key(r_arr[r_slot][i].code);
                break;
            case E_CLEAR_KEYS:
                clear_keys();
                break;
            case E_SET_MODS:
                set_mods(r_arr[r_slot][i].code);
                break;
            case E_CLEAR_MODS:
                clear_mods();
                break;
        }
        if(r_arr[r_slot][i].send) {
            dprintf(" + send");
            send_keyboard_report();
            if(r_interval) {
                { uint8_t ms = r_interval; while (ms--) wait_ms(1); }
            }
        }
        dprintf("\n");
    }

    clear_keyboard();
    dprintf("Recorder: finished playing\n");
    is_playing = false;
}
