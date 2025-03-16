cmake_minimum_required(VERSION 3.13)


# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)
#include(pico_extras_import_optional.cmake)

project(cobra_usb_keyboard C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "2.1.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 2.1.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# If you want debug output from USB (pass -DPICO_STDIO_USB=1) this ensures you don't lose any debug output while USB is set up
if (NOT DEFINED PICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS)
    set(PICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS 3000)
endif()

# Initialize the SDK
pico_sdk_init()

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        )
if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wno-maybe-uninitialized)
endif()


#set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
#set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")

add_executable(cobra_usb_keyboard)

# Example source
target_sources(cobra_usb_keyboard PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/hid_app.c
        ${CMAKE_CURRENT_LIST_DIR}/main.c
        ${CMAKE_CURRENT_LIST_DIR}/msc_app.c
        ${CMAKE_CURRENT_LIST_DIR}/cdc_app.c
        ${CMAKE_CURRENT_LIST_DIR}/cobra_kb.c
        )

target_compile_definitions(cobra_usb_keyboard PRIVATE
       PICO_DEFAULT_UART=0
       PICO_DEFAULT_UART_TX_PIN=16
       PICO_DEFAULT_UART_RX_PIN=17
     )

# Make sure TinyUSB can find tusb_config.h
target_include_directories(cobra_usb_keyboard PUBLIC      ${CMAKE_CURRENT_LIST_DIR})

# In addition to pico_stdlib required for common PicoSDK functionality, add dependency on tinyusb_host
# for TinyUSB device support and tinyusb_board for the additional board support library used by the example
target_link_libraries(
        cobra_usb_keyboard
        PUBLIC
        pico_stdlib
        tinyusb_host
        tinyusb_board
        pico_multicore
#        pico_unique_id
        )
pico_enable_stdio_usb(cobra_usb_keyboard 0)
pico_enable_stdio_uart(cobra_usb_keyboard 1)
pico_add_extra_outputs(cobra_usb_keyboard)

# add url via pico_set_program_url
#example_auto_set_url(cobra_usb_keyboard)


set(FAMILY rp2040)
set(BOARD pico_sdk)
set(TINYUSB_FAMILY_PROJECT_NAME_PREFIX "tinyusb_host_cobra_")

