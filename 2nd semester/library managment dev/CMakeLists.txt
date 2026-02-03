cmake_minimum_required(VERSION 3.25)
project(Library_Management)

set(CMAKE_CXX_STANDARD 17)

add_executable(Library_Management main.cpp Librarian.cpp Librarian.h Binary.cpp Binary.h)
