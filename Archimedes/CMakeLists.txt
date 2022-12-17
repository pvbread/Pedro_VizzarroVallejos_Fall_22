add_executable(Archimedes Archimedes.cpp GameBoard.cpp)

include_directories(../Abelian ./)

target_link_libraries(Archimedes Abelian)