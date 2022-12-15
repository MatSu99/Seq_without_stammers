#include <iterator>
#include <iostream>
#include <vector>

// OI X
// Task 1, Phase 1 Sequences without Stammers
// 14.02.2022
using namespace std;




int main()
{
    std::ios_base::sync_with_stdio(false);
    int n;

    cin >> n; // Input, number of letters in output

    // case 1
    if(n==1)
    {
        cout << n << "\n";
        cout << "a";
        return 0;
    }
    // case 2
    if(n == 2)
    {
        cout << n << "\n";
        cout << "ab";
        return 0;
    }
    //case 3
    if(n == 3)
    {
        cout << n-1 << "\n";
        cout << "aba";
        return 0;
    }
    // case 4

    //Thue-Morse sequence generator
    vector<bool> TM_seq;
    TM_seq.push_back(0);
    int length=1;
    bool gate_1 = true;

    do{
        for(int i = 0; i < length;i++)
        {
            TM_seq.push_back( TM_seq[i] ? 0 : 1);
            if(TM_seq.size()>n+1)
            {
                gate_1 = false;
                break;
            }
        }
            length = TM_seq.size();

    }while(gate_1);


    // Creating D series
    bool s_1;
    bool s_2;

    vector<char> beta;

    for(int i = 0; i<n; i++)
    {
        s_1 = TM_seq[i];
        s_2 = TM_seq[i+1];
        if(s_1 == false && s_2 == false)
            beta.push_back('b');
        else if(s_1 == true && s_2 == true)
            beta.push_back('b');
        else if(s_1 == false && s_2 == true)
            beta.push_back('a');
        else if(s_1 == true && s_2 == false)
            beta.push_back('c');
    }


cout << "3\n";
        for(int i = 0; i<beta.size(); i++)
        {
            cout << beta[i];
        }



    return 0;
}
