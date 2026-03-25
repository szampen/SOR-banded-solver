#ifndef SORSOLVER_HPP
#define SORSOLVER_HPP

#include <vector>

class SORSolver {

public:
    static std::vector<double> solve(
        const std::vector<std::vector<double>>& strip,
        const std::vector<double>& y,
        const std::vector<double>& diag,
        std::vector <double> x0,
        int size,
        int iter,
        double omega,
        int strip_num
    );
};

#endif