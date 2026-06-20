#include <iostream>
#include <string>
#include <unordered_map>
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main()
{_
    string first, second;
    char letter;
    int occurencesOnSec = 0, balance = 0, occurencesOnFirst = 0, diff = 0;
    unordered_map<char, int> freqF, freqS;
    cin >> first >> second;
    freqS['*'] = 0;
    for (int i = 0; i < first.length(); i++){
        freqF[first[i]]++;
        freqS[second[i]]++;
    }

    for (const auto& pair : freqS) {
        //para cada letra na segunda string
        //se a letra existe na primeira, vejo quantas vezes ela aparece na primeira e na segunda
        //se for uma quantidade igual, ok. 
        //se for uma quantidade maior na primeira, preciso usar os '*' para compensar a diferença.
        //se nao tiver '*' suficiente, N.
        //se tiver uma quantidade maior na segunda, N.
        letter = pair.first;
        occurencesOnSec = pair.second;

        if (letter != '*') {

            if (freqF.find(letter) != freqF.end()) {
                occurencesOnFirst = freqF[letter];
            } else {
                cout << "N" << endl;
                return 0;
            }

            if(occurencesOnFirst == occurencesOnSec){
                continue;
            }else if(occurencesOnFirst > occurencesOnSec){
                diff = occurencesOnFirst - occurencesOnSec;
                if(diff <= freqS['*']){
                    freqS['*']--;
                    continue;
                }else{
                    cout << "N" << endl;
                    return 0;
                }
            }else if(occurencesOnFirst < occurencesOnSec){
                cout << "N" << endl;
                return 0;
            }
        }
    }
    cout << "A" << endl;
    return 0;
}