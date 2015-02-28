#include <iostream>
#include<vector>

using namespace std;

string s, s_chis, s_sign;
vector<int> chis;
vector<string> sign;
int i, x = 0;

int main() {
    s = "123 + 456 - 789 * 987 / 654 % 321";
    while (x <= s.size()) {
        if (s.find(" ", 0) !=-1) {
            if (int(s[x]) == 32) {
                s_chis = s.substr(0, x);
                i = stoi(s_chis, nullptr, 10);
                chis.push_back(i);
                s.erase(0, x + 1);
                if (!s.empty()) {
                    s_sign = s.substr(0, 1);
                    s.erase(0, 2);
                    sign.push_back(s_sign);
                }
                x = 0;
            }
            x++;
        }
        else
        {
            s_chis = s.substr(0, s.size());
            i = stoi(s_chis, nullptr, 10);
            chis.push_back(i);
            chis.pop_back();
            break;
        }
    }

    for (
            int y = 0;
            y <= chis.

                    size();

            y++) {
        cout << chis[y] << " ";
    }
    cout <<
            endl;
    for (
            int y = 0;
            y <= sign.

                    size();

            y++) {
        cout << sign[y] << " ";
    }

    return 0;
}


