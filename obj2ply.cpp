#include <assimp/Importer.hpp>
#include <assimp/Exporter.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>

void ConvertOBJtoPLY(const std::string& inputFilePath, const std::string& outputFilePath) {
    // Create an instance of the Importer class
    Assimp::Importer importer;

    // Read the OBJ file
    const aiScene* scene = importer.ReadFile(inputFilePath,
        aiProcess_CalcTangentSpace       |
        aiProcess_Triangulate            |
        aiProcess_JoinIdenticalVertices  |
        aiProcess_SortByPType);

    // Check if the import failed
    if (!scene) {
        std::cerr << "Error importing OBJ file: " << importer.GetErrorString() << std::endl;
        return;
    }

    // Create an instance of the Exporter class
    Assimp::Exporter exporter;

    // Export the scene to PLY format
    aiReturn result = exporter.Export(scene, "ply", outputFilePath);
    if (result != aiReturn_SUCCESS) {
        std::cerr << "Error exporting to PLY format: " << exporter.GetErrorString() << std::endl;
    } else {
        std::cout << "Successfully converted " << inputFilePath << " to " << outputFilePath << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input OBJ file> <output PLY file>" << std::endl;
        return 1;
    }

    std::string inputFilePath = argv[1];
    std::string outputFilePath = argv[2];

    ConvertOBJtoPLY(inputFilePath, outputFilePath);

    return 0;
}
