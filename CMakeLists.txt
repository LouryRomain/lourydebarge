cmake_minimum_required (VERSION 3.5)
project (plt)

# Directories
include_directories ("${PROJECT_SOURCE_DIR}/src")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Enable C++11
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF(CMAKE_COMPILER_IS_GNUCC)
	SET(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -Wall -std=c11   -pthread -g")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -pthread -g")
ENDIF(CMAKE_COMPILER_IS_GNUCC)


# Generate headers
set(DIA2CODE "${PROJECT_SOURCE_DIR}/dia2code/bin/dia2code")
exec_program(${DIA2CODE} ARGS -d ../src -t cpp -cl State,Fifo,Command,Choice,Node,MinMax,Attack,Defence,Engine,IA,Card,Static,Record,Move_unit,TYPE_VIEW,Render,Clickable,STATE,TYPE,VIEW,STATE_CLICKABLE,ListTerritory,Clavier,ListElement,Souris,Bouton_ok,Animation,Animated,Territory,Player,Element,Window,View,Gang,Tile,Textures  ../src/state.dia)

# Sources
file(GLOB_RECURSE main_sources src/*.cpp)



# jsoncpp
include_directories ("${PROJECT_SOURCE_DIR}/extern/jsoncpp-0.10.5/dist")
file(GLOB jsoncpp_sources "${PROJECT_SOURCE_DIR}/extern/jsoncpp-0.10.5/dist/jsoncpp.cpp")

# Executables
add_executable(run ${main_sources} ${jsoncpp_sources})

# SFML
if(WIN32)
set(SFML_ROOT "D:/Utils/SFML-2.3")
set(CMAKE_MODULE_PATH "${SFML_ROOT}/cmake/Modules" ${CMAKE_MODULE_PATH})
else(WIN32)
SET(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
endif(WIN32)
find_package(SFML 2 COMPONENTS graphics window system network)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(run ${SFML_LIBRARIES})
endif()

