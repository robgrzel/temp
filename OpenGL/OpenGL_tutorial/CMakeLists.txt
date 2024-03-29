cmake_minimum_required(VERSION 3.6)
project(OpenGL_tutorial)

set(CMAKE_CXX_STANDARD 11)
INCLUDE(FindPkgConfig)

set(ROOTSYS
        /opt/CERN/ROOT/root-6.08.06
        )

set(do.OpenGl_Plot2d 0)
set(do.OpenGl_Simple_Damage 0)
set(do.OpenGl_Simple 1)
set(do.OpenGl_Simple_Curve 0)
set(do.OpenGl_OOF 0)
set(do.OpenGl_Window 0)

set(n 0)


if (do.OpenGl_Simple_Curve)

    set(SOURCE_FILES
            OpenGl_Simple/opengl_glut_fltk_curve.cpp
            )

endif (do.OpenGl_Simple_Curve)


if (do.OpenGl_Plot2d)

    set(SOURCE_FILES
            OpenGl_Plot2d/OpenGl_Plot2d_00${n}.cpp
            #OpenGl_Plot2d/OpenGl_Plot2d_00${n}.h
            OpenGl_Plot2d/shader_utils.cpp
            OpenGl_Plot2d/shader_utils.h
            OpenGl_Plot2d/res_texture.c
            OpenGl_Plot2d/graph00${n}.v.glsl
            OpenGl_Plot2d/graph00${n}.f.glsl
            )

endif (do.OpenGl_Plot2d)

if (do.OpenGl_Window)

    set(SOURCE_FILES
            FLTK_OpenGl_events/main.cpp
            FLTK_OpenGl_events/MyGLWindow.h
            FLTK_OpenGl_events/MyGLWindow.cpp
            )

endif (do.OpenGl_Window)


if (do.OpenGl_Simple_Damage)

    set(SOURCE_FILES
            OpenGl_Simple/opengl_redraw_part_by_damage.cpp)

endif (do.OpenGl_Simple_Damage)


if (do.OpenGl_Simple)

    set(SOURCE_FILES
            OpenGl_Simple/opengl_simple.cpp)

endif (do.OpenGl_Simple)

if (do.OpenGl_OOF)
    set(SOURCE_FILES
            GLUT-Object-Oriented-Framework/main.cpp
            GLUT-Object-Oriented-Framework/GlutFramework.h
            GLUT-Object-Oriented-Framework/GlutFramework.cpp
            GLUT-Object-Oriented-Framework/Keyboard.h
            GLUT-Object-Oriented-Framework/Keyboard.cpp
            GLUT-Object-Oriented-Framework/PerformanceTimer.h
            GLUT-Object-Oriented-Framework/PerformanceTimer.cpp
            GLUT-Object-Oriented-Framework/Point.h
            GLUT-Object-Oriented-Framework/Vector.h
            )
endif (do.OpenGl_OOF)

option(enable-mpi ON)
option(enable-pthr-widget ON)
option(MGL_HAVE_PTHREAD ON)

#find_package(ROOT REQUIRED COMPONENTS RIO Net)

message("USE QT5...")
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui PrintSupport)
#qt5_use_modules(${PROJECT_NAME} Core Widgets Gui)

find_package(OpenMP REQUIRED)
find_package(FLTK REQUIRED)
find_package(Threads REQUIRED)

#########################################################
# FIND SDL2
#########################################################
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR})
link_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR})
#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if (NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif (NOT GLUT_FOUND)
link_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR})
#########################################################
# FIND GLEW
#########################################################
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_directories(${GLEW_LIBRARY_DIRS})
add_definitions(${GLEW_DEFINITIONS})
if (NOT GLEW_FOUND)
    message(ERROR " GLEW not found!")
endif (NOT GLEW_FOUND)
#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if (NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif (NOT OPENGL_FOUND)

include_directories(/usr/include/FL)

if (THREADS_HAVE_PTHREAD_ARG)
    target_compile_options(PUBLIC ${PROJECT_NAME} "-pthread")
endif ()

if (1)
    include_directories(/usr/include/openmpi)
    SET(CMAKE_C_COMPILER /usr/bin/mpicc.openmpi)
    SET(CMAKE_CXX_COMPILER /usr/bin/mpicxx.openmpi)
elseif (MPI_FOUND)
    find_package(MPI REQUIRED)
    include_directories(/usr/include/mpich)
    SET(CMAKE_C_COMPILER /usr/bin/mpicc.mpich)
    SET(CMAKE_CXX_COMPILER /usr/bin/mpicxx.mpich)
endif (1)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

message("LINK QT5...")
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Gui Qt5::PrintSupport qcustomplot)

message("LINK MATHGL...")
target_link_libraries(${PROJECT_NAME} mgl-mpi mgl-qt mgl-glut mgl-fltk mgl m ssl rt crypto)

if (1)
    message("LINK OpenMPI...")
    target_link_libraries(${PROJECT_NAME} /usr/lib/openmpi/lib/libmpi.so)
elseif (MPI_FOUND)
    message("LINK MPICH...")
    target_link_libraries(${PROJECT_NAME} /usr/lib/mpich/lib/libmpich.so)
endif (1)

if (CMAKE_THREAD_LIBS_INIT)
    target_link_libraries(${PROJECT_NAME} "${CMAKE_THREAD_LIBS_INIT}")
endif ()

message("LINK FLTK...")
target_link_libraries(${PROJECT_NAME} fltk fltk_gl)
message("LINK OPENGL...")
find_library(GLEW_LIBRARY NAMES GLEW glew32 glew glew32s PATH_SUFFIXES lib64)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLUT_LIBRARIES})
message("LINK SDL2...")
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

#target_link_libraries(
#        ${PROJECT_NAME}
#        -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree
#        -lRint -lPostscript -lMatrix -lPhysics
#        -lMathCore -lThread -pthread -lm -ldl -rdynamic)

# Add a test:
#enable_testing()
#add_test(${PROJECT_NAME} ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME})

