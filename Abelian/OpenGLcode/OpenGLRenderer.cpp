#include "pch.h"
#include "OpenGLRenderer.h"
#include "glad/glad.h"
#include "AbelianWindow.h"
#include "Picture.h"
#include "Shader.h"

namespace Abelian
{
    OpenGLRenderer::OpenGLRenderer()
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    void OpenGLRenderer::Draw(Picture& picture, int x, int y, int z, Shader& shader)
	{
        float vertices[] = {
            // positions      // texture coords
             (float)x, (float)y, (float)z, 0.0f, 0.0f, // bottem left
             (float)(x+picture.GetWidth()), (float)y, (float)z, 1.0f, 0.0f, // bottom right
             (float)x, (float)(y+picture.GetHeight()), (float)z, 0.0f, 1.0f, // top left
             (float)(x + picture.GetWidth()), (float)(y + picture.GetHeight()), (float)x, 1.0f, 1.0f  // top right
        };
        unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
        };
        unsigned int VBO, VAO, EBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

		picture.Activate();
		shader.Activate();

        int width{ AbelianWindow::GetWindow()->GetWidth()};
        int height{ AbelianWindow::GetWindow()->GetWidth()};
        shader.ProvideFloatValues("screenSize", {(float)width, (float)height});

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

   
   
    void OpenGLRenderer::Clear()
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
    }
}
