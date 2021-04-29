#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sol(vector<int> priorities, int location) {
    int answer = 0;

    while (true) {
        int max = priorities[0];
        for (unsigned int j = 1; j < priorities.size(); j++) {
            if (priorities[j] > max) {
                max = priorities[j];
            }
        }
        if (priorities[0] == max) {
            priorities.erase(priorities.begin());
            answer++;
            if (location == 0) {
                break;
            }
            location = location - 1;
        }
        else {
            priorities.push_back(priorities.front());
            priorities.erase(priorities.begin());
            location = location - 1;
            if (location == -1) {
                location = priorities.size() - 1;
            }
        }
    }
    return answer;
}

int main() {
    vector<int> a = { 2,1,3,2 };
    cout << sol(a, 2) << endl;
    return 0;
}