set(SOURCE_FILES
	Event.cpp
	OpenGLcode/OpenGLPicture.cpp
	OpenGLcode/OpenGLShader.cpp
	OpenGLcode/OpenGLRenderer.cpp
	Picture.cpp
	Shader.cpp
	Renderer.cpp
	Unit.cpp
  	AbelianApp.cpp
	AbelianWindow.cpp
	GLFWcode/GlFWimplementation.cpp
   )

set(HEADER_FILES
	Event.h
	Keys.h
	OpenGLcode/OpenGLPicture.h
	OpenGLcode/OpenGLShader.h
	OpenGLcode/OpenGLRenderer.h
	Picture.h
	Renderer.h
	PictureImplementation.h
	ShaderImplementation.h
	RendererImplementation.h
	Unit.h
	Abelian.h
	AbelianApp.h
	AbelianUtil.h
	AbelianWindow.h
	WindowImplementation.h
	GLFWcode/GLFWimplementation.h
   )

add_library(Abelian SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DABELIAN_LIB)

target_precompile_headers(Abelian PRIVATE pch.h)

include_directories(../glwf/include)
include_directories(../Abelian)
include_directories(../glad/include)
include_directories(../stbi)

target_link_libraries(Abelian glfw glad stbi)