#include "drivers/TimerEvent.h"

namespace mbed {

TimerEvent::TimerEvent() {
}

TimerEvent::TimerEvent(const ticker_data_t *data) {
}

void TimerEvent::irq(uint32_t id) {
}

TimerEvent::~TimerEvent() {
}

// insert in to linked list
void TimerEvent::insert(timestamp_t timestamp) {
}

void TimerEvent::insert_absolute(us_timestamp_t timestamp) {
}

void TimerEvent::remove() {
}

}
