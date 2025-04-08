#include <iostream>
#include <filesystem>;
int main() {
    // Create a directory
    std::filesystem::create_directory("example_directory");

    return 0;
}