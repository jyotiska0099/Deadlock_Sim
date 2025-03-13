#include "banker_algorithm.h"
#include <iostream>

BankerAlgorithm::BankerAlgorithm(int numProcesses, int numResources) 
    : numProcesses(numProcesses), numResources(numResources) {}

void BankerAlgorithm::initializeAvailableResources(const std::vector<int>& available) {
    availableResources = available;
}

void BankerAlgorithm::initializeMaxResources(const std::vector<std::vector<int>>& max) {
    maxResources = max;
}

void BankerAlgorithm::initializeAllocatedResources(const std::vector<std::vector<int>>& allocated) {
    allocatedResources = allocated;
}

bool BankerAlgorithm::isSafeState(const std::vector<int>& resourceRequest) {
    std::vector<bool> finish(numProcesses, false);
    std::vector<int> work = availableResources;

    while (true) {
        bool found = false;
        for (int i = 0; i < numProcesses; ++i) {
            if (!finish[i]) {
                bool canFinish = true;
                for (int j = 0; j < numResources; ++j) {
                    if (maxResources[i][j] - allocatedResources[i][j] > work[j]) {
                        canFinish = false;
                        break;
                    }
                }
                if (canFinish) {
                    for (int j = 0; j < numResources; ++j) {
                        work[j] += allocatedResources[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) break;
    }

    for (bool f : finish) {
        if (!f) return false; // Not safe state
    }
    return true; // Safe state
}

void BankerAlgorithm::detectDeadlock() {
    // Basic deadlock detection: If no safe sequence exists, it's a deadlock.
    std::vector<int> request(numResources, 0);
    if (!isSafeState(request)) {
        std::cout << "Deadlock detected." << std::endl;
    } else {
        std::cout << "No deadlock detected." << std::endl;
    }
}
