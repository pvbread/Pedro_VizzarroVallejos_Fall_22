set(SOURCE_FILES
  	AbelianApp.cpp
   )

set(HEADER_FILES
	Abelian.h
	AbelianApp.h
	AbelianUtil.h
   )

add_library(Abelian SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DABELIAN_LIB)

target_precompile_headers(Abelian PRIVATE pch.h)

include_directories(../glwf/include)

target_link_libraries(Abelian glfw)