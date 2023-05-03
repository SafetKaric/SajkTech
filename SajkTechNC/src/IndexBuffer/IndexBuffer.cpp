#include "GL/glew.h"
#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
	:m_RendererID(0)
{
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void IndexBuffer::UnBind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
