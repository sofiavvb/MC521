#include <iostream>
#include <string>
#include <cctype>
#include <unordered_set>
using namespace std;

int main()
{
    string s, t;
    bool ok = true;
    unordered_set<char> hash;
    cin >> s >> t;
    //colocar em um hash as letras de t
    for (char c : t) {
        hash.insert(c);
    }

    for (int i = 1; i < s.size(); i++) {
        if (isupper(s[i])){
            char before = s[i-1];
            if (hash.find(before) == hash.end()) {
                ok = false;
                break;
            }
        }
    }
    
    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}