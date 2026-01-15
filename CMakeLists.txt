cmake_minimum_required(VERSION 3.15)
project(c__)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Tell CPR to use system curl
set(CPR_USE_SYSTEM_CURL ON CACHE BOOL "" FORCE)

# CPR library
FetchContent_Declare(
        cpr
        GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG c492b4fed1fd7288eacec6fe8d89e37df78d373a
)

# nlohmann/json library
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.3
)

# inih library (just source files)
FetchContent_Declare(
        inih
        GIT_REPOSITORY https://github.com/benhoyt/inih.git
        GIT_TAG r62
)

# D++ (Discord++) library
FetchContent_Declare(
        dpp
        GIT_REPOSITORY https://github.com/brainboxdotcc/DPP.git
        GIT_TAG v10.0.29
)

# Make libraries available
FetchContent_MakeAvailable(cpr json inih dpp)

# Add executable with ini.c included
add_executable(c__ main.cpp ${inih_SOURCE_DIR}/ini.c)

# Include inih headers
target_include_directories(c__ PRIVATE ${inih_SOURCE_DIR})

# Link CPR, JSON, and DPP
target_link_libraries(c__ PRIVATE
        cpr::cpr
        nlohmann_json::nlohmann_json
        dpp
)
