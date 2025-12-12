cmake_minimum_required(VERSION 3.25)
project(Bankaccount)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bankaccount main.cpp bank.cpp chekin.cpp Saving.cpp )
