#include "xlaudio.h"
#include "xlaudio_armdsp.h"

#define BLOCKSIZE 64

extern uint16_t *largearray;

void processBuffer(uint16_t x[BLOCKSIZE], uint16_t y[BLOCKSIZE]) {
    static int block = 0;
    memcpy(y, largearray + block * BLOCKSIZE, BLOCKSIZE *2);
    block = (block + 1561) % 1562;
}

#include <stdio.h>

int main(void) {
    WDT_A_hold(WDT_A_BASE);

    xlaudio_init_dma(FS_16000_HZ, XLAUDIO_J1_2_IN, BUFLEN_64, processBuffer);
    xlaudio_run();

    return 1;
}

