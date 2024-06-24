

if (TARGET tinyusb_host)
    add_subdirectory(cobra_kb)
else ()
    message("Skipping TinyUSB host examples as TinyUSB is unavailable")
endif ()
