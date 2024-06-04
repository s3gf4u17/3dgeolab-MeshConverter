#include <iostream>
#include <fstream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

int main() {
    // Create an instance of the Assimp importer
    Assimp::Importer importer;

    // Specify the post-processing options
    unsigned int postProcessFlags =
        aiProcess_Triangulate |            // Triangulate the mesh
        aiProcess_JoinIdenticalVertices | // Join identical vertices
        aiProcess_PreTransformVertices |  // Apply transformations to vertices
        aiProcess_GenUVCoords |           // Generate UV coordinates if missing
        aiProcess_FlipUVs |               // Flip UV coordinates (if necessary)
        aiProcess_GenNormals;             // Generate normals if missing

    // Load the OBJ file
    const aiScene* scene = importer.ReadFile("nmt.obj", postProcessFlags);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "Error: " << importer.GetErrorString() << std::endl;
        return 1;
    }

    // Create a USD file
    std::ofstream usdFile("output.usd");
    if (!usdFile) {
        std::cerr << "Error: Unable to create output USD file." << std::endl;
        return 1;
    }

    // Write USD header
    usdFile << "#usda 1.0\n\n";

    // Traverse the scene and write USD data
    // For simplicity, let's assume we have only one mesh in the scene
    const aiMesh* mesh = scene->mMeshes[0];
    usdFile << "def Mesh \"mesh\"\n";
    usdFile << "{\n";

    // Write vertices
    usdFile << "\tpoint3f[] points = [\n";
    for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
        const aiVector3D& vertex = mesh->mVertices[i];
        usdFile << "\t\t(" << vertex.x << ", " << vertex.y << ", " << vertex.z << "),\n";
    }
    usdFile << "\t]\n";

    // Write normals
    usdFile << "\tnormal3f[] normals = [\n";
    for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
        const aiVector3D& normal = mesh->mNormals[i];
        usdFile << "\t\t(" << normal.x << ", " << normal.y << ", " << normal.z << "),\n";
    }
    usdFile << "\t]\n";

    // Write faces
    usdFile << "\tint[] faceVertexCounts = [";
    for (unsigned int i = 0; i < mesh->mNumFaces; ++i) {
        unsigned int numIndices = mesh->mFaces[i].mNumIndices;
        usdFile << numIndices << ", ";
    }
    usdFile << "]\n";

    usdFile << "\tint[] faceVertexIndices = [";
    for (unsigned int i = 0; i < mesh->mNumFaces; ++i) {
        for (unsigned int j = 0; j < mesh->mFaces[i].mNumIndices; ++j) {
            unsigned int index = mesh->mFaces[i].mIndices[j];
            usdFile << index << ", ";
        }
    }
    usdFile << "]\n";

    // Write USD footer
    usdFile << "}\n";

    // Close the USD file
    usdFile.close();

    std::cout << "Conversion successful." << std::endl;
    return 0;
}
