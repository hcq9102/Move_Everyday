cmake_minimum_required(VERSION 3.2) #set the VERSION
project(hello) # 指定项目名字

#最后想要调试，所以在cmake里设置为debug模式
set(CMAKE_BUILD_TYPE DEBUG) # 不用debug时，换成release版本

add_executable(hello  main.cpp) #generate an excutable program,把所用到的文件或者库都写进去，生成一个可执行文件

#在terminal 新建一个build， 去cmake一下
#make -j3


