cmake_minimum_required(VERSION 3.26)
project(projet_allegro C)

set(CMAKE_C_STANDARD 11)
set(WIN32 FALSE)  # Indiquer que ce n'est pas une application Windows

add_executable(projet_allegro main.c personage.c)
target_link_libraries(projet_allegro -lmingw32 -lalleg44)


