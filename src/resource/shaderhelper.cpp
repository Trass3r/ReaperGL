#include "shaderhelper.hpp"

#include <fstream>
#include <iostream>

void ShaderHelper::loadSimpleShader(mogl::ShaderProgram& shader, const std::string& vertexFile, const std::string& fragmentFile)
{
    std::ifstream   vsFile(vertexFile);
    std::ifstream   fsFile(fragmentFile);
    mogl::Shader    vertex(vsFile, mogl::Shader::Type::VertexShader);
    mogl::Shader    fragment(fsFile, mogl::Shader::Type::FragmentShader);

    if (!vertex.compile())
        std::cerr << "Vertex shader " << vertexFile << std::endl << vertex.getLog() << std::endl;
    if (!fragment.compile())
        std::cerr << "Fragment shader" << fragmentFile << std::endl << fragment.getLog() << std::endl;

    shader.attach(vertex);
    shader.attach(fragment);

    if (!shader.link())
        std::cerr << "Program " << std::endl << shader.getLog() << std::endl;
}
