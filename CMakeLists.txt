cmake_minimum_required(VERSION 3.19)
project(tarea_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

set(GCC_COVERAGE_COMPILE_FLAGS "-I/usr/include/python3.9 -lpython3.9")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

find_package(Python3 COMPONENTS Interpreter NumPy REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
find_path(MATPLOTLIB_CPP_INCLUDE_DIRS "matplotlibcpp.h")


add_executable(${PROJECT_NAME} main.cpp
        HammingCode/Hamming.cpp HammingCode/Hamming.h
        Conversiones/Conversiones.cpp Conversiones/Conversiones.h
        Gráfico/GraficoNRZI.h Interfaz/mainwindow.h Interfaz/mainwindow.cpp)

target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
target_link_libraries(tarea_1 ${PYTHON_LIBRARIES} Python3::NumPy)
target_include_directories(tarea_1 PRIVATE ${MATPLOTLIB_CPP_INCLUDE_DIRS})
