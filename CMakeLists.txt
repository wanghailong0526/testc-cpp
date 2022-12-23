cmake_minimum_required(VERSION 3.21)
project(testc_cpp)

set(CMAKE_CXX_STANDARD 17)
#开启 C++异常 mac不可用
#set_target_properties(target PROPERTIES COMPILE_FLAGS "/EHsc")
#开启异常, with SEH exceptions mac不可用
#set_target_properties(target PROPERTIES COMPILE_FLAGS "/EHa")
#开启异常, with extern C functions mac不可用
#set_target_properties(target PROPERTIES COMPILE_FLAGS "/EHs")
#cmake 2.8.12+ mac不可用
#add_compile_options(/EHs)
#开启C++异常
#set(CMAKE_CXX_FLAGS "-fexceptions")

add_executable(testc_cpp testc/testpthread/testpthreadcondition.c)
