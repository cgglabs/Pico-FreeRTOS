# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(main C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add FreeRTOS as a library
add_library(freertos
    FreeRTOS/Source/croutine.c
    FreeRTOS/Source/event_groups.c
    FreeRTOS/Source/list.c
    FreeRTOS/Source/queue.c
    FreeRTOS/Source/stream_buffer.c
    FreeRTOS/Source/tasks.c
    FreeRTOS/Source/timers.c
    FreeRTOS/Source/portable/GCC/ARM_CM0/port.c
    FreeRTOS/Source/portable/GCC/ARM_CM0/portasm.c
    FreeRTOS/Source/portable/GCC/ARM_CM0/mpu_wrappers_v2_asm.c
    FreeRTOS/Source/portable/MemMang/heap_4.c
)

# Include FreeRTOS headers
target_include_directories(freertos PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/FreeRTOS/include
    ${CMAKE_CURRENT_LIST_DIR}/FreeRTOS/Source/portable/GCC/ARM_CM0
    ${CMAKE_CURRENT_LIST_DIR}/FreeRTOS
)

add_executable(main
    main.c
    )

# pull in common dependencies
target_link_libraries(main pico_stdlib freertos)

# create map/bin/hex file etc.
pico_add_extra_outputs(main)

# add url via pico_set_program_url
