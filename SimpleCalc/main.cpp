#include <iostream>
#include<vector>


using namespace std;

string s, s_chis, s_sign;
int chis[100];
vector<string> sign;
int i, x = 0, chisn = 0, x2;


void eras(int *array, int begin_pos, int size) // removes one element
{
    for (int xx = begin_pos; xx <= size - 1; xx++) {
        array[xx] = array[xx + 1];
    }
    chisn--;
}


void check_num(string str) ///// check num
{
    for (int x = 0; x < str.size(); x++) {
        if ((int(str[x]) < 48) || (int(str[x]) > 57)) {
            cout << "Incorrect input" << endl;
            exit(0);
        }
    }
}


void check_sign(char str) ///// check sign
{

    if ((int(str) != 42) and (int(str) != 43) and (int(str) != 45) and (int(str) != 47) and (int(str) != 37)) {
        cout << "Incorrect input" << endl;
        exit(0);
    }

}

void exitprog ()
{
    cout << "Incorrect input" << endl;
    exit(0);
}


int main() {
    s = "";

    if (s == "")
    {
        exitprog();
    }
    while (x <= s.size()) {
        if (s.find(" ", 0) != -1) {
            if (int(s[x]) == 32) {
                s_chis = s.substr(0, (unsigned long long int) x);
                check_num(s_chis); ////////////////
                i = stoi(s_chis, nullptr, 10);
                chis[chisn] = i;
                chisn++;
                if ((int(s[x + 1]) < 48) && (int(s[x + 1]) > 57)) {
                    exitprog();
                }
                s.erase(0, (unsigned long long int) (x + 1));
                if (!s.empty()) {
                    s_sign = s.substr(0, 1);
                    check_sign(s_sign[0]);////////////////
                    if (s[1] != ' ')
                    {
                        exitprog();
                    }
                    s.erase(0, 2);
                    sign.push_back(s_sign);
                }
                x = 0;
            }
            x++;
        }
        else {
            s_chis = s.substr(0, s.size());
            check_num(s_chis);////////////////////
            i = stoi(s_chis, nullptr, 10);
            chis[chisn] = i;
            chisn++;
            break;
        }
    }

    for (int x = 0; x < sign.size(); x++) {
        if (sign[x] == "*") {
            chis[x2] = chis[x2] * chis[x2 + 1];
            eras(chis, x2 + 1, chisn);
            x2--;
        }
        else if (sign[x] == "/") {
            if (chis[x2 + 1] == 0) {
                exitprog();
            }

            chis[x2] = chis[x2] / chis[x2 + 1];
            eras(chis, x2 + 1, chisn);
            x2--;
        }
        else if (sign[x] == "%") {
            chis[x2] = chis[x2] % chis[x2 + 1];
            eras(chis, x2 + 1, chisn);
            x2--;
        }
        x2++;
    }
    x2 = 0;
    for (int x = 0; x < chisn; x++) {
        if (sign[x] == "+") {
            chis[0] = chis[0] + chis[1];
            eras(chis, 1, chisn);
        }
        else if (sign[x] == "-") {
            chis[0] = chis[0] - chis[1];
            eras(chis, 1, chisn);
        }
    }

    cout << chis[0];
    return 0;
}


