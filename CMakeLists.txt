cmake_minimum_required(VERSION 3.20)

# Project configuration
project(Project LANGUAGES C CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Sources
add_executable(Project
    Main.cpp
    glad.c
)

# Include directories (project headers + third-party headers)
target_include_directories(Project PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/Librarys/include
)

# Link directories for prebuilt third-party libs
if (MSVC)
    target_link_directories(Project PRIVATE ${CMAKE_SOURCE_DIR}/Librarys/lib)
endif()

# Link against GLFW and OpenGL on Windows, plus system libs typically required by static GLFW
if (WIN32)
    target_link_libraries(Project PRIVATE
        glfw3
        opengl32
        user32
        gdi32
        shell32
        ole32
        oleaut32
        advapi32
        comdlg32
        winmm
        imm32
        version
    )
endif()

