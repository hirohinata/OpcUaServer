cmake_minimum_required(VERSION 3.13)
project(OpcUaServer)

include_directories(
    ${PROJECT_SOURCE_DIR}
    )

set(SOURCE_FILES
    main.c
    stack/opcua.c
    stack/core/message/message.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})