#include "chkFiles.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

bool chkFiles(std::string sf1, std::string sf2){
    std::ifstream f1{sf1}, f2{sf2};
    std::string renglon, r1, r2;
    std::vector<std::string> v1, v2;

    bool iguales = true;

    while (f1) {
        std::getline(f1, renglon);
        std::cout << renglon << "\n";
        v1.push_back(renglon);
    }
    f1.close();

    while (f2) {
        std::getline(f2,renglon);
        std::cout << renglon << "\n";
        v2.push_back(renglon);
    }
    f2.close();

    if (v1.size() == v2.size()) {
        for (auto i=0; i < v1.size(); i++)
        {
            r1 = v1[i];
            r2 = v2[i];

            if (r1 != r2) 
            {
                iguales=false;
            }
        }
    }
    else {
        iguales = false;
    }
    return iguales;
}