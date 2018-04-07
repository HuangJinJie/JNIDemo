#指定需要CMAKE的最小版本
cmake_minimum_required(VERSION 3.4.1)


#C 的编译选项是 CMAKE_C_FLAGS
# 指定编译参数，可选
#SET(CMAKE_CXX_FLAGS "-Wno-error=format-security -Wno-error=pointer-sign")

#设置生成的so动态库最后输出的路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})

#设置头文件搜索路径（和此txt同个路径的头文件无需设置），可选
#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/common)

#指定用到的系统库或者NDK库或者第三方库的搜索路径，可选。
#LINK_DIRECTORIES(/usr/local/lib)
#生成多个就继续写add_library，仿造下面的去写就ok
add_library(#生成的.so文件的名称，第一个.so
            one

            #Sets the library as a shared library.
            SHARED

            #提供的c++文件
            src/main/cpp/one.cpp )

add_library(#生成的.so文件的名称,第二个.so
            two

            #Sets the library as a shared library.
            SHARED

            #提供的c++文件
            src/main/cpp/two.cpp )

#添加子目录,将会调用子目录中的CMakeLists.txt
#ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/src/main/cpp/one)
#ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/src/main/cpp/two)


find_library( # Sets the name of the path variable.打印的.so文件
              log-lib
              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

target_link_libraries(#Specifies the target library.与log库绑定
                      one

                      #Links the target library to the log library
                      #included in the NDK.
                      ${log-lib} )
target_link_libraries(#Specifies the target library.与log库绑定
                      two

                      #Links the target library to the log library
                      #included in the NDK.
                      ${log-lib} )