cmake_minimum_required(VERSION 3.15)

project(PuzzleRoom)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

set(SOURCE_FILES
    src/gameObject.cpp
    src/inventoryObject.cpp
    src/door.cpp
    src/inventory.cpp
    src/player.cpp
    src/room.cpp
    src/gameTerminal.cpp
    src/puzzle.cpp
    src/keypadPuzzle.cpp
    src/lockedObject.cpp
    src/lockedDoor.cpp
)

set(TEST_FILES
    test/testObjects.cpp
    test/testInventory.cpp
    test/testRoom.cpp
    test/testPlayer.cpp
    test/testDoor.cpp
    test/testInventoryObject.cpp
    test/testPuzzle.cpp
    test/testKeyPad.cpp
    test/testLockedObjects.cpp
    test/testLockedDoor.cpp
    test/testGameTerminal.cpp
)

add_executable(runAllTests
    ${TEST_FILES}
    ${SOURCE_FILES}
)

add_executable(PuzzleRoom
    src/main.cpp
    ${SOURCE_FILES}
)

install(TARGETS PuzzleRoom RUNTIME DESTINATION bin)
include(CPack)

# Creates packaged executable form of project 
install(TARGETS PuzzleRoom RUNTIME DESTINATION bin)
include(CPack)
#

target_link_libraries(runAllTests gtest gtest_main)
