cmake_minimum_required(VERSION 3.13)
project(test)

IF (WIN32)
    MESSAGE(STATUS "Now is windows")
    set(ESP32_SRC_PATH "C:/Users/Administrator/Documents/Arduino/hardware/espressif/esp32/")
ELSEIF (APPLE)
    MESSAGE(STATUS "Now is Apple systens.")
    set(ESP32_SRC_PATH "/Users/kaylor/Library/Arduino15/packages/esp32/hardware/esp32/1.0.1/")
ELSEIF (UNIX)
    MESSAGE(STATUS "Now is UNIX-like OS's. Including aPPLE os x  and CygWin")
ENDIF ()

set(CMAKE_CXX_STANDARD 14)
message("ESP32 PATH: " ${ESP32_SRC_PATH})
set(COMPONENT_ADD_INCLUDEDIRS
        variants/esp32/
        cores/esp32/
        libraries/ArduinoOTA/src
        libraries/AsyncUDP/src
        libraries/AzureIoT/src
        libraries/BLE/src
        libraries/BluetoothSerial/src
        libraries/DNSServer/src
        libraries/EEPROM/src
        libraries/ESP32/src
        libraries/ESPmDNS/src
        libraries/FFat/src
        libraries/FS/src
        libraries/HTTPClient/src
        libraries/HTTPUpdate/src
        libraries/NetBIOS/src
        libraries/Preferences/src
        libraries/SD_MMC/src
        libraries/SD/src
        libraries/SimpleBLE/src
        libraries/SPIFFS/src
        libraries/SPI/src
        libraries/Ticker/src
        libraries/Update/src
        libraries/WebServer/src
        libraries/WiFiClientSecure/src
        libraries/WiFi/src
        libraries/Wire/src
        )
foreach(var ${COMPONENT_ADD_INCLUDEDIRS})
#    message(${ESP32_SRC_PATH}${var})
    include_directories(${ESP32_SRC_PATH}${var})
endforeach()
add_executable(test test.cpp)