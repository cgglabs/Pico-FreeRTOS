/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include <FreeRTOS.h>
#include <task.h>

#define LED_PIN 25

void vTaskExample(void *pvParameters) {
    // Initialize LED pin
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (1) {
        gpio_put(LED_PIN, 1);           // Turn LED on
        vTaskDelay(pdMS_TO_TICKS(500)); // On for 500ms
        gpio_put(LED_PIN, 0);           // Turn LED off
        vTaskDelay(pdMS_TO_TICKS(500)); // Off for 500ms
    }
}

int main() {
    // Initialize Pico SDK
    stdio_init_all();

    // Create task
    xTaskCreate(vTaskExample, "ExampleTask", 256, NULL, 1, NULL);

    // Start scheduler
    vTaskStartScheduler();

    // Should never reach here
    while (1);
}
