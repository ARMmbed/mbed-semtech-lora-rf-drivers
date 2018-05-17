/*
 * Copyright (c) 2018, Arm Limited and affiliates.
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

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestPlugin.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTestExt/MockSupportPlugin.h"

//#define MBED_CONF_LORA_DEVICE_EUI      { 0x6A, 0x54, 0x05, 0x45, 0xD6, 0xFF, 0xBD, 0xB0 }
//#define MBED_CONF_LORA_APPLICATION_EUI { 0xE3, 0xDB, 0x7F, 0x2D, 0x75, 0x9D, 0x1C, 0x91 }
//#define MBED_CONF_LORA_APPLICATION_KEY { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

IMPORT_TEST_GROUP(sx1272_test);

