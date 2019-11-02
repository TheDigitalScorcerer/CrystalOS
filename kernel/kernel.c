extern unsigned char port_byte_in(unsigned short port);
extern void port_byte_out(unsigned short port, unsigned char data);
extern unsigned short port_word_in(unsigned short port);
extern void port_word_out(unsigned short port, unsigned short data);

extern void print(char*, unsigned char);

int main() {
    //return 0;
    print("Hello, world!\n", 0);
    print("Hi!", 0);
    return 0;
}