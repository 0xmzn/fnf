cmake_minimum_required(VERSION 3.20)
project(sfml)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug
            CACHE STRING
            "Choose the type of build (Debug or Release)"
            FORCE
            )
endif()

find_package(SFML 2.5
        COMPONENTS
        system window graphics network audio REQUIRED
        )

add_executable(sfmlapp
        main.cpp)

target_link_libraries(sfmlapp sfml-graphics)
