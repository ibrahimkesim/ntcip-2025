cmake_minimum_required(VERSION 3.6)
project(haberlesme_karti)

set(CMAKE_C_STANDARD 11)

set(CMAKE_LIBRARY_PATH "/opt/tdx-xwayland/5.7.6/sysroots/armv7at2hf-neon-tdx-linux-gnueabi/usr/lib")
set(CMAKE_USR_PATH "/opt/tdx-xwayland/5.7.6/sysroots/x86_64-tdxsdk-linux/usr")

if(LOG_LEVEL)
        if(${LOG_LEVEL} MATCHES 5)
                add_definitions(-DCMAKE_LOG_LEVEL=5)
        elseif(${LOG_LEVEL} MATCHES 4)
                add_definitions(-DCMAKE_LOG_LEVEL=4)
        elseif(${LOG_LEVEL} MATCHES 3)
                add_definitions(-DCMAKE_LOG_LEVEL=3)
        elseif(${LOG_LEVEL} MATCHES 2)
                add_definitions(-DCMAKE_LOG_LEVEL=2)
        elseif(${LOG_LEVEL} MATCHES 1)
                add_definitions(-DCMAKE_LOG_LEVEL=1)
        endif()
else()
        if(${LOG_LEVEL} MATCHES 0)
                add_definitions(-DCMAKE_LOG_LEVEL=0)
        else()
                add_definitions(-DCMAKE_LOG_LEVEL=4)
        endif()
endif()

set(LIBS "-L${CMAKE_LIBRARY_PATH} -lnetsnmpmibs -lnl-3 -ldl -lm -lnetsnmpagent -Wl,-E -lnetsnmp -lm")
set(CFLAGS "-I. -g -O2 -DNETSNMP_ENABLE_IPV6 -fno-strict-aliasing -DNETSNMP_REMOVE_U64 -g -O2 -Ulinux -Dlinux=linux -D_REENTRANT -D_GNU_SOURCE -DDEBIAN -fwrapv -fno-strict-aliasing -pipe -I{CMAKE_USR_PATH}/include -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -I{CMAKE_USR_PATH}/lib")

# Find SQLite3
find_package(SQLite3 REQUIRED)

add_executable(${PROJECT_NAME} src/main.c)
add_subdirectory(src/socket_handler)
add_subdirectory(src/snmp_handler)
add_subdirectory(src/quectel)


find_package(Threads REQUIRED)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC
        sqlite3
        Threads::Threads
        /opt/tdx-xwayland/5.7.6/sysroots/armv7at2hf-neon-tdx-linux-gnueabi/usr/lib/libnetsnmp.so
        /opt/tdx-xwayland/5.7.6/sysroots/armv7at2hf-neon-tdx-linux-gnueabi/usr/lib/libnetsnmpmibs.so
        /opt/tdx-xwayland/5.7.6/sysroots/armv7at2hf-neon-tdx-linux-gnueabi/usr/lib/libnetsnmpagent.so
        /opt/tdx-xwayland/5.7.6/sysroots/armv7at2hf-neon-tdx-linux-gnueabi/usr/lib/libnetsnmptrapd.so
        systemd
        SOCKET_HANDLER
        SNMP_HANDLER   
        QUECTEL
)
