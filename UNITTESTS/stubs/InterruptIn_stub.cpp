
#include "drivers/InterruptIn.h"

#include "InterruptIn_stub.h"


namespace mbed {

Callback<void()> InterruptIn_stub::callback1 = NULL;
Callback<void()> InterruptIn_stub::callback2 = NULL;
Callback<void()> InterruptIn_stub::callback3 = NULL;
Callback<void()> InterruptIn_stub::callback4 = NULL;
Callback<void()> InterruptIn_stub::callback5 = NULL;
Callback<void()> InterruptIn_stub::callback6 = NULL;
Callback<void()> InterruptIn_stub::callback7 = NULL;


InterruptIn::InterruptIn(PinName pin)
{

}

InterruptIn::~InterruptIn()
{

}

void InterruptIn::rise(Callback<void()> func) 
{
    if (!InterruptIn_stub::callback1) {
        InterruptIn_stub::callback1 = func;
        return;
    }
    if (!InterruptIn_stub::callback2) {
        InterruptIn_stub::callback2 = func;
        return;
    }
    if (!InterruptIn_stub::callback3) {
        InterruptIn_stub::callback3 = func;
        return;
    }
    if (!InterruptIn_stub::callback4) {
        InterruptIn_stub::callback4 = func;
        return;
    }
    if (!InterruptIn_stub::callback5) {
        InterruptIn_stub::callback5 = func;
        return;
    }
    if (!InterruptIn_stub::callback6) {
        InterruptIn_stub::callback6 = func;
        return;
    }
    if (!InterruptIn_stub::callback7) {
        InterruptIn_stub::callback7 = func;
        return;
    }
}

}


