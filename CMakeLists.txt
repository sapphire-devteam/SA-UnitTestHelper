# Copyright (c) 2021 Sapphire Development Team. All Rights Reserved.

cmake_minimum_required(VERSION 3.16)


# Create Cmake project.
project(SA-UnitTestHelper)


# === Input ===

# Add interface library target.
add_library(SA-UnitTestHelper INTERFACE)

# Add SA-UnitTestHelper.hpp include directory.
target_include_directories(SA-UnitTestHelper INTERFACE .)


# === Option ===

option(SA_UTH_EXAMPLES "Build SA-UnitTestHelper examples" OFF)

if(SA_UTH_EXAMPLES)
	# Setup output directories for project.
	set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/Build/${CMAKE_BUILD_TYPE}_${CMAKE_HOST_SYSTEM_PROCESSOR})
	message("Output Directory: ${CMAKE_BINARY_DIR}")

	# Enable testing for this directory and below.
	enable_testing()

	# Add entries.
	add_subdirectory(Examples)
endif()