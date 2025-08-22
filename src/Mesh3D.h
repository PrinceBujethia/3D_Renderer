#ifndef MESH3D_H
#define MESH3D_H

#include "Vector3D.h"
#include <vector>

struct Face {
    int vertexIndex1, vertexIndex2, vertexIndex3;
    Vector3D normal;
    
    Face(int v1, int v2, int v3) : vertexIndex1(v1), vertexIndex2(v2), vertexIndex3(v3) {}
};

class Mesh3D {
private:
    std::vector<Vector3D> vertices;  
    std::vector<Face> faces;         
    Vector3D position;               
    Vector3D rotation;               
    Vector3D scale;                  
    
public:
    Mesh3D() : position(0, 0, 0), rotation(0, 0, 0), scale(1, 1, 1) {}
    
    int AddVertex(const Vector3D& vertex) {
        vertices.push_back(vertex);
        return vertices.size() - 1;
    }
    
    void AddFace(int v1, int v2, int v3) {
        faces.emplace_back(v1, v2, v3);
        CalculateFaceNormal(faces.back());
    }
    
    void CalculateFaceNormal(Face& face) {
        Vector3D v1 = vertices[face.vertexIndex1];
        Vector3D v2 = vertices[face.vertexIndex2];
        Vector3D v3 = vertices[face.vertexIndex3];
        
        Vector3D edge1 = v2 - v1;
        Vector3D edge2 = v3 - v1;
        face.normal = edge1.Cross(edge2).Normalize();
    }
    
    void SetPosition(const Vector3D& pos) { position = pos; }
    void SetRotation(const Vector3D& rot) { rotation = rot; }
    void SetScale(const Vector3D& scl) { scale = scl; }
    
    const std::vector<Vector3D>& GetVertices() const { return vertices; }
    const std::vector<Face>& GetFaces() const { return faces; }
    Vector3D GetPosition() const { return position; }
    Vector3D GetRotation() const { return rotation; }
    Vector3D GetScale() const { return scale; }
    
    std::vector<Vector3D> GetTransformedVertices() const {
        std::vector<Vector3D> transformed;
        
        for (const auto& vertex : vertices) {
            Vector3D v = vertex;
            
            v.x *= scale.x;
            v.y *= scale.y;
            v.z *= scale.z;
            
            float cosY = cos(rotation.y);
            float sinY = sin(rotation.y);
            float newX = v.x * cosY - v.z * sinY;
            float newZ = v.x * sinY + v.z * cosY;
            v.x = newX;
            v.z = newZ;
            
            v = v + position;
            
            transformed.push_back(v);
        }
        
        return transformed;
    }
};

#endif
