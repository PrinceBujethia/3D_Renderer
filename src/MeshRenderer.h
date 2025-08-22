#include "Mesh3D.h"
#include "raylib.h"

class MeshRenderer {
public:
    static void DrawWireframe(const Mesh3D& mesh, Color color = BLACK) {
        auto transformedVertices = mesh.GetTransformedVertices();
        const auto& faces = mesh.GetFaces();
        
        for (const auto& face : faces) {
            Vector3D v1 = transformedVertices[face.vertexIndex1];
            Vector3D v2 = transformedVertices[face.vertexIndex2];
            Vector3D v3 = transformedVertices[face.vertexIndex3];
            
            DrawLine3D(v1.ToRaylib(), v2.ToRaylib(), color);
            DrawLine3D(v2.ToRaylib(), v3.ToRaylib(), color);
            DrawLine3D(v3.ToRaylib(), v1.ToRaylib(), color);
        }
    }
    
    static void DrawSolid(const Mesh3D& mesh, Color color = RED) {
        auto transformedVertices = mesh.GetTransformedVertices();
        const auto& faces = mesh.GetFaces();
        
        for (const auto& face : faces) {
            Vector3D v1 = transformedVertices[face.vertexIndex1];
            Vector3D v2 = transformedVertices[face.vertexIndex2];
            Vector3D v3 = transformedVertices[face.vertexIndex3];
            
            DrawTriangle3D(v1.ToRaylib(), v2.ToRaylib(), v3.ToRaylib(), color);
        }
    }
    
    static void DrawMixed(const Mesh3D& mesh, Color solidColor = RED, Color wireColor = BLACK) {
        DrawSolid(mesh, solidColor);
        DrawWireframe(mesh, wireColor);
    }
};
