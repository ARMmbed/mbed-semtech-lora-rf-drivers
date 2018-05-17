#include "drivers/Timer.h"

namespace mbed {

Timer::Timer() {
}

Timer::Timer(const ticker_data_t *data) {

}

Timer::~Timer() {
}

void Timer::start() {
}

void Timer::stop() {
}

int Timer::read_us() {
    return 0;
}

float Timer::read() {
    return 0.0f;
}

int Timer::read_ms() {
    return 0;
}

us_timestamp_t Timer::read_high_resolution_us() {
    return 0;
}

us_timestamp_t Timer::slicetime() 
{
    return 0;
}

void Timer::reset() {
}

Timer::operator float() {
    return read();
}

}
