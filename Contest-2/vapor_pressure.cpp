#include <iostream>
using namespace std;

int main()
{
    int balls, ballons, c;
    cin >> balls >> ballons >> c;
    while(balls > c * ballons){
        balls--;
    }
    double result = (double) balls / ballons;
    cout << result << endl;
    return 0;
}