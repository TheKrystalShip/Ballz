cmake_minimum_required(VERSION 3.28)
project(ballz VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(SOURCES src/main.cpp
            src/Ball.cpp
            src/BallController.cpp
            src/BallRenderer.cpp
            src/BallGame.cpp
            src/Grid.cpp
)

add_executable(ballz ${SOURCES})

target_include_directories(ballz PUBLIC include ${TOASTER_INCLUDES} ${SDL2_ttf_INCLUDE_DIR} ${SDL2_mixer_INCLUDE_DIRS})
target_link_libraries(ballz toaster ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} SDL2_ttf::SDL2_ttf SDL2_ttf::SDL2_ttf SDL2_mixer::SDL2_mixer)

install(TARGETS ballz RUNTIME DESTINATION bin)

add_custom_command(TARGET ballz POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME      ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION   ${PROJECT_VERSION})
include(CPack)
