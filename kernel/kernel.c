char* video_address = 0xb8000;


int main() {
    //return 0;
    *video_address = 'X';
    return 0;
}