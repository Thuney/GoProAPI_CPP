project (GoProAPI_CPP)
cmake_minimum_required(VERSION 3.1)
cmake_policy(VERSION 3.1)

include_directories(${GoProAPI_CPP_SOURCE_DIR}/src)

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE HDRS src/*.h)

add_executable(GoProAPI_CPP ${SRCS} ${HDRS})


#Commented configuration for other libraries. Does not work currently

#include_directories(${PROJECT_SOURCE_DIR}/vendor/ffmpeg)
#add_library(
#	ffmpeg
#	${PROJECT_SOURCE_DIR}/vendor/ffmpeg/fftools/ffmpeg.h
#)

#set_target_properties(ffmpeg PROPERTIES LINKER_LANGUAGE C)



#add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/boost_beast ${PROJECT_SOURCE_DIR}/vendor/boost_beast/build EXCLUDE_FROM_ALL)

##target_link_libraries(GoProAPI_CPP Beast)
#target_link_libraries(GoProAPI_CPP ffmpeg)