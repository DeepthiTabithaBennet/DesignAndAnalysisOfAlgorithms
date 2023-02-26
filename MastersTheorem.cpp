#include<bits/stdc++.h>
using namespace std;

void Timecalc(float a, float b, float k, float p){
    
    if (a > pow(b,k)){
        cout << "T(n) = theta(n^" << log2(a)/log2(b) << ")\n";
    }
    
    else if(a == pow(b,k)){
        if(p > -1)
            cout << "T(n) = theta(n^" << round(log2(a)/log2(b)) << " * log^" << (p + 1) << " n)\n";
        else if(p == -1)
            cout << "T(n) = theta(n^" << round(log2(a)/log2(b)) << " * loglogn)\n";
        else
            cout << "T(n) = theta(n^" << round(log2(a)/log2(b)) << ")\n";
    }
    
    else if(a < pow(b,k)){
        if(p >= 0)
            cout << "T(n) = theta(n^" << k << " log^" << p << "n)\n";
        else
            cout << "T(n) = O(n^" << k << endl;
    }  
}

int main(){
    float a, b, k, p;
    char sign;
    
    cout << "Enter the value of a : ";
    cin >> a;
    
    cout << "Enter the value of b : ";
    cin >> b;
    
    cout << "Enter the value of k : ";
    cin >> k;
    
    cout << "Enter the value of p : ";
    cin >> p;
    
    cout << "Enter the sign : ";
    cin >> sign;

    if(a >= 1 && b > 1 && k >= 0 && sign == '+'){
        cout << "\nRecurrence Relation is\n";
        cout << "T(n) = " << a << "T(n/" << b << ") " << sign << " theta (n^" << k << " log^" << p << "n)\n";
        Timecalc(a, b, k, p);
    }

    else{
        cout << "\nCannot solve the recurrence relation using Master's theorem\n";
    }
    return 0;
}
