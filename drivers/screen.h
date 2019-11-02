extern unsigned char port_byte_in(unsigned short port);
extern void port_byte_out(unsigned short port, unsigned char data);
extern unsigned short port_word_in(unsigned short port);
extern void port_word_out(unsigned short port, unsigned short data);

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0f

// I/O Ports
#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5

int get_screen_offset(int col, int row) {
    return (row * MAX_ROWS + col) * 2;
}

int get_cursor() {
    port_byte_out(REG_SCREEN_CTRL, 14);
    int offset = port_byte_in(REG_SCREEN_DATA) << 8;
    port_byte_out(REG_SCREEN_CTRL, 15);
    offset += port_byte_in(REG_SCREEN_DATA);
    return offset * 2;
}

void set_cursor(int offset) {
    offset /= 2;
    port_byte_out(REG_SCREEN_CTRL, 14);
    port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset >> 8));
    port_byte_out(REG_SCREEN_CTRL, 15);
    port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset % 256));
}

void print_char(char character, int col, int row, char attribute_byte) {
    unsigned char *vidmem = (unsigned char*) VIDEO_ADDRESS;

    if (!attribute_byte) {
        attribute_byte = WHITE_ON_BLACK;
    }
    int offset;
    if (col >= 0 && row >= 0) {
        offset = get_screen_offset(col, row);
    } else {
        offset = get_cursor();
    }

    if (character == '\n') {
        int rows = offset / (2 * MAX_COLS);
        offset = get_screen_offset(MAX_COLS - 1, rows);
    } else {
        vidmem[offset] = character;
        vidmem[offset + 1] = attribute_byte;
    }

    offset += 2;
    //offset = handle_scrolling(offset);
    set_cursor(offset);
}

void print_at(char* message, int col, int row, unsigned char attr_byte) {
    // Update the cursor if col and row not negative.
    if (col >= 0 && row >= 0) {
        set_cursor(get_screen_offset(col, row));
    }
    // Loop  through  each  char of the  message  and  print  it.
    int i = 0;
    while(message[i] != 0) {
        print_char(message[i++], col, row, attr_byte);
    }
}

void clear_screen() {
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            print_char(0, j, i, WHITE_ON_BLACK);
        }
    }
    set_cursor(get_screen_offset(0, 0));
}

void print(char* message, unsigned char attr_byte) {
    print_at(message, -1, -1, attr_byte);
}