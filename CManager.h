#pragma once
#include "Header.h"
#if defined(DIRECTX)


#include "CMesh.h"
#include "CDevice.h"
#include "CDeviceContext.h"
#include "CCam.h"
#include "CTexture2D.h"
#include "CRenderTarget.h"
#include "CSwapChain.h"
#include "CVertexShader.h"
#include "CPixelShader.h"
#include "CLayout.h"
class CManager
{
public:
	CManager();
	~CManager();
public:
	// Objects
	std::vector<CMesh> m_mesh;
	CDevice Dev;
	CDeviceContext DevContext;
	CCam Camera;
	CTexture2D Tex2D;
	CRenderTarget RenTarg;
	CRenderTarget RenTarg2;
	CSwapChain SwCh;
	CVertexShader VShader;
	CPixelShader PShader;
	CLayout LayOut;
	// Buffer Objects
	CBuffer NeverChangeBuffer;
	CBuffer ChangeOnResizeBuffer;
	CBuffer ChangeEveryFrameBuffer;


public:
	// Global Variables
	HINSTANCE                           m_hInst = NULL;
	HWND                                m_hWnd = NULL;
	D3D_FEATURE_LEVEL                   m_featureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11Buffer*                       m_pCBNeverChanges = NULL;
	ID3D11Buffer*                       m_pCBChangeOnResize = NULL;
	ID3D11Buffer*                       m_pCBChangesEveryFrame = NULL;
	XMMATRIX                            m_World;
	XMFLOAT4                            m_vMeshColor= XMFLOAT4(1.0f,1.0f,1.0f,1.0f);

	// Mesh Model Matrix 
	float m_x = 0.0f;
	float m_y = 0.0f;
	float m_z = 0.0f;
	// Cam Model Matrix

	XMMATRIX newView;
	float m_Cx = 0.1f;
	float m_Cy = 0.1f;
	float m_Cz = 0.1f;

