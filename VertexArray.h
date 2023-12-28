#pragma once

class VertexArray
{
public:
	VertexArray() = delete;
	VertexArray(const float* verts, unsigned int numVerts, const unsigned int* indices, unsigned int numIndices);
	~VertexArray();

	void SetActive();

	unsigned int GetNumVerts() const { return mNumVerts; }
	unsigned int GetNumIndices() const { return mNumIndices; }
private:
	unsigned int mNumVerts;
	unsigned int mNumIndices;
	
	unsigned int mVertexBuffer;
	unsigned int mIndexBuffer;

	unsigned int mVertexArray;
};

