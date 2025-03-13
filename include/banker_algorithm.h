#ifndef BANKER_ALGORITHM_H
#define BANKER_ALGORITHM_H

#include <vector>

class BankerAlgorithm {
public:
    BankerAlgorithm(int numProcesses, int numResources);
    void initializeAvailableResources(const std::vector<int>& available);
    void initializeMaxResources(const std::vector<std::vector<int>>& max);
    void initializeAllocatedResources(const std::vector<std::vector<int>>& allocated);
    bool isSafeState(const std::vector<int>& resourceRequest);
    void detectDeadlock();

private:
    int numProcesses;
    int numResources;
    std::vector<int> availableResources;
    std::vector<std::vector<int>> maxResources;
    std::vector<std::vector<int>> allocatedResources;
};

#endif // BANKER_ALGORITHM_H
