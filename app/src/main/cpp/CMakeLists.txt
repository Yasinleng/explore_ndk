# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

cmake_minimum_required(VERSION 3.4.1)
#引入头文件
include_directories(include)

file(GLOB source *.cpp c/*.c)
add_library( # Sets the name of the library.
        native-lib
        SHARED
        ${source})


find_library( # Sets the name of the path variable.
        log-lib
        log)

target_link_libraries( # Specifies the target library.
        native-lib
        ${log-lib})