add_executable(Archimedes Archimedes.cpp GameBoard.cpp Adversary.cpp)

include_directories(../Abelian ./)

target_link_libraries(Archimedes Abelian)