#define _USE_MATH_DEFINES                                                                                  
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Util.h"
#include <math.h>
#include <vector>

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "Square.h"   //Samuel
#include "Triangle.h" //Andiko
#include "Pentagon.h"  //
#include "Circle.h"  //Jessica
#include "Octagon.h" //Dustin
#include "Trapezoid.h" //Yunisa

float scale = 0.01;


int main(int key, int scancode, int action, int mods) //main program                                        
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1100, 720, "UAS KGV Williams-C", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum err = glewInit();

    Square s1; //aspal
    s1.setTranslation(0.0f, -0.5f, 0.0f);
    s1.setScale(glm::vec3(1.0f, -0.30f, 1.0f));
    s1.setColor(glm::vec4(0.15f, 0.15f, 0.15f, 1.0f));

    Pentagon p1; // pintu depan
    p1.setTranslation(-0.6f, -0.3f, 0.0f);
    p1.setScale(glm::vec3(0.155f, 0.2f, 1.0f));
    p1.setColor(glm::vec4(0.545f, 0.0f, 0.0f, 1.0f));

    Square s2; // kaca truk
    s2.setTranslation(glm::vec3(-0.56f, -0.2f, 0.0f));
    s2.setScale(glm::vec3(0.09f, 0.08f, 1.0f));
    s2.setColor(glm::vec4(0.50f, 0.50f, 0.50f, 1.0f));

    Triangle t3; //kaca truk
    t3.setTranslation(-0.65f, -0.2f, 0.0f);
    t3.setScale(glm::vec3(0.09f, 0.08f, 1.0f));
    t3.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

    Square s3; // gagang pintu
    s3.setTranslation(glm::vec3(-0.49f, -0.31f, 0.0f));
    s3.setScale(glm::vec3(0.02f, 0.01f, 1.0f));
    s3.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 0.0f));

    Square s6; // gagang pintu 1
    s6.setTranslation(glm::vec3(-0.49f, -0.35f, 0.0f));
    s6.setScale(glm::vec3(0.02f, 0.01f, 1.0f));
    s6.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 0.0f));

    Square s7; // Bendera
    s7.setTranslation(glm::vec3(-0.70f, -0.35f, 0.0f));
    s7.setScale(glm::vec3(0.03f, 0.01f, 1.0f));
    s7.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s8; // Bendera 1
    s8.setTranslation(glm::vec3(-0.70f, -0.34f, 0.0f));
    s8.setScale(glm::vec3(0.03f, 0.01f, 1.0f));
    s8.setColor(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));

    Square s4; // kotak belakang
    s4.setTranslation(glm::vec3(-0.05f, -0.25f, 0.0f));
    s4.setScale(glm::vec3(0.4f, 0.25f, 1.0f));
    s4.setColor(glm::vec4(0.10f, 0.15f, 0.25f, 1.0f));

    Square s5; // kotak atas
    s5.setTranslation(glm::vec3(-0.05f, -0.1f, 0.0f));
    s5.setScale(glm::vec3(0.2f, 0.20f, 1.0f));
    s5.setColor(glm::vec4(0.10f, 0.15f, 0.25f, 1.0f));

    Trapezoid t1; // kotak
    t1.setTranslation(glm::vec3(-0.05f, 0.2f, 0.0f));
    t1.setScale(glm::vec3(0.18f, 0.06f, 1.0f));
    t1.setColor(glm::vec4(0.10f, 0.15f, 0.25f, 1.0f));

    Circle c1; // ban 1
    c1.setTranslation(glm::vec3(-0.6f, -0.53f, 0.0f));
    c1.setScale(glm::vec3(0.4f, 0.7f, 1.0f));
    c1.setColor(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));

    Circle c2; // velg ban 1
    c2.setTranslation(glm::vec3(-0.6f, -0.53f, 0.0f));
    c2.setScale(glm::vec3(0.11f, 0.17f, 1.0f));
    c2.setColor(glm::vec4(0.741f, 0.717f, 0.4f, 1.0f));

    Circle c3; // ban 2
    c3.setTranslation(glm::vec3(-0.25f, -0.53f, 0.0f));
    c3.setScale(glm::vec3(0.4f, 0.7f, 1.0f));
    c3.setColor(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));

    Circle c4; // velg ban 2
    c4.setTranslation(glm::vec3(-0.25f, -0.53f, 0.0f));
    c4.setScale(glm::vec3(0.11f, 0.17f, 1.0f));
    c4.setColor(glm::vec4(0.741f, 0.717f, 0.4f, 1.0f));

    Circle c5; // ban 3
    c5.setTranslation(glm::vec3(0.2f, -0.53f, 0.0f));
    c5.setScale(glm::vec3(0.4f, 0.7f, 1.0f));
    c5.setColor(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));

    Circle c6; // velg ban 3
    c6.setTranslation(glm::vec3(0.2f, -0.53f, 0.0f));
    c6.setScale(glm::vec3(0.11f, 0.17f, 1.0f));
    c6.setColor(glm::vec4(0.741f, 0.717f, 0.4f, 1.0f));

    Square s15; //marka jalan
    s15.setTranslation(glm::vec3(-0.9f, -0.5f, 0.0f));
    s15.setScale(glm::vec3(0.08f, 0.030f, 1.0f));
    s15.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s20; //marka jalan 1
    s20.setTranslation(glm::vec3(0.35f, -0.5f, 0.0f));
    s20.setScale(glm::vec3(0.08f, 0.030f, 1.0f));
    s20.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s21; //marka jalan 2
    s21.setTranslation(glm::vec3(0.6f, -0.5f, 0.0f));
    s21.setScale(glm::vec3(0.08f, 0.030f, 1.0f));
    s21.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s22; //marka jalan 3
    s22.setTranslation(glm::vec3(0.85f, -0.5f, 0.0f));
    s22.setScale(glm::vec3(0.08f, 0.030f, 1.0f));
    s22.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Octagon o1; // logo
    o1.setTranslation(glm::vec3(-0.05f, -0.25f, 0.0f));
    o1.setScale(glm::vec3(0.17f + scale, 0.17f + scale, 1.0f));
    o1.setColor(glm::vec4(0.7f, 0.56f, 0.56f, 1.0f));

    vector<Object*> Objects;

    Objects.push_back(&s1);
    Objects.push_back(&s15);
    Objects.push_back(&s20);
    Objects.push_back(&s21);
    Objects.push_back(&s22);

    Objects.push_back(&p1);
    Objects.push_back(&s2);
    Objects.push_back(&t3);
    Objects.push_back(&s3);
    Objects.push_back(&s4);
    Objects.push_back(&s5);
    Objects.push_back(&s6);
    Objects.push_back(&s7);
    Objects.push_back(&s8);

    Objects.push_back(&c1);
    Objects.push_back(&c2);
    Objects.push_back(&c3);
    Objects.push_back(&c4);
    Objects.push_back(&c5);
    Objects.push_back(&c6);

    Objects.push_back(&t1);

    Objects.push_back(&o1);

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    string vertexString = readFile("vertex.vert");
    string fragmentString = readFile("fragment.frag");

    const char* vertexChar = vertexString.c_str();
    const char* fragmentChar = fragmentString.c_str();

    glShaderSource(vertexShader, 1, &vertexChar, NULL);
    glShaderSource(fragmentShader, 1, &fragmentChar, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    GLint uColor = glGetUniformLocation(program, "uColor");
    GLint uMat4x4 = glGetUniformLocation(program, "transformationMat4x4");

    Object* Object;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.85f, 0.9f, 1.0f, 1.0f); // warna window

        glUseProgram(program);

        //glDrawArrays(GL_TRIANGLES,0,6);
        for (int i = 0; i < Objects.size(); i++)
        {
            Object = Objects.at(i);
            glUniform4fv(uColor, 1, &(Object->getColor()[0]));
            glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &(Object->getTransformationMat4x4()[0][0]));
            Objects.at(i)->draw();
        }


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}