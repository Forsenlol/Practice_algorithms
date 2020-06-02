#include <iostream>
#include <stdlib.h>
#include <string>
 
using namespace std;
 
int main()
{
    string in = "";
    getline(cin, in);
    int len = in.size();
    
    while ((int)in[len - 1] == 32){
        in.pop_back();
        --len;
    }
    
    int quantity_space = 0;
    
    for (int i = 0; i < len; ++i){
        if ((int)in[i] == 32){
            ++quantity_space;
            --len;
        }
        if ((int)in[i] != 32){
            break;
        }
    }
    
    in.erase(0, quantity_space);
    string out = "";
    
    for (int i = 0; i < len; ++i){
        if (i == len - 1){
            out = out + in[i];
            break;
        }
        if ((int)in[i] == 32 && (int)in[i + 1] == 32){
            continue;
        }
        out = out + in[i];
    }
    cout << out;
    
    return 0;
}