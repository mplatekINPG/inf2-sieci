cmake_minimum_required(VERSION 2.8)
project( siec )

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
	main.cpp	
	factory.h factory.cpp
	Queue.h Queue.cpp
	Siec.h Siec.cpp
)


add_executable( siec ${SOURCES} )
target_link_libraries( siec )

