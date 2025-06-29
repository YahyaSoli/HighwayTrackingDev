#include <torch/torch.h>
#include <iostream>

int main() {
    try {
        torch::Tensor tensor = torch::rand({2, 3});
        std::cout << "LibTorch test successful!" << std::endl;
        std::cout << tensor << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "LibTorch test failed: " << e.what() << std::endl;
        return 1;
    }
}
