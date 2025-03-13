#ifndef INTERACTIVE_INTERFACE_H
#define INTERACTIVE_INTERFACE_H

#include <string>

class InteractiveInterface {
public:
    void run();
    void allocateResource(const std::string& resourceName);
    void releaseResource(const std::string& resourceName);
};

#endif // INTERACTIVE_INTERFACE_H
