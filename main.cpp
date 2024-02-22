#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>

using namespace std;

struct  Solution {
    int coins = numeric_limits<int>::max();
    unordered_map<int, int> monedas;
};

Solution dynamicProgramming(int C, Solution sol, vector<int> denominaciones) {
    vector<Solution> M;
    int num, denomElegida;
    sol.coins = 0;
    M.push_back(sol);
    for (int cantidad = 1; cantidad <= C; cantidad++) {
        M.push_back(Solution());
        M[cantidad].coins = numeric_limits<int>::max();
        for (int i = 0; i < denominaciones.size(); i++) {
            if (cantidad >= denominaciones[i]) {
                num = M[cantidad-denominaciones[i]].coins + 1;
                if (num < M[cantidad].coins) {
                    M[cantidad].coins = num;
                    denomElegida = denominaciones[i];
                }
            }
        }
        //entender la denominacion finla elegida, agregarla a M[cantidad].monedas[denominacionElegida]
        M[cantidad].monedas = M[cantidad - denomElegida].monedas;
        M[cantidad].monedas[denomElegida]++;

    }
    return M[C];
};

int main() {
    Solution sol;
    vector<int> denominaciones;
    int numInputs, temp, P, Q, C;

    cin >> numInputs;
    for (int i = 0; i < numInputs; i++) {
        cin >> temp;
        denominaciones.push_back(temp);
        sol.monedas[temp] = 0;
    }
    
    
    cin >> P >> Q;
    C = Q - P;
    sol = dynamicProgramming(C, sol, denominaciones);
    for (const auto& pair: sol.monedas) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    return 0;
}