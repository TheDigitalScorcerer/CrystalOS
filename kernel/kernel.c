char* video_address = 0xb8000;


int main() {
    *video_address = 'X';
    return 0;
}