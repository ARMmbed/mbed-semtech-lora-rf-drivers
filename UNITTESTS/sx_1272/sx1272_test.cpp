/*
 * Copyright (c) 2015, Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "CppUTest/TestHarness.h"

#include "LoRaRadio.h"
#include "SX1272_LoRaRadio.h"
#include "EventQueue.h"

#include "InterruptIn_stub.h"
#include "SPI_stub.h"

using namespace events;
using namespace mbed;

static void handle_tx_done(void)
{
}

static void handle_rx_done(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr)
{
}

static void handle_rx_error(void)
{
}

static void handle_rx_timeout(void)
{
}

static void handle_tx_timeout(void)
{

}



TEST_GROUP(sx1272_test)
{
    LoRaRadio* unit;
//    SX1272_LoRaRadio* unit;

    radio_events_t events;

    void setup()
    {
        SPI_stub::int_value = 0;
        InterruptIn_stub::callback1 = NULL;
        InterruptIn_stub::callback2 = NULL;
        InterruptIn_stub::callback3 = NULL;
        InterruptIn_stub::callback4 = NULL;
        InterruptIn_stub::callback5 = NULL;
        InterruptIn_stub::callback6 = NULL;
        InterruptIn_stub::callback7 = NULL;

        unit = new SX1272_LoRaRadio(MBED_CONF_APP_LORA_SPI_MOSI,
                           MBED_CONF_APP_LORA_SPI_MISO,
                           MBED_CONF_APP_LORA_SPI_SCLK,
                           MBED_CONF_APP_LORA_CS,
                           MBED_CONF_APP_LORA_RESET,
                           MBED_CONF_APP_LORA_DIO0,
                           MBED_CONF_APP_LORA_DIO1,
                           MBED_CONF_APP_LORA_DIO2,
                           MBED_CONF_APP_LORA_DIO3,
                           MBED_CONF_APP_LORA_DIO4,
                           MBED_CONF_APP_LORA_DIO5,
                           MBED_CONF_APP_LORA_RF_SWITCH_CTL1,
                           MBED_CONF_APP_LORA_RF_SWITCH_CTL2,
                           MBED_CONF_APP_LORA_TXCTL,
                           MBED_CONF_APP_LORA_RXCTL,
                           MBED_CONF_APP_LORA_ANT_SWITCH,
                           MBED_CONF_APP_LORA_PWR_AMP_CTL,
                           MBED_CONF_APP_LORA_TCXO);


        events.tx_done = mbed::callback(&handle_tx_done);
        events.rx_done = mbed::callback(&handle_rx_done);
        events.rx_error = mbed::callback(&handle_rx_error);
        events.tx_timeout = mbed::callback(&handle_tx_timeout);
        events.rx_timeout = mbed::callback(&handle_rx_timeout);
    }

    void teardown()
    {
        delete unit;
        unit = NULL;
    }
};

TEST(sx1272_test, Create)
{
    CHECK(unit != NULL);
    delete unit;

    unit = new SX1272_LoRaRadio(MBED_CONF_APP_LORA_SPI_MOSI,
                                MBED_CONF_APP_LORA_SPI_MISO,
                                MBED_CONF_APP_LORA_SPI_SCLK,
                                MBED_CONF_APP_LORA_CS,
                                MBED_CONF_APP_LORA_RESET,
                                MBED_CONF_APP_LORA_DIO0,
                                MBED_CONF_APP_LORA_DIO1,
                                MBED_CONF_APP_LORA_DIO2,
                                MBED_CONF_APP_LORA_DIO3,
                                MBED_CONF_APP_LORA_DIO4,
                                MBED_CONF_APP_LORA_DIO5,
                                MBED_CONF_APP_LORA_RF_SWITCH_CTL1,
                                MBED_CONF_APP_LORA_RF_SWITCH_CTL2,
                                MBED_CONF_APP_LORA_TXCTL,
                                MBED_CONF_APP_LORA_RXCTL,
                                MBED_CONF_APP_LORA_ANT_SWITCH,
                                MBED_CONF_APP_LORA_PWR_AMP_CTL,
                                PinName(8));
}

TEST(sx1272_test, init_radio)
{
    unit->init_radio(NULL);
}

TEST(sx1272_test, radio_reset)
{
    unit->radio_reset();
}

TEST(sx1272_test, sleep)
{
    unit->sleep();
}

TEST(sx1272_test, standby)
{
    unit->standby();
}

TEST(sx1272_test, set_rx_config)
{
    unit->init_radio(&events);

    unit->set_rx_config(MODEM_FSK, 6500, 24, 6, 6500, 4, 30, true, 6, true, true, 5, true, true);

    unit->set_rx_config(MODEM_FSK, 6500, 24, 6, 6500, 4, 30, false, 6, true, true, 5, true, true);

    unit->set_rx_config(MODEM_LORA, 0, 24, 6, 5, 4, 30, true, 6, true, true, 5, true, true);

    unit->set_rx_config(MODEM_LORA, 0, 2, 6, 5, 4, 30, true, 6, true, true, 5, true, true);

    unit->set_rx_config(radio_modems_t(4), 0, 2, 6, 5, 4, 30, true, 6, true, true, 5, true, true);
}

TEST(sx1272_test, set_tx_config)
{
    unit->init_radio(&events);

    unit->set_tx_config(MODEM_FSK, 4800, 0, 0, 4800, 0, 5, false, false, 0, 0, 0, 3600);

    unit->set_tx_config(MODEM_LORA, 4800, 0, 0, 4800, 0, 5, false, false, false, 0, 0, 3600);

    unit->set_tx_config(MODEM_LORA, 4800, 2, 2, 4, 0, 5, false, false, true, 0, 0, 3600);
}

TEST(sx1272_test, send)
{
    unit->init_radio(&events);

    unit->set_tx_config(MODEM_FSK, 4800, 0, 0, 4800, 0, 5, false, false, 0, 0, 0, 3600);
    uint8_t buf[] = "test";
    unit->send(buf, 4);

    uint8_t buf2[] = "teststeststeststeststeststeststeststeststeststeststeststeststeststests";
    unit->set_tx_config(MODEM_FSK, 4800, 0, 0, 4800, 0, 5, true, false, 0, 0, 0, 3600);
    unit->send(buf2, 70);

    unit->set_tx_config(MODEM_LORA, 4800, 0, 0, 4800, 0, 5, false, false, 0, 0, 0, 3600);
    unit->send(buf, 4);

    unit->set_tx_config(MODEM_LORA, 4800, 0, 0, 4800, 0, 5, true, false, true, 0, true, 3600);
    unit->send(buf2, 70);
}

TEST(sx1272_test, receive)
{
    unit->init_radio(&events);

    unit->set_rx_config(MODEM_FSK, 6500, 24, 6, 6500, 4, 30, true, 6, true, true, 5, true, false);
    unit->receive(0);

    unit->set_rx_config(MODEM_FSK, 6500, 24, 6, 6500, 4, 30, false, 6, true, true, 5, true, false);
    unit->receive(60);

    unit->set_rx_config(MODEM_LORA, 0, 24, 6, 5, 4, 30, true, 6, true, true, 5, true, false);
    unit->receive(0);

    unit->set_rx_config(MODEM_LORA, 0, 2, 6, 5, 4, 30, true, 6, true, false, 5, false, false);
    unit->receive(60);

}

TEST(sx1272_test, set_channel)
{
    unit->init_radio(&events);

    unit->set_channel(4);
}

TEST(sx1272_test, random)
{
    uint32_t rand = unit->random();
    uint32_t rand2 = unit->random();
    CHECK(rand != rand2);
}

TEST(sx1272_test, get_status)
{
    unit->init_radio(NULL);
    uint8_t status = unit->get_status();
    CHECK_EQUAL(RF_IDLE, status);
}

TEST(sx1272_test, set_max_payload_length)
{
    unit->init_radio(&events);

    unit->set_max_payload_length(MODEM_FSK, 20);

    unit->set_max_payload_length(MODEM_LORA, 24);
}

TEST(sx1272_test, set_public_network)
{
    unit->init_radio(&events);

    unit->set_public_network(true);

    unit->set_public_network(false);
}

TEST(sx1272_test, time_on_air)
{
    unit->init_radio(&events);

    unit->time_on_air(MODEM_FSK, 20);

    unit->set_rx_config(MODEM_LORA, 0, 2, 6, 5, 4, 30, true, 6, true, false, 5, false, false);
    unit->time_on_air(MODEM_LORA, 20);

    unit->set_rx_config(MODEM_LORA, 1, 2, 6, 5, 4, 30, true, 6, true, false, 5, false, false);
    unit->time_on_air(MODEM_LORA, 20);

    unit->set_rx_config(MODEM_LORA, 2, 2, 6, 5, 4, 30, true, 6, true, false, 5, false, false);
    unit->time_on_air(MODEM_LORA, 20);
}

TEST(sx1272_test, perform_carrier_sense)
{
    unit->init_radio(&events);

    unit->perform_carrier_sense(MODEM_FSK, 8, -6, 60);

    unit->perform_carrier_sense(MODEM_LORA, 8, -166, 60);
}

TEST(sx1272_test, start_cad)
{
    unit->init_radio(&events);

    unit->start_cad();

    unit->set_rx_config(MODEM_LORA, 0, 2, 6, 5, 4, 30, true, 6, true, false, 5, false, false);

    unit->start_cad();
}

TEST(sx1272_test, check_rf_frequency)
{
    unit->check_rf_frequency(3);
}

TEST(sx1272_test, set_tx_continuous_wave)
{
    unit->set_tx_continuous_wave(5, 6, 7);
}

TEST(sx1272_test, lock)
{
    unit->lock();
}

TEST(sx1272_test, unlock)
{
    unit->unlock();
}

//TEST interrupts
TEST(sx1272_test, dio0)
{
    unit->init_radio(&events);

    if (InterruptIn_stub::callback1) {
        //Radio in IDLE state
        InterruptIn_stub::callback1();

        unit->set_rx_config(MODEM_FSK, 4800, 2, 6, 4800, 4, 30, true, 6, true, false, 5, false, false);
        unit->receive(60);
        InterruptIn_stub::callback1();

        unit->set_rx_config(MODEM_FSK, 4800, 2, 6, 4800, 4, 30, true, 6, true, false, 5, false, true);
        unit->receive(60);
        InterruptIn_stub::callback1();

        unit->set_rx_config(MODEM_FSK, 4800, 2, 6, 4800, 4, 30, true, 6, false, false, 5, false, false);
        unit->receive(60);
        InterruptIn_stub::callback1();

        unit->set_rx_config(MODEM_FSK, 4800, 2, 6, 4800, 4, 30, false, 6, false, false, 5, false, true);
        unit->receive(60);
        SPI_stub::int_value = 10;
        InterruptIn_stub::callback1();

        SPI_stub::int_value = 0x20; //error
        unit->set_rx_config(MODEM_LORA, 4, 2, 6, 8, 4, 30, true, 6, true, false, 5, false, false);
        unit->receive(60);
        InterruptIn_stub::callback1();

        unit->set_rx_config(MODEM_LORA, 4, 2, 6, 8, 4, 30, true, 6, true, false, 5, false, true);
        unit->receive(60);
        InterruptIn_stub::callback1();

        SPI_stub::int_value = 0x80;
        unit->set_rx_config(MODEM_LORA, 4, 2, 6, 8, 4, 30, true, 6, true, false, 5, false, false);
        unit->receive(60);
        InterruptIn_stub::callback1();

        SPI_stub::int_value = 10;
        unit->set_rx_config(MODEM_LORA, 4, 2, 6, 8, 4, 30, true, 6, true, false, 5, false, true);
        unit->receive(60);
        InterruptIn_stub::callback1();

        uint8_t buf[] = "test";
        unit->send(buf, 4);
        InterruptIn_stub::callback1();

        unit->set_rx_config(MODEM_FSK, 4800, 2, 6, 4800, 4, 30, false, 6, false, false, 5, false, true);
        unit->send(buf, 4);
        InterruptIn_stub::callback1();
    }
}

TEST(sx1272_test, dio1)
{
    unit->init_radio(&events);

    if (InterruptIn_stub::callback2) {
        //Radio in IDLE state
        InterruptIn_stub::callback2();

        unit->set_rx_config(MODEM_FSK, 4800, 2, 6, 4800, 4, 30, true, 6, true, false, 5, false, false);
        unit->receive(60);
        InterruptIn_stub::callback2();

        SPI_stub::int_value = -10;
        unit->set_rx_config(MODEM_FSK, 4800, 2, 6, 4800, 4, 30, false, 6, true, false, 5, false, false);
        unit->receive(60);
        InterruptIn_stub::callback2();

        SPI_stub::int_value = 10;
        unit->set_rx_config(MODEM_LORA, 4, 2, 6, 8, 4, 30, false, 6, true, false, 5, false, false);
        unit->receive(60);
        InterruptIn_stub::callback2();

        uint8_t buf[] = "test";
        unit->send(buf, 4);
        InterruptIn_stub::callback2();

        unit->set_rx_config(MODEM_FSK, 4800, 2, 6, 4800, 4, 30, false, 6, false, false, 5, false, true);
        unit->send(buf, 4);
        InterruptIn_stub::callback2();

        uint8_t buf2[] = "teststeststeststeststeststeststeststeststeststeststeststeststeststests";
        unit->set_rx_config(MODEM_FSK, 4800, 2, 6, 4800, 4, 30, false, 6, false, false, 5, false, true);
        unit->send(buf2, 70);
        InterruptIn_stub::callback2();
    }
}


