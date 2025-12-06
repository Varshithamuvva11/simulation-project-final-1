#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N = 50;     // road length
const int STEPS = 50;

int main() {
    srand(time(NULL));

    vector<char> road(N, '.');

    // Put some cars randomly on road
    for (int i = 0; i < N; i++) {
        if (rand() % 5 == 0)
            road[i] = 'C';
    }

    for (int step = 0; step < STEPS; step++) {
        cout << "Step " << step << ":\n";

        // Print road
        for (int i = 0; i < N; i++)
            cout << road[i];
        cout << "\n";

        vector<char> next = road;

        // Movement rule
        for (int i = N - 1; i >= 0; i--) {
            if (road[i] == 'C') {
                int nextPos = (i + 1) % N; 
                if (road[nextPos] == '.') {
                    next[i] = '.';
                    next[nextPos] = 'C';
                }
            }
        }

        road = next;
    }

    return 0;
}

