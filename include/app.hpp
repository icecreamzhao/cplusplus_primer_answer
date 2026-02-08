#pragma once

#include <string>

namespace app {

class Application {
public:
    Application() = default;
    ~Application() = default;

    void run();

private:
    std::string name_{"industrial-cmake"};
};

} // namespace app
