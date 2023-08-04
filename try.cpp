#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector <int>    in;
    int             i = 0;

    in.push_back(2);
    in.push_back(22);
    in.push_back(32);
    in.push_back(12);
    in.push_back(0);

    for (; i < in.size() - 3; i++)
    {}

    in.erase(in.begin()+2);
    i = 0;

    cout << "naber" << endl;
    for (; i < in.size(); i++)
    {
        cout << in[i] << endl;
    }
    return 0;
}
