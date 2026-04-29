#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include <fstream>
#include <string>
#include <utility>
using namespace std;

class SystemConfig {
public:

    /* ===== SAVE CONFIG ===== */
    static void save(string state, string pricing) {
        ofstream file("config.csv");

        file << state << "," << pricing;

        file.close();
    }

    /* ===== LOAD CONFIG ===== */
    static pair<string, string> load() {
        ifstream file("config.csv");

        string state = "Active";
        string pricing = "Standard";

        if (file.good()) {
            getline(file, state, ',');
            getline(file, pricing);
        }

        file.close();

        return {state, pricing};
    }
};

#endif