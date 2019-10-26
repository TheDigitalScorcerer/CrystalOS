#include "keyboard_events.h"
#include "lib/math.h"
#include "lib/stdlib.h"
#include "lib/memory.h"

// var ^= (-(!(input >> 7)) ^ var) & 1;

void kb_ps2sc1_update_pointed_key(unsigned char* key, unsigned char input) {
    *key ^= (-(!(input >> 7)) ^ *key) & 1;
}
void kb_ps2sc1_update_pointed_short(unsigned char* key, unsigned char input, unsigned char val) {
    *key ^= (-(!(input >> 7)) ^ *key) & val;
}

void kb_ps2sc2_update_pointed_key(unsigned char* key, unsigned short input) {
    *key ^= (-(!(input >> 15)) ^ *key) & 1;
}
void kb_ps2sc2_update_pointed_short(unsigned char* key, unsigned short input, unsigned char val) {
    *key ^= (-(!(input >> 15)) ^ *key) & val;
}

void update_keyevents(long address) {
    struct keystate backup;
    memcpy(&keyboard_state, &backup, sizeof(struct keystate));
    unsigned char input;
    unsigned char scancodeset = 2;
    if (scancodeset == 1) {
        switch (input & ~128)
        {
        case 0x01:
            kb_ps2sc1_update_pointed_key(&keyboard_state.esc, input);
            break;

        case 0x02:
            kb_ps2sc1_update_pointed_key(&keyboard_state.num1, input);
            break;
        case 0x03:
            kb_ps2sc1_update_pointed_key(&keyboard_state.num2, input);
            break;
        case 0x04:
            kb_ps2sc1_update_pointed_key(&keyboard_state.num3, input);
            break;
        case 0x05:
            kb_ps2sc1_update_pointed_key(&keyboard_state.num4, input);
            break;
        case 0x06:
            kb_ps2sc1_update_pointed_key(&keyboard_state.num5, input);
            break;
        case 0x07:
            kb_ps2sc1_update_pointed_key(&keyboard_state.num6, input);
            break;
        case 0x08:
            kb_ps2sc1_update_pointed_key(&keyboard_state.num7, input);
            break;
        case 0x09:
            kb_ps2sc1_update_pointed_key(&keyboard_state.num8, input);
            break;
        case 0x0A:
            kb_ps2sc1_update_pointed_key(&keyboard_state.num9, input);
            break;
        case 0x0B:
            kb_ps2sc1_update_pointed_key(&keyboard_state.num0, input);
            break;

        case 0x0C:
            keyboard_state.dash ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x0D:
            keyboard_state.equals ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x0E:
            keyboard_state.bs ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x0F:
            keyboard_state.tab ^= (-(!(input >> 7)) ^ var) & 1;
            break;

        case 0x10:
            keyboard_state.q ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x11:
            keyboard_state.w ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x12:
            keyboard_state.e ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x13:
            keyboard_state.r ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x14:
            keyboard_state.t ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x15:
            keyboard_state.y ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x16:
            keyboard_state.u ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x17:
            keyboard_state.i ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x18:
            keyboard_state.o ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x19:
            keyboard_state.p ^= (-(!(input >> 7)) ^ var) & 1;
            break;

        case 0x1A:
            keyboard_state.squareopen ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x1B:
            keyboard_state.squareclose ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x1C:
            keyboard_state.enter ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x1D:
            keyboard_state.modifiers |= 4;
            break;

        case 0x1E:
            keyboard_state.a ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x1F:
            keyboard_state.s ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x20:
            keyboard_state.d ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x21:
            keyboard_state.f ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x22:
            keyboard_state.g ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x23:
            keyboard_state.h ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x24:
            keyboard_state.j ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x25:
            keyboard_state.k ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x26:
            keyboard_state.l ^= (-(!(input >> 7)) ^ var) & 1;
            break;

        case 0x27:
            keyboard_state.semicolon ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x28:
            keyboard_state.quote ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x29:
            keyboard_state.backtick ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x2A:
            keyboard_state.modifiers |= 1;
            break;
        case 0x2B:
            keyboard_state.backslash ^= (-(!(input >> 7)) ^ var) & 1;
            break;

        case 0x2C:
            keyboard_state.z ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x2D:
            keyboard_state.x ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x2E:
            keyboard_state.c ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x2F:
            keyboard_state.v ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x30:
            keyboard_state.b ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x31:
            keyboard_state.n ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x32:
            keyboard_state.m ^= (-(!(input >> 7)) ^ var) & 1;
            break;

        case 0x33:
            keyboard_state.comma ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x34:
            keyboard_state.dot ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x35:
            keyboard_state.foreslash ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x36:
            keyboard_state.modifiers |= 2; // Right Shift
            break;
        case 0x37:
            keyboard_state.keypad |= 2048; // Multiply
            break;
        case 0x38:
            keyboard_state.modifiers |= 16; // Left Alt
            break;
        case 0x39:
            keyboard_state.space ^= (-(!(input >> 7)) ^ var) & 1;
            break;
        case 0x3A:
            keyboard_state.modifiers ^= 256; // Caps lock
            break;
        // F1-10 keys below
        case 0x45:
            keyboard_state.modifiers ^= 1024; // Num lock
            break;
        case 0x46:
            keyboard_state.modifiers ^= 512; // Scroll lock
            break;

        case 0x47:
            keyboard_state.keypad |= 128;
            break;
        case 0x48:
            keyboard_state.keypad |= 256;
            break;
        case 0x49:
            keyboard_state.keypad |= 512;
            break;
        case 0x4A:
            keyboard_state.keypad |= 4096;
            break;
        case 0x4B:
            keyboard_state.keypad |= 16;
            break;
        case 0x4C:
            keyboard_state.keypad |= 32;
            break;
        case 0x4D:
            keyboard_state.keypad |= 64;
            break;
        case 0x4E:
            keyboard_state.keypad |= 8192;
            break;
        case 0x4F:
            keyboard_state.keypad |= 2;
            break;
        case 0x50:
            keyboard_state.keypad |= 4;
            break;
        case 0x51:
            keyboard_state.keypad |= 8;
            break;
        case 0x52:
            keyboard_state.keypad |= 1;
            break;
        case 0x53:
            keyboard_state.keypad |= 32768;
            break;

        case 0x57:
            keyboard_state.fs |= 2048;
            break;
        case 0x58:
            keyboard_state.fs |= 4096;
            break;
        default:
            break;
        }

        if (input >= 0x3B && input <= 0x44) {
            keyboard_state.fs |= pow(2, input - 0x3B);
        }

        if (!memcmp(&backup, &keyboard_state, sizeof(struct keystate))) {
            newkbevent = 1;
            lastkbevent = input;
            if (kbbufferlen >= 64) {
                for (unsigned char i = 1; i < 64; i++)
                {
                    kbbuffer[i - 1] = kbbuffer[i];
                }
            }
            kbbuffer[kbbufferlen] = input;
            if (kbbufferlen < 64) {
                kbbufferlen++;
            }
        }
    }
}