	XMMATRIX DwarfMatrix = XMMATRIX(
		.03f, 0.0f, 0.0f, m_x,
		0.0f, .03f, 0.0f, m_y,
		0.0f, 0.0f, .03f, m_z,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	XMMATRIX translate = XMMATRIX(
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	XMMATRIX translateN = XMMATRIX(
		0.0f, 0.0f, 0.0f, -0.1f,
		0.0f, 0.0f, 0.0f, 0.1f,
		0.0f, 0.0f, 0.0f, 0.1f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	GLFLOAT3 Eye;
	GLFLOAT3 At;
	GLFLOAT3 Up;
	// Rotatiion
	float positiveRotation = 1.0f;
	float negativeRotation = -1.0f;

	// Scale
	float meshScalePositive = 1.1f;
	float meshScaleNegative = 0.9f;
	XMMATRIX DwarfMatrixScale = XMMATRIX(
		meshScalePositive, 0.0f, 0.0f, 0.0f,
		0.0f, meshScalePositive, 0.0f, 0.0f,
		0.0f, 0.0f, meshScalePositive, 0.0f,
		0.0f, 0.0f, 0.0f			, 1.0f
	);

	XMMATRIX DwarfMatrixScale2 = XMMATRIX(
		meshScaleNegative, 0.0f, 0.0f, 0.0f,
		0.0f, meshScaleNegative, 0.0f, 0.0f,
		0.0f, 0.0f, meshScaleNegative, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	// Change cam
	int camChanges = 0;
	// Timer
	bool isTimePress = false;
	float m_timer;

	float newTime = 0.0002f;
	// Other bools < (!) Search for proper comment in code >
	bool onInitpepito = false;
	bool isDeviceInit = false;

	// Parameter for inputs - Used in ImGui
	int m_Param;

	// Assimp
	const aiScene* Model;
	SimpleVertex* m_Vertex;
	WORD* m_Index;
	int m_numVertex;
	int m_numIndex;
	int Amount_Meshes = 0;

	TextAndMesh TM;

	// Change Party
	bool isParty = false;
	float m_R = 1.0f;
	float m_G = 1.0f;
	float m_B = 1.0f;
	float m_A = 1.0f;
	float m_incrase = 0.05f;

	
public:
	bool initDevide(HRESULT &hr, const HWND& hWnd);
	void SwapChain(const HWND& hWnd);
	bool createRenderTargetView(HRESULT &hr, ID3D11RenderTargetView* &mRenderTargetView);
	void createDepthStencilTexture(HRESULT &hr);
	void createDepthStecilView(HRESULT &hr);
	void setUpViewport();
	void createTheSampleState(HRESULT &hr);

	// Cam
	void initCam();
	void initCam2();
	void camChange();
	void cameraMove(ID3D11DeviceContext* &pImmediateContext, ID3D11Buffer*&pCBNeverChanges, WPARAM wParam, float xPos, float yPos);
	void camRotation(ID3D11DeviceContext* &pImmediateContext, ID3D11Buffer*&pCBNeverChanges);
	void CManager::resizeCam(float width, float height, ID3D11DeviceContext* &pImmediateContext, ID3D11Buffer* & g_pCBChangeOnResize);

	// Textures
	void SwapChainResize(float width, float height, ID3D11DeviceContext* &pImmediateContext, ID3D11Buffer* pBChangeOnResize);
	// Assimp Mesh
	void createAssimpMesh();
	void LoadMesh(int numVertices, int numIndices, aiVector3D* VertexArray, aiVector3D* textCoord, std::vector<std::uint32_t>& IndexArray);
	void readTextMesh();
	
	
	void MeshGenerator();
	vector <const char*> filePaths;
	void MeshGenerator2();
	vector <const char*> filePaths2;


	



	// render Texture
	ID3D11Texture2D* TextureID;
	ID3D11ShaderResourceView* ShaderRVID;

	CRenderTarget RenderTargetID;
	void CreateRenderTexture();

};

#elif defined(OPENGL)
#include "CCam.h"
#include "CShader.h"
//#include "CVertexBuffer.h"
//#include "CIndexBuffer.h"
//#include "CVertexArrayObject.h"
#include "CMesh.h"
#include "CDevice.h"
class CManager
{
public:
	CManager();
	~CManager();
public:
	void Clear() const;
	void CamChange();
	glm::mat4 setModelPos();
	glm::mat4 setModelPos2();
	// Init's
	void LoadScene();
	void initCamera();
	void WindowResize(int width, int height);
	void initwindow(float width, float height);
	void initImGuiWindow();
	void setImGui();


	// Mesh Generator

	// First Mesh
	CMesh Meshes;
	vector<CMesh> Mesh;
	vector <const char*> filePaths;
	void MeshLoader(const char* filepath);
	void loadTexture(int i);
	// Second Mesh
	CMesh Meshes2;
	vector<CMesh> Mesh2;
	vector <const char*> filePaths2;
	void MeshLoader2(const char* filepath);
	void loadTexture2(int i);
	// Third Mesh
	CMesh Meshes3;
	vector<CMesh> Mesh3;
	vector <const char*> filePaths3;
	void MeshLoader3(const char* filepath);
	void loadTexture3(int i);
	// Fourth Mesh
	CMesh Meshes4;
	vector<CMesh> Mesh4;
	vector <const char*> filePaths4;
	void MeshLoader4(const char* filepath);
	void loadTexture4(int i);


	// Initialize All
	void init();

public:
	// Objects
	CCam Cam;
	CCam StaticCam;
	CDevice Device;
	CShader* SHADER;
	POINT windowSize;
	GLuint fremeBufferID;

	//
	GLuint frameBufferID2;
	GLuint DepthBufferID2;
	GLuint TexBufferID2;
	void createRenderTexture();
	void renderTextureCamera();

public:
	// Chagne cam
	int m_ChangeCam;
	
	float scale = 1.0f;
	

	// timer
	bool isTimePress = false; 
	//float m_timer;
	float newTime = .2f;

	// Change Party
	bool isParty = false;
	float m_R = 1.0f;
	float m_G = 1.0f;
	float m_B = 1.0f;
	float m_A = 1.0f;
	float m_incrase = 0.05f;

	// ImGui Data
	int m_tris1 = 0;
	int m_tris2 = 0;
	int m_amountMeshes = 0;

	// Scaling while time
	bool isScaling = false;

};
#endif