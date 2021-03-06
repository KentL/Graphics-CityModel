//========================================================================
// Week 5 - Buffers and Attributes
//
// Example 4: Rendering a cube, using our beginnings of Wolf
//========================================================================
#define GLFW_INCLUDE_GL3
#define GLFW_NO_GLU
#include <stdio.h>
#include <stdlib.h>
#ifndef __APPLE__
#include <GL/glew.h>
#endif
#include <GL/glfw.h>
#include "W_Common.h"
#include "W_BufferManager.h"
#include "W_VertexDeclaration.h"
#include "W_ProgramManager.h"

struct Vertex
{
	GLfloat x,y,z;
	GLubyte r,g,b,a;
};

static const Vertex cubeVertices[] = {
// Front
	{ -0.5f, -0.5f, 0.5f, 255, 0, 0, 255 },
	{ -0.5f,  0.5f, 0.5f, 255, 0, 0, 255 },
	{  0.5f,  0.5f, 0.5f, 255, 0, 0, 255 },
	{  0.5f,  0.5f, 0.5f, 255, 0, 0, 255 },
	{  0.5f, -0.5f, 0.5f, 255, 0, 0, 255 },
	{ -0.5f, -0.5f, 0.5f, 255, 0, 0, 255 },

	// Back
	{  0.5f,  0.5f,-0.5f, 128, 0, 0, 255 },
	{ -0.5f,  0.5f,-0.5f, 128, 0, 0, 255 },
	{ -0.5f, -0.5f,-0.5f, 128, 0, 0, 255 },
	{ -0.5f, -0.5f,-0.5f, 128, 0, 0, 255 },
	{  0.5f, -0.5f,-0.5f, 128, 0, 0, 255 },
	{  0.5f,  0.5f,-0.5f, 128, 0, 0, 255 },

	// Left
	{ -0.5f,  0.5f,-0.5f, 0, 255, 0, 255 },
	{ -0.5f,  0.5f, 0.5f, 0, 255, 0, 255 },
	{ -0.5f, -0.5f, 0.5f, 0, 255, 0, 255 },
	{ -0.5f, -0.5f, 0.5f, 0, 255, 0, 255 },
	{ -0.5f, -0.5f,-0.5f, 0, 255, 0, 255 },
	{ -0.5f,  0.5f,-0.5f, 0, 255, 0, 255 },

	// Right
	{  0.5f,  0.5f, 0.5f, 0, 128, 0, 255 },
	{  0.5f,  0.5f,-0.5f, 0, 128, 0, 255 },
	{  0.5f, -0.5f,-0.5f, 0, 128, 0, 255 },
	{  0.5f, -0.5f,-0.5f, 0, 128, 0, 255 },
	{  0.5f, -0.5f, 0.5f, 0, 128, 0, 255 },
	{  0.5f,  0.5f, 0.5f, 0, 128, 0, 255 },

	// Top
	{ -0.5f,  0.5f, 0.5f, 0, 0, 255, 255 },
	{ -0.5f,  0.5f,-0.5f, 0, 0, 255, 255 },
	{  0.5f,  0.5f,-0.5f, 0, 0, 255, 255 },
	{  0.5f,  0.5f,-0.5f, 0, 0, 255, 255 },
	{  0.5f,  0.5f, 0.5f, 0, 0, 255, 255 },
	{ -0.5f,  0.5f, 0.5f, 0, 0, 255, 255 },

	// Bottom
	{ -0.5f, -0.5f, 0.5f, 0, 0, 128, 255 },
	{  0.5f, -0.5f, 0.5f, 0, 0, 128, 255 },
	{  0.5f, -0.5f,-0.5f, 0, 0, 128, 255 },
	{  0.5f, -0.5f,-0.5f, 0, 0, 128, 255 },
	{ -0.5f, -0.5f,-0.5f, 0, 0, 128, 255 },
	{ -0.5f, -0.5f, 0.5f, 0, 0, 128, 255 },
};

static wolf::VertexBuffer* g_pVB = 0;
static wolf::VertexDeclaration* g_pDecl = 0;
static wolf::Program* g_pProgram = 0;

