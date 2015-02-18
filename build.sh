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

if ! hash avr-gcc 2>/dev/null; then
    echo "Error: You do not have avr-gcc installed. Run sudo apt-get install gcc-avr binutils-avr avr-libc"
    exit
fi

cd tmk_keyboard/keyboard/ergodox

echo " * Cleaning up after last build"
make -f Makefile.pjrc clean >/dev/null

echo " * Building"
make -f Makefile.pjrc >/dev/null

if [[ -f "ergodox_pjrc.eep" ]]; then
    echo " * Copying eep file"
    cp ergodox_pjrc.eep ../../../

    echo " * Copying hex file"
    cp ergodox_pjrc.hex ../../../

    echo
    echo " *        If this is the first time using the TMK firmware,"
    echo " *        copy the eep file to your ergodox using the teensy"
    echo " *        loader, then press the reset button"
    echo
    echo " * Copy the hex file, then press the reset button"
fi
