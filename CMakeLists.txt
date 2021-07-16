cmake_minimum_required(VERSION 2.8.3)
project(ros_watchdog)

## Find dependent packages
find_package(catkin REQUIRED COMPONENTS roscpp)

# Dependent of target 
catkin_package(CATKIN_DEPENDS roscpp)

# Include path of dependence
include_directories(${catkin_INCLUDE_DIRS})

# Target 
add_executable(${PROJECT_NAME}
  src/watchdog_node.cpp
)

# Add cmake target dependencies of the executable
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS} ${${PROJECT_NAME}_EXPORTED_TARGETS})

# Linkt to dependent libraries
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

# Install target
install(TARGETS ${PROJECT_NAME}
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch 
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
