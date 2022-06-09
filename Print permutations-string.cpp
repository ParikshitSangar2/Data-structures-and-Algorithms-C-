#include <iostream>
#include <string>
using namespace std;
void permute(string a, int l, int r)  
{  
    // Base case  
    if (l == r)  
        cout<<a<<endl;  
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
            swap(a[l], a[i]);  //swap
            permute(a, l+1, r);  //permute
            swap(a[l], a[i]);  //backtrack
        }  
    }  
}  
void printPermutations(string input){
    permute(input,0,input.size()-1);
}
int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
