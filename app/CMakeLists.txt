#最低的cmake版本
cmake_minimum_required(VERSION 3.4.1)

#需要生成的库和使用的库
add_library( native-lib
             SHARED
             src/main/cpp/native-lib.cpp )




#添加一个需要依赖的第三方库
#add_library(nn SHARED IMPORTED)

#set_target_properties(nn
#                      PROPERTIES IMPORTED_LOCATION
#                      ${CMAKE_SOURCE_DIR}/src/main/jni/${ANDROID_ABI}/lib/libnn.so
#                      )


#引入需要依赖的本地库
find_library( log-lib
              log )


# 对用到的库做一个依赖
target_link_libraries( native-lib
                       ${log-lib} )