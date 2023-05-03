#pragma once
class IndexBuffer
{
public:
	unsigned int m_RendererID;
public:
	IndexBuffer();
	~IndexBuffer();

	void Bind() const;
	void UnBind() const;
};

