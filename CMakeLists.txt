
cmake_minimum_required(VERSION 3.16.3)

project(qt3dExample VERSION 1.0.0 LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# /home/robert/Qt/5.15.2/gcc_64/lib/cmake
set(Qt5_DIR         "/home/robert/Qt/5.15.2/gcc_64/lib/cmake/Qt5" CACHE PATH "Qt5 Root directory")
set(Qt5Core_DIR     "/home/robert/Qt/5.15.2/gcc_64/lib/cmake/Qt5Core" CACHE PATH "Qt5 Core directory")
set(Qt5Widgets_DIR  "/home/robert/Qt/5.15.2/gcc_64/lib/cmake/Qt5Widgets" CACHE PATH "Qt5 Widgets directory")
set(Qt5UiTools_DIR  "/home/robert/Qt/5.15.2/gcc_64/lib/cmake/Qt5UiTools" CACHE PATH "Qt5 UiTools directory")
set(Qt5Sql_DIR      "/home/robert/Qt/5.15.2/gcc_64/lib/cmake/Qt5Sql" CACHE PATH "Qt5 Sql directory")
set(Qt5Xml_DIR      "/home/robert/Qt/5.15.2/gcc_64/lib/cmake/Qt5Xml" CACHE PATH "Qt5 Xml directory")
set(Qt53DExtras_DIR "/home/robert/Qt/5.15.2/gcc_64/lib/cmake/Qt53DExtras" CACHE PATH "Qt5 3D Extras directory")
set(Qt53DCore_DIR   "/home/robert/Qt/5.15.2/gcc_64/lib/cmake/Qt53DCore" CACHE PATH "Qt5 3D Core directory")
set(Qt53DRender_DIR "/home/robert/Qt/5.15.2/gcc_64/lib/cmake/Qt53DRender" CACHE PATH "Qt5 3D Render directory")
set(Qt53DInput_DIR  "/home/robert/Qt/5.15.2/gcc_64/lib/cmake/Qt53DInput" CACHE PATH "Qt5 3D Input directory")


find_package(Qt5Core     REQUIRED CONFIG)
find_package(Qt5Widgets  REQUIRED CONFIG)
find_package(Qt5UiTools  REQUIRED CONFIG)
find_package(Qt5Sql      REQUIRED CONFIG)
find_package(Qt5Xml      REQUIRED CONFIG)
find_package(Qt53DExtras REQUIRED CONFIG)
find_package(Qt53DCore   REQUIRED CONFIG)
find_package(Qt53DRender REQUIRED CONFIG)
find_package(Qt53DInput  REQUIRED CONFIG)


# find_package(Qt5Widgets REQUIRED)
# find_package(Qt5Core REQUIRED)
# # find_package(Qt53D REQUIRED)

# find_package(Qt53DCore REQUIRED)

# find_package(Qt5 REQUIRED COMPONENTS 
#              Core
#              Gui
#              Widgets
#              3DCore
#              3DExtras
#              3DRender
#              3DInput)

# find_package(Qt5OpenGL REQUIRED)
# find_package(OpenGL REQUIRED)
# find_package(GLUT REQUIRED)




# Find includes in corresponding build directories.
# set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_AUTOUIC ON)

# Instruct Cmake to run automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


# message(INFO ">>> ${Qt5Widgets_INCLUDES}")


set(_INCLUDE_DIRS
    # GL
    # /usr/include
    # Qt5
    # ${Qt5Widgets_INCLUDES}
    # local
    ${CMAKE_CURRENT_LIST_DIR}/include)

include_directories(${_INCLUDE_DIRS}
                    # ${PROJECT_SOURCE_DIR}
                    ${PROJECT_BINARY_DIR}
                    ${CMAKE_CURRENT_LIST_DIR}/include
                    # ${OPENGL_INCLUDE_DIRS} 
                    # ${GLUT_INCLUDE_DIRS})
)

set(_UI
)

set(_HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/include/MyOpenGLWidget.h
    # ${CMAKE_CURRENT_LIST_DIR}/include/MyGraphicsScene.h
    ${CMAKE_CURRENT_LIST_DIR}/include/MyOrbitTransformController.h
)

set(_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/MyOpenGLWidget.cpp
    # ${CMAKE_CURRENT_LIST_DIR}/src/MyGraphicsScene.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/MyOrbitTransformController.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
)

qt5_wrap_cpp(qt3dExample_header_moc ${_HEADERS})
qt5_wrap_ui(qt3dExample_ui_moc ${_UI})

add_executable(qt3dExample
    ${qt3dExample_header_moc}
    ${qt3dExample_ui_moc}
    ${_SOURCES}
)

target_link_libraries(qt3dExample 
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::3DCore
    Qt5::3DExtras
    Qt5::3DRender
    Qt5::3DInput
    Qt5::UiTools
    stdc++
    glut
    GLU
    GL
    ssl
    pthread
)


# target_include_directories(shield.ai PUBLIC ${_INCLUDE_DIRS})
# target_link_libraries(shield.ai 
    # dl
    # nsl
    # m
    # rt
    # pthread
    # ssl
    # stdc++
    # glut
    # GLU
    # GL
    # Qt5::OpenGL
    # ${OPENGL_LIBRARY}
    # ${GLUT_LIBRARY}
    # ${Qt5Widgets_LIBRARIES}
    # Qt5::Core
    # Qt5::Gui
    # Qt5::Widgets)
# )


# if (CMAKE_TESTING_ENABLED)
#     add_subdirectory(test)
# endif()
