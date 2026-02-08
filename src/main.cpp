#include "app.hpp"
#include <iostream>

int main()
{
    app::Application app;
    app.run();
    return 0;
}

void app::Application::run()
{
    std::cout << "Hello from " << name_ << std::endl;
}
