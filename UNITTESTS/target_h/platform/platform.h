#ifndef MBED_PLATFORM_H
#define MBED_PLATFORM_H

#include "inttypes.h"
#include "PinNames.h"

#ifndef NVIC_SystemReset
#define NVIC_SystemReset            __NVIC_SystemReset
static void __NVIC_SystemReset(void)
{

}
#endif

typedef unsigned int  mode_t;

typedef struct {
    PinName pin;
} gpio_t;

struct spi_s {

};

struct gpio_irq_s {
    unsigned int id;
    PinName pinname;
};

#define NAME_MAX 255    ///< Maximum size of a name in a file path

struct dirent {
    char d_name[NAME_MAX+1]; ///< Name of file
    uint8_t d_type;          ///< Type of file
};

#endif
