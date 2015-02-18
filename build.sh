#!/bin/bash

cd "$(dirname "$0")"

if [[ ! -e "tmk_keyboard" ]]; then
    echo " * Cloning TMK keyboard firmware (from cub-uanic)"
    git clone --quiet https://github.com/cub-uanic/tmk_keyboard.git
fi

if [[ ! -L "tmk_keyboard/keyboard/ergodox/keymap_olemartinorg.h" ]]; then
    echo " * Adding symbolic link to keyboard mapping"
    ln -s keymap_olemartinorg.h tmk_keyboard/keyboard/ergodox/keymap_olemartinorg.h
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

if ! hash avr-gcc 2>/dev/null; then
    echo "Error: You do not have avr-gcc installed. Run sudo apt-get install gcc-avr binutils-avr avr-libc"
    exit
fi

cd tmk_keyboard/keyboard/ergodox

echo " * Cleaning up after last build"
make -f Makefile.lufa clean >/dev/null

echo " * Building"
make -f Makefile.lufa micro >/dev/null

cd ../../..

if [[ -f "tmk_keyboard/keyboard/ergodox/ergodox_lufa.hex" ]]; then
    echo " * Copying hex file"
    cp tmk_keyboard/keyboard/ergodox/ergodox_lufa.hex .

    echo " * Please press the reset-button on your ErgoDox"
    teensy_loader_cli/teensy_loader_cli -mmcu=atmega32u4 -w ergodox_lufa.hex

    echo " * All done! Now test out your new layout!"

else

    echo "Error: Build failed, for some reason"

fi
