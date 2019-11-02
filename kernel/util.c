void memcpy(char* src, char* dst, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        *(dst + i) = *(src + i);
    }
}