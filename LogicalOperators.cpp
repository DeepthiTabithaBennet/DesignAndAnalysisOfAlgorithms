#include <iostream>
using namespace std;  

int main(){
    int x;
    int y;
    int i;
   
    cout << "X" << " | " << "Y" << " | " << "OR" << " | " << "AND" << " | " << "NOTX" << " | " << "NOTY" << " | " << "NOR" << " | " << "NAND" << " | " << "XOR" << " | " << "XNOR";
    for (i = 0; i <= 3; i++) {
        x = i / 2;
        y = i % 2;
        cout << endl << x << " | " << y << " | " << (x || y) << "  | " << (x && y) << "   | " << !x << "    | " << !y << "    | " << !(x || y) << "   | " << !(x && y) << "    | " << (x ^ y) << "   | " << !(x ^ y);        
    }
    cout << endl;
}
