#define OPTIM_ENABLE_EIGEN_WRAPPERS
#include "optim.hpp"
#include <chrono>
#include <iostream>

//
// Ackley function

double ackley_fn(const optim::Vec_t &vals_inp, optim::Vec_t *grad_out, void *opt_data) {
    const double x = vals_inp(0);
    const double y = vals_inp(1);
    const double pi = 3.1415;

    double obj_val = -20 * std::exp(-0.2 * std::sqrt(0.5 * (x * x + y * y))) - std::exp(0.5 * (std::cos(2 * pi * x) + std::cos(2 * pi * y))) + 22.718282L;

    return obj_val;
}

int main() {
    // initial values:
    optim::Vec_t x = optim::Vec_t::Constant(2, 1, 2);// (2,2)

    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

    bool success = optim::pso(x, ackley_fn, nullptr);

    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    if (success) {
        std::cout << "pso: Ackley test completed successfully.\n"
                  << "elapsed time: " << elapsed_seconds.count() << "s\n";
    } else {
        std::cout << "pso: Ackley test completed unsuccessfully." << std::endl;
    }

    std::cout << "\npso: solution to Ackley test:\n"
              << x << std::endl;

    return 0;
}
