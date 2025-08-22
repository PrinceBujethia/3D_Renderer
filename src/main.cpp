#include "raylib.h"
#include "Mesh3D.h"
#include "CubeFactory.h"
#include "MeshRenderer.h"
#include <memory>

class Advanced3DRenderer {
private:
    Camera3D camera;
    std::unique_ptr<Mesh3D> cube;
    const int screenWidth = 800;
    const int screenHeight = 600;
    float rotationSpeed = 1.0f;

public:
    Advanced3DRenderer() {
        InitWindow(screenWidth, screenHeight, "Advanced 3D Learning Project");
        SetTargetFPS(60);

        camera.position = {4.0f, 2.0f, 4.0f};
        camera.target = {0.0f, 0.0f, 0.0f};
        camera.up = {0.0f, 1.0f, 0.0f};
        camera.fovy = 60.0f;
        camera.projection = CAMERA_PERSPECTIVE;

        cube = CubeFactory::CreateCube(2.0f);
        cube->SetPosition(Vector3D(0, 0, 0));
    }

    ~Advanced3DRenderer() {
        CloseWindow();
    }

    void Run() {
        while (!WindowShouldClose()) {
            Update();
            Draw();
        }
    }

    void Update() {
        UpdateCamera(&camera, CAMERA_ORBITAL);

        Vector3D currentRotation = cube->GetRotation();
        currentRotation.y += rotationSpeed * GetFrameTime(); 
        cube->SetRotation(currentRotation);

        if (IsKeyDown(KEY_UP)) rotationSpeed += 1.0f * GetFrameTime();
        if (IsKeyDown(KEY_DOWN)) rotationSpeed -= 1.0f * GetFrameTime();
        if (rotationSpeed < 0) rotationSpeed = 0;
    }

    void Draw() {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawLine3D({0, 0, 0}, {2, 0, 0}, RED);    
        DrawLine3D({0, 0, 0}, {0, 2, 0}, GREEN);  
        DrawLine3D({0, 0, 0}, {0, 0, 2}, BLUE);   

        MeshRenderer::DrawMixed(*cube, Fade(RED, 0.8f), MAROON);

        EndMode3D();

        DrawText("3D Custom Mesh Renderer", 10, 10, 20, DARKGRAY);
        DrawText("Mouse: Rotate camera", 10, 35, 16, DARKGRAY);
        DrawText("UP/DOWN: Control rotation speed", 10, 55, 16, DARKGRAY);
        DrawText(TextFormat("Rotation Speed: %.1f", rotationSpeed), 10, 75, 16, DARKGRAY);
        DrawFPS(10, screenHeight - 30);

        EndDrawing();
    }
};

int main() {
    Advanced3DRenderer renderer;
    renderer.Run();
    return 0;
}
