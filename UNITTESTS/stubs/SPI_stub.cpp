
#include "SPI.h"
#include "SPI_stub.h"

namespace mbed {


int SPI_stub::int_value = 0;

SPI::SPI(PinName mosi, PinName miso, PinName sclk, PinName ssel)
{

}

void SPI::format(int bits, int mode)
{
}

void SPI::frequency(int hz)
{
}

void SPI::aquire()
{
}

int SPI::write(int value)
{
    return SPI_stub::int_value;
}

int SPI::write(const char *tx_buffer, int tx_length, char *rx_buffer, int rx_length)
{
    return SPI_stub::int_value;
}

void SPI::lock() {

}

void SPI::unlock() {

}

}


