#Minimum version required for CMake
cmake_minimum_required (VERSION 2.6)
 
#Name of the project
project (ThalesAlenia)
 
#Compile in Debug Mode. Allows to make debug.
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb")
SET(CMAKE_BUILD_TYPE "debugfull" )
 
#Set a variable with the directory path.
SET(OOM_TRUNK_DIR ${CMAKE_CURRENT_SOURCE_DIR})
 
#Set a variable with the path of the application.
SET(EXECUTABLE_OUTPUT_PATH ${OOM_TRUNK_DIR}/bin)
 
#In Linux and Mac OS/X the Path is /usr/include/ooml
INCLUDE_DIRECTORIES("/usr/include/ooml")
 
#Set a variable with the name of the cpp source files of your application
SET(TOPEFEE_FILES topefee.cpp)
SET(RUEDAMOTOR_FILES ruedamotor.cpp)

#Set a variable with the name of your application
SET(TOPEFEE_NAME topefee)
 SET(RUEDAMOTOR_NAME ruedamotor	)

#Create and link the executable
ADD_EXECUTABLE(${TOPEFEE_NAME} ${TOPEFEE_FILES})
ADD_EXECUTABLE(${RUEDAMOTOR_NAME} ${RUEDAMOTOR_FILES})

TARGET_LINK_LIBRARIES(${TOPEFEE_NAME} OOMLCore OOMLComponents OOMLParts)
TARGET_LINK_LIBRARIES(${RUEDAMOTOR_NAME} OOMLCore OOMLComponents OOMLParts)
