#ifndef KEYBOARD_EVENTS_H
#define KEYBOARD_EVENTS_H 1

unsigned char newkbevent = 0;
unsigned char lastkbevent = 0;
unsigned char kbbuffer[64];
unsigned char kbbufferlen = 0;

struct keystate {
    /* Modifiers:
    0: lshift
    1: rshift
    2: lctrl
    3: rctrl
    4: lalt
    5: ralt
    6: lcrystal
    7: rcrystal
    8: caps
    9: scroll
    A: num
    */
    unsigned short modifiers;
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    unsigned char e;
    unsigned char f;
    unsigned char g;
    unsigned char h;
    unsigned char i;
    unsigned char j;
    unsigned char k;
    unsigned char l;
    unsigned char m;
    unsigned char n;
    unsigned char o;
    unsigned char p;
    unsigned char q;
    unsigned char r;
    unsigned char s;
    unsigned char t;
    unsigned char u;
    unsigned char v;
    unsigned char w;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char num1;
    unsigned char num2;
    unsigned char num3;
    unsigned char num4;
    unsigned char num5;
    unsigned char num6;
    unsigned char num7;
    unsigned char num8;
    unsigned char num9;
    unsigned char num0;
    unsigned char backtick;
    unsigned char dash;
    unsigned char equals;
    unsigned char backslash;
    unsigned char foreslash;
    unsigned char semicolon;
    unsigned char quote;
    unsigned char dot;
    unsigned char comma;
    unsigned char tab;
    unsigned char squareopen;
    unsigned char squareclose;
    unsigned char bs;
    unsigned char esc;
    unsigned char home;
    unsigned char pgup;
    unsigned char pgdn;
    unsigned char end;
    unsigned char del;
    unsigned char prtsc;
    unsigned char ins;
    unsigned char enter;
    unsigned short fs; // The F row (Can go 1-16)
    unsigned short keypad;
    /* Keypad:
    0: 0
    1: 1
    2: 2
    3: 3
    4: 4
    5: 5
    6: 6
    7: 7
    8: 8
    9: 9
    A: /
    B: *
    C: -
    D: +
    E: Enter
    F: Del/.
    */
   unsigned char space; // How did I forget this???
} keyboard_state;

#endif