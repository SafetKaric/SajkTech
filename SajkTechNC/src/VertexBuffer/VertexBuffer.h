#pragma once
class VertexBuffer
{
private:
	unsigned int m_RendererID;
	float* m_Points;
public:
	VertexBuffer(float* points);
	~VertexBuffer();

	const void Bind() const;
	const void UnBind() const;
};

