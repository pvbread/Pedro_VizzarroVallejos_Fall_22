add_executable(Archimedes Archimedes.cpp)

include_directories(../Abelian)

target_link_libraries(Archimedes Abelian)