#-----------------------------------------------------------------
# CMake file for the MRPT application:  holonomic-navigator-demo
#
#  Run with "cmake ." at the root directory
#-----------------------------------------------------------------
project(holonomic-navigator-demo)

mrpt_return_if_not_wxwidgets()

# ---------------------------------------------
# TARGET:
# ---------------------------------------------
set(SRCS
	holonomic_navigator_demoApp.cpp holonomic_navigator_demoApp.h
	holonomic_navigator_demoMain.cpp holonomic_navigator_demoMain.h
	../ReactiveNavigationDemo/DEFAULT_GRIDMAP_DATA.h
	MyGLCanvas.cpp MyGLCanvas.h
)

if(WIN32)
	set(SRCS ${SRCS} resource.rc)
endif()

# Define the executable target:
add_executable(${PROJECT_NAME} WIN32 ${SRCS} ${MRPT_VERSION_RC_FILE})

# Add the required libraries for linking:
target_link_libraries(${PROJECT_NAME}
	imp_wxwidgets
	mrptwxthings
	)

# Dependencies on MRPT libraries:
#  Just mention the top-level dependency, the rest will be detected automatically,
#  and all the needed #include<> dirs added (see the script DeclareAppDependencies.cmake for further details)
DeclareAppDependencies(${PROJECT_NAME} mrpt::nav mrpt::gui)

DeclareAppForInstall(${PROJECT_NAME})

AppStartMenuLink(${PROJECT_NAME} "Holonomic navigation simulator")   # Add link to the Start menu (in Windows Installable packages)
