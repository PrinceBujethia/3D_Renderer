# 3D Renderer in C++ with Raylib

## Overview

This project is a simple yet flexible **3D object renderer** built from scratch in C++ using [Raylib](https://www.raylib.com/). It’s designed as a learning exercise and a portfolio project to demonstrate fundamental 3D concepts, object-oriented programming, and graphics mathematics.

## Why 3D Rendering?

Rendering in 3D is a big leap from 2D:
- Requires understanding geometry in three dimensions.
- Transformations (movement, rotation, scaling) are more involved.
- Objects are built and manipulated from vertices and faces (triangles).
- Lighting and perspective add realism and complexity.

## Key Features

- **Custom 3D Mesh Representation:** OOP-based mesh handling (vertices, faces, normals)
- **Wireframe/Solid Rendering:** Switch easily between wireframe and solid visuals
- **Basic Transformations:** Position, rotation (Euler angles), and scaling for objects
- **Interactive Camera:** Orbit, pan, and zoom with mouse/keyboard
- **Modular Design:** Easy to add new shapes or rendering techniques
- **Extensive Code Comments:** Every block explained for learners

## What I Learned

- 3D math fundamentals (vectors, dot/cross products, normals)
- Structure and transformations of 3D meshes
- Object-oriented design for graphics projects
- Basics of rendering pipelines (projection, rasterization, depth)
- Integration of Raylib’s 3D API


## Getting Started

### Prerequisites

- **C++ Compiler** (GCC, MSVC, Clang, etc.)
- **Raylib Library** ([Install instructions](https://www.raylib.com/))
    - On Linux: `sudo apt-get install libraylib-dev`
    - On Windows/Mac: Follow Raylib’s setup instructions


Alternatively, open and run in your favorite IDE!

## Project Structure

├── main.cpp # Application entrypoint
├── Mesh3D.h/cpp # 3D mesh class (vertices, faces, transformations)
├── CubeFactory.h/cpp # Utility for creating cube objects
├── MeshRenderer.h/cpp # Rendering logic (wireframe, solid)
├── Vector3D.h/cpp # 3D vector math
├── README.md


## How It Works

- **Mesh3D**: Manages object geometry and transformations.
- **CubeFactory**: Generates vertex/face data for cubes.
- **MeshRenderer**: Draws the mesh using Raylib’s 3D functions.
- **main.cpp**: Sets up camera controls, user input, animation, and rendering.

## Customization

- Add new shapes by building additional factories.
- Integrate new rendering modes (lighting, textures, etc.).
- Tweak camera controls for different experiences.

## Contributing

Open to feedback, suggestions, and improvements!
- Fork the repo
- Submit pull requests
- Create issues for bugs or feature requests


**Feedback welcome!**  
If you found this project useful or have ideas for improvement, please let me know via issues or comments.
