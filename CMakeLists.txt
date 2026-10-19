cmake_minimum_required(VERSION 3.10)
project(naive_agent LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(agent_core agent.cpp
mock_model.cpp)
target_compile_options(agent_core PRIVATE -Wall -Wextra -Wpedantic)

add_executable(naive_agent main.cpp)
target_link_libraries(naive_agent PRIVATE agent_core)
target_compile_options(naive_agent PRIVATE -Wall -Wextra -Wpedantic)