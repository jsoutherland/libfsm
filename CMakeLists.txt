cmake_minimum_required(VERSION 2.6)
project(STATE_MACHINE)

if(CMAKE_COMPILER_IS_GNUCXX)
	add_definitions(-std=gnu++0x)
endif()


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin )

include_directories($(STATE_MACHINE_SRC_DIR)/include)

set(FSM_SRCS src/StateMachine.cpp src/State.cpp src/StateTransition.cpp)

add_executable(fsm_demo demo/demo.cpp)

add_library(fsm STATIC ${FSM_SRCS})

target_link_libraries(fsm_demo fsm)
