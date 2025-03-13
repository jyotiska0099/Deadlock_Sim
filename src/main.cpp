#include "banker_algorithm.h"
#include "resource_allocation_graph.h"
#include "interactive_interface.h"
#include "circular_wait_detection.h"

int main() {
    BankerAlgorithm banker(3, 3); // Example: 3 processes, 3 resources
    ResourceAllocationGraph graph;
    InteractiveInterface interface;
    CircularWaitDetection detection;

    // Initialize Banker's Algorithm
    std::vector<int> availableResources = {2, 3, 2};
    banker.initializeAvailableResources(availableResources);

    std::vector<std::vector<int>> maxResources = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}};
    banker.initializeMaxResources(maxResources);

    std::vector<std::vector<int>> allocatedResources = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}};
    banker.initializeAllocatedResources(allocatedResources);

    // Run interactive interface
    interface.run();

    // Generate and visualize resource allocation graph
    graph.generateDotFile("resource_graph.dot");
    graph.visualizeGraph("resource_graph.dot");

    // Detect deadlock
    banker.detectDeadlock();

    // Detect circular wait
    detection.detectCircularWait();

    return 0;
}
