project (GoProAPI_CPP)
cmake_minimum_required(VERSION 3.1)
cmake_policy(VERSION 3.1)

# Set where to find additional cmake modules, if any
# Comment out if not required
set(CMAKE_MODULE_PATH ${GoProAPI_CPP_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# Find and include Boost from its vendor directory
set(BOOST_ROOT ${GoProAPI_CPP_SOURCE_DIR}/vendor/boost)
set(BOOST_LIBRARYDIR ${GoProAPI_CPP_SOURCE_DIR}/vendor/boost/libs)
set(Boost_USE_STATIC_LIBS OFF)
add_definitions(-DBOOST_ALL_NO_LIB)

find_package(Boost REQUIRED COMPONENTS)
include_directories(${Boost_INCLUDE_DIRS})

# Find and include relevant ffmpeg packages
# find_package(FFmpeg COMPONENTS AVCODEC AVFORMAT AVUTIL AVDEVICE REQUIRED)
# include_directories(${FFMPEG_INCLUDE_DIRS})

# Set the base src directory as an include directory
include_directories(${GoProAPI_CPP_SOURCE_DIR}/src)

# Gather local project sources
file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE HDRS src/*.h)

# Create project executable
add_executable(GoProAPI_CPP ${SRCS} ${HDRS})

# Link in dependencies
# target_link_libraries(GoProAPI_CPP ${FFMPEG_LIBRARIES})

# Not sure if linking in Boost is necessary, since I am only using boost::beast, which is header only
# target_link_libraries(GoProAPI_CPP ${Boost_LIBRARIES})