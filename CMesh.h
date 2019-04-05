#pragma once
#include "Header.h"
#if defined(DIRECTX)
#include "CBuffer.h"
#include "CTexture2D.h"
class CMesh
{
public:
	CBuffer VertexBuffer;
	CBuffer IndexBuffer;
	CBuffer ChangeEveryFrame;
	int m_numIndex;
	WORD* m_indices;
	SimpleVertex* m_vertices;

	std::string textName;
	LPCWSTR dirText;
	CTexture2D TextureMesh;

public:
	CMesh() = default;
	// Complete Mesh properties
	CMesh(D3D11_USAGE Usage, SimpleVertex* VertexArray, WORD* IndexArray, int numRealVertex, int numIndex, D3D11_BIND_FLAG BindFlags, int CPUAccesFlags, int Offset);
	// Simple Mesh Properties (Useful for setting the complete data)
	CMesh(int numRealVertex, int numIndex, SimpleVertex* VertexArray, WORD* IndexArray);
	// Assimp Constructor
	
	~CMesh();
public:
	CBChangesEveryFrame m_object;
	CBChangesEveryFrame m_object2;
	TextAndMesh TM;
	void loadMeshText(ID3D11Device* m_pd3dDevice);

	bool DoTheImportThing( );
};

#elif defined(OPENGL)
#pragma once
//#include "Config.h"
//#include "CVertexBuffer.h"
class CMesh
{
public:
	CMesh();
	~CMesh();
public:

	GLuint buuferID;
	GLuint textID;
	GLuint vertexArrayID;

	int m_tris;
	int m_indices;
	struct simpleVertex
	{
		glm::vec3 position;
		glm::vec2 texCoord;

	};
	simpleVertex * buffersito;
	//CVertexBuffer Buffer;
	vector<unsigned int> VertexIndex;
	vector <glm::vec3> temp_Vertex;
	vector<glm::vec3> glmVertices;
	vector<glm::vec2> tem_uvs;
	string texname;
	glm::vec2 uv;
	glm::vec3 Vertices;
	
	
	glm::mat4 MeshMatrix;
	glm::vec3 newScale;
	glm::vec3 translation;
	glm::mat4 officialMatrix;
	// Scale Model
	float m_Scalex = 0.01f;
	float m_Scaley = 0.01f;
	float m_Scalez = 0.01f;
	// Trasform
	float m_x = 2.0f;
	float m_y = 0;
	float m_z = 0;
	float m_timer;

public:
	void LoadMeshV2(int numVertex, int numIndex, aiVector3D* VertexArray, aiVector3D* textCoord, std::vector<std::uint32_t>& IndexArray);
	void loadTexture();
	void loadTexture2();
	void createMeshMatrix(float Iden, float x, float y, float z, float ScaleX, float ScaleY, float ScaleZ);
	glm::mat4 setMatrix();
};


#endif