void InitExample5()
{
   
	
	glEnable(GL_DEPTH_TEST);
    g_pProgram = wolf::ProgramManager::CreateProgram("data/week5/cube.vsh", "data/week5/cube.fsh");
    g_pVB = wolf::BufferManager::CreateVertexBuffer(cubeVertices, sizeof(Vertex) * 6 * 3 * 2);

	g_pDecl = new wolf::VertexDeclaration();
	g_pDecl->Begin();
	g_pDecl->AppendAttribute(wolf::AT_Position, 3, wolf::CT_Float);
	g_pDecl->AppendAttribute(wolf::AT_Color, 4, wolf::CT_UByte);
	g_pDecl->SetVertexBuffer(g_pVB);
	g_pDecl->End();
}

void RenderExample5()
{
	static float s_fRotation = 0;
	glm::mat4 mProj = glm::perspective(45.0f, 1280.0f / 720.0f, 0.1f, 1000.0f);
	glm::mat4 mView = glm::lookAt(glm::vec3(0.0f,0.0f,8.0f), glm::vec3(0.0f,0.0f,0.0f), glm::vec3(0.0f,1.0f,0.0f));
	glm::mat4 mWorld = glm::rotate(s_fRotation, 0.0f, 1.0f, 0.0f);
	mWorld = mWorld * glm::rotate(s_fRotation, 1.0f, 0.0f, 0.0f);
	s_fRotation += 1.0f;

    // Use shader program.
	g_pProgram->Bind();
    
	// Bind Uniforms
    g_pProgram->SetUniform("projection", mProj);
    g_pProgram->SetUniform("view", mView);
    g_pProgram->SetUniform("world", mWorld);    
    
	// Set up source data
	g_pDecl->Bind();

	// Draw!
	

	{
		glDrawArrays(GL_TRIANGLES, 0, 6 * 3 * 2);

		mWorld = glm::translate(2.0f, 0.0f, 0.0f) * mWorld;
		g_pProgram->SetUniform("world", mWorld);
		glDrawArrays(GL_TRIANGLES, 0, 6 * 3 * 2);

		mWorld = glm::translate(-4.0f, 0.0f, 0.0f) * mWorld;
		g_pProgram->SetUniform("world", mWorld);
		glDrawArrays(GL_TRIANGLES, 0, 6 * 3 * 2);

		mWorld = glm::translate(-2.0f, 0.0f, 0.0f) * mWorld;
		g_pProgram->SetUniform("world", mWorld);
		glDrawArrays(GL_TRIANGLES, 0, 6 * 3 * 2);

	}//SECOND ROW,3 CUBES


	mWorld = glm::translate(2.0f, 0.0f, 0.0f) * mWorld;

	{   mWorld = glm::translate(0.0f, 2.0f, 0.0f) * mWorld;
	    g_pProgram->SetUniform("world", mWorld);
	    glDrawArrays(GL_TRIANGLES, 0, 6 * 3 * 2);


		mWorld = glm::translate(2.0f, 0.0f, 0.0f) * mWorld;
		g_pProgram->SetUniform("world", mWorld);
		glDrawArrays(GL_TRIANGLES, 0, 6 * 3 * 2);

		mWorld = glm::translate(-4.0f, 0.0f, 0.0f) * mWorld;
		g_pProgram->SetUniform("world", mWorld);
		glDrawArrays(GL_TRIANGLES, 0, 6 * 3 * 2);
	}//FIRST ROW,3 CUBES

		{   mWorld = glm::translate(0.0f, -4.0f, 0.0f) * mWorld;
		g_pProgram->SetUniform("world", mWorld);
		glDrawArrays(GL_TRIANGLES, 0, 6 * 3 * 2);


		mWorld = glm::translate(2.0f, 0.0f, 0.0f) * mWorld;
		g_pProgram->SetUniform("world", mWorld);
		glDrawArrays(GL_TRIANGLES, 0, 6 * 3 * 2);

		mWorld = glm::translate(2.0f, 0.0f, 0.0f) * mWorld;
		g_pProgram->SetUniform("world", mWorld);
		glDrawArrays(GL_TRIANGLES, 0, 6 * 3 * 2);
		}//THIRD ROW,3 CUBES

}


