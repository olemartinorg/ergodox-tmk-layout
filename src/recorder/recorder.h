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

#include <stdint.h>

typedef enum {
    E_ADD_KEY    = 0b000,
    E_DEL_KEY    = 0b001,
    E_ADD_MOD    = 0b010,
    E_DEL_MOD    = 0b011,
    E_TYPE       = 0b100,
    E_CLEAR_KEYS = 0b101,
    E_SET_MODS   = 0b110,
    E_CLEAR_MODS = 0b111,
} recorded_event_t;

void recorder_add(recorded_event_t event, uint8_t code);
void recorder_send(void);
void recorder_toggle(uint8_t slot);
void recorder_start(uint8_t slot);
void recorder_stop(uint8_t slot);
void recorder_clear(uint8_t slot);
void recorder_play(uint8_t slot);
