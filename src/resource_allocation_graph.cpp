#include "resource_allocation_graph.h"
#include <iostream>

void ResourceAllocationGraph::generateDotFile(const std::string& filename) {
    std::ofstream dotFile(filename);
    dotFile << "digraph ResourceAllocationGraph {\n";
    // Example nodes and edges
    dotFile << "P1 -> R1;\n";
    dotFile << "P2 -> R2;\n";
    dotFile << "R1 -> P1;\n";
    dotFile << "R2 -> P2;\n";
    dotFile << "}\n";
    dotFile.close();
}

void ResourceAllocationGraph::visualizeGraph(const std::string& dotFilename) {
    // Use Graphviz to convert the .dot file into an image.
    std::string command = "dot -Tpng " + dotFilename + " -o output.png";
    system(command.c_str());
}
