#ifndef RESOURCE_ALLOCATION_GRAPH_H
#define RESOURCE_ALLOCATION_GRAPH_H

#include <fstream>
#include <string>

class ResourceAllocationGraph {
public:
    void generateDotFile(const std::string& filename);
    void visualizeGraph(const std::string& dotFilename);
};

#endif // RESOURCE_ALLOCATION_GRAPH_H
