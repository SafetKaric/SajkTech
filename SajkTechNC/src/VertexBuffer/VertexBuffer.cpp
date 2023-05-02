#include "GL/glew.h"
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(float* points)
	:m_RendererID(0), m_Points(points)
{
	
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, 3 * 3 * sizeof(float), points, GL_STATIC_DRAW);
}

const void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}
const void VertexBuffer::UnBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}
