#include "SORSolver.hpp"
#include <algorithm>

std::vector<double> SORSolver::solve(
        const std::vector<std::vector<double>>& strip,
        const std::vector<double>& y,
        const std::vector<double>& diag,
        std::vector <double> x0,
        int size,
        int iter,
        double omega,
        int strip_num
    )
{
    for (int i = 0; i < iter; ++i){
        for(int j = 0; j < size; ++j){
            double m = y[j];

            int spaces_to_subtract = std::min(j, strip_num);
            int it = strip.size()-1;

            if(spaces_to_subtract > 0){
                for (int k = j - 1 ; k >= j - spaces_to_subtract; --k){
                    m -= strip[it][k] * x0[k];
                    it--;
                }
            }

            spaces_to_subtract = std::min(strip_num,size - j - 1);
            it = 0;

            if(spaces_to_subtract > 0){
                for (int k = j + 1; k <= j + spaces_to_subtract; ++k){
                    m -= strip[strip_num - 1 - it][j] * x0[k];
                    it++;
                }
            }

            x0[j] = (1 - omega) * x0[j] + ((omega * m)/diag[j]);
        }
    }
    return x0;
}


