#!/bin/bash

set -e

cd "$(dirname "$0")"

if [[ ! -e "tmk_keyboard" ]]; then
    echo " * Cloning TMK keyboard firmware (from cub-uanic)"
    git clone --quiet https://github.com/cub-uanic/tmk_keyboard.git
    cd tmk_keyboard
    git checkout -b olemartinorg a620448e7bfb1a5ec75b69c0dadb81444aa51c2e
    rm -rf .git

    echo " * Patching in references to our keymap"
    echo "olemartinorg: OPT_DEFS += -DKEYMAP_OLEMARTINORG" >> keyboard/ergodox/Makefile.lufa
    echo "olemartinorg: all" >> keyboard/ergodox/Makefile.lufa

    cd keyboard/ergodox
    ln -s ../../../src/keymap_olemartinorg.h keymap_olemartinorg.h
    echo " * Patching keymap.c"
    patch --quiet keymap.c < ../../../src/keymap.c.diff
    echo " * Patching matrix.c"
    patch --quiet matrix.c < ../../../src/matrix.c.diff
    echo " * Patching config.h"
    patch --quiet config.h < ../../../src/config.h.diff

    cd ../..
    echo " * [Recorder] Patching common.mk"
    patch --quiet common.mk < ../src/recorder/common.mk.diff
    cd common
    echo " * [Recorder] Patching action.c"
    patch --quiet action.c < ../../src/recorder/action.c.diff
    echo " * [Recorder] Patching action_code.h"
    patch --quiet action_code.h < ../../src/recorder/action_code.h.diff
    echo " * [Recorder] Patching action_util.h"
    patch --quiet action_util.c < ../../src/recorder/action_util.c.diff
    echo " * [Recorder] Linking recorder.h"
    ln -s ../../src/recorder/recorder.h recorder.h
    echo " * [Recorder] Linking recorder.c"
    ln -s ../../src/recorder/recorder.c recorder.c

    cd ../../
fi

if [[ ! -e "/usr/lib/libusb.so" && ! -e "/usr/lib/x86_64-linux-gnu/libusb.so" ]]; then
    echo "Error: You do not have libusb-dev installed. Run sudo apt-get install libusb-dev"
    exit
fi

if [[ ! -e "teensy_loader_cli" ]]; then
    echo " * Downloading Teensy Loader CLI"
    wget --quiet https://www.pjrc.com/teensy/teensy_loader_cli.2.1.zip
    unzip teensy_loader_cli.2.1.zip >/dev/null
    rm teensy_loader_cli.2.1.zip
    cd teensy_loader_cli
    echo " * Building Teensy Loader CLI"
    make >/dev/null
    cd ..
fi

if [[ ! -e "hid_listen" ]]; then
    echo " * Downloading Teensy Debugger"
    wget --quiet https://www.pjrc.com/teensy/hid_listen_1.01.zip
    unzip hid_listen_1.01.zip >/dev/null
    rm hid_listen_1.01.zip
    cd hid_listen
    echo " * Building Teensy Debugger"
    make >/dev/null
    cd ..
fi

if ! hash avr-gcc 2>/dev/null; then
    echo "Error: You do not have avr-gcc installed. Run sudo apt-get install gcc-avr binutils-avr avr-libc"
    exit
fi

echo " * Cleaning up after last build"
[[ -f "ergodox_lufa.hex" ]] && rm ergodox_lufa.hex
cd tmk_keyboard/keyboard/ergodox
make -f Makefile.lufa clean >/dev/null

echo " * Building"
make -f Makefile.lufa olemartinorg >/dev/null

cd ../../..

if [[ -f "tmk_keyboard/keyboard/ergodox/ergodox_lufa.hex" ]]; then
    echo " * Copying hex file"
    cp tmk_keyboard/keyboard/ergodox/ergodox_lufa.hex .

    echo " * Please press the reset-button on your ErgoDox"
    teensy_loader_cli/teensy_loader_cli -mmcu=atmega32u4 -w ergodox_lufa.hex

    echo " * All done! Now test out your new layout!"
    echo " * Connecting debugger (press the D-button while booting the keyboard to enable debugging)"
    sudo hid_listen/hid_listen

else

    echo "Error: Build failed, for some reason"

fi
