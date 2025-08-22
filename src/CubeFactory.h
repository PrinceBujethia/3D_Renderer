#include "Mesh3D.h"
#include <memory>

class CubeFactory {
public:
    static std::unique_ptr<Mesh3D> CreateCube(float size = 1.0f) {
        auto cube = std::make_unique<Mesh3D>();
        
        float halfSize = size * 0.5f;
        
        int v0 = cube->AddVertex(Vector3D(-halfSize, -halfSize,  halfSize));  // Bottom-left-front
        int v1 = cube->AddVertex(Vector3D( halfSize, -halfSize,  halfSize));  // Bottom-right-front
        int v2 = cube->AddVertex(Vector3D( halfSize,  halfSize,  halfSize));  // Top-right-front
        int v3 = cube->AddVertex(Vector3D(-halfSize,  halfSize,  halfSize));  // Top-left-front
        
        int v4 = cube->AddVertex(Vector3D(-halfSize, -halfSize, -halfSize));  // Bottom-left-back
        int v5 = cube->AddVertex(Vector3D( halfSize, -halfSize, -halfSize));  // Bottom-right-back
        int v6 = cube->AddVertex(Vector3D( halfSize,  halfSize, -halfSize));  // Top-right-back
        int v7 = cube->AddVertex(Vector3D(-halfSize,  halfSize, -halfSize));  // Top-left-back
        
        cube->AddFace(v0, v1, v2);  
        cube->AddFace(v0, v2, v3); 
        
        cube->AddFace(v5, v4, v7);
        cube->AddFace(v5, v7, v6);
        
        cube->AddFace(v4, v0, v3);
        cube->AddFace(v4, v3, v7);
        
        cube->AddFace(v1, v5, v6);
        cube->AddFace(v1, v6, v2);
        
        cube->AddFace(v3, v2, v6);
        cube->AddFace(v3, v6, v7);
        
        cube->AddFace(v4, v5, v1);
        cube->AddFace(v4, v1, v0);
        
        return cube;
    }
};
