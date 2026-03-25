#include <iostream>
#include <iomanip>
#include "SORSolver.hpp"
#include <vector>

int main(){
    int size, strip_num, iterations;
    double parameter;

    if(!(std::cin >> size >> strip_num)) return 0;

    std::vector<std::vector<double>> strips(strip_num);

    for (int i = 0; i < strip_num; ++i){
        for (int j = 0; j < size - strip_num + i ; ++j){
            double temp;
            std::cin >> temp;
            strips[i].push_back(temp);
        }
    }

    std::vector<double> diagonal(size);
    for (int i = 0; i < size; ++i) std::cin >> diagonal[i];

    std::vector<double> result(size);
    for (int i = 0; i < size; ++i) std::cin >> result[i];

    std::vector<double> initial(size);
    for (int i = 0; i < size; ++i) std::cin >> initial[i];

    std::cin >> parameter >> iterations;

    std::vector<double> final_x = SORSolver::solve(strips, result, diagonal, initial, size, iterations, parameter, strip_num);   

    for (int i = 0; i < size; ++i) {
        std::cout << std::scientific << std::setprecision(10) << final_x[i] << "\n";
    }
    
    return 0;
}
