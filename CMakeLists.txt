cmake_minimum_required(VERSION 3.13)  # CMake version check
project(simple_example)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp room/CinemaRoom.cpp room/CinemaRoom.h room/RoomDescription.cpp room/RoomDescription.h
        room/Seat.cpp room/Seat.h movie/Movie.h seance/Description.h movie/MovieDescription.cpp movie/MovieDescription.h
        movie/Movie.cpp room/Room.cpp room/Room.h seance/Seance.cpp seance/Seance.h room/RoomFactory.h
        room/CinemaRoomFactory.h room/CinemaRoomFactory.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(simple_example ${SOURCE_FILES})