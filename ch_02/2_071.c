typedef unsigned packed_t;

// I still don't quite understand this question
int xtype(packed_t word, int bytenum) {
    int shift = (3 - bytenum) << 3;
    return ((int)(word << shift)) >> 24;
}