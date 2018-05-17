
#ifndef PINNAMES_H
#define PINNAMES_H

typedef enum {
    PIN_INPUT,
    PIN_OUTPUT,
    PIN_INPUT_OUTPUT	//pin state can be set and read back
} PinDirection;

typedef enum {
    D0=0,
    D1,
    D2,
    D3,
    D4,
    D5,
    D6,
    D7,
    D8,
    D9,
    D10,
    D11,
    D12,
    D13,
    D14,

    A0,
    A4,

    PB30,

    LED1 = PB30,
    LED2 = PB30,
    LED3 = PB30,
    LED4 = PB30,

    // Not connected
    NC = (int)0xFFFFFFFF
} PinName;

typedef enum {
    PullNone = 0,
    PullUp = 1,
    PullDown = 2,
    PullDefault = PullUp
} PinMode;

#endif
