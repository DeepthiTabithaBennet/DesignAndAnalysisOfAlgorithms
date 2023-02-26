#include <iostream>
using namespace std;

/*———————————————————————————————————————————————————————————————————————————*/
void naivePatternSearch(string mainString, string pattern, int array[], int *index){
   int patLen = pattern.size();
   int strLen = mainString.size();

   for(int i = 0; i <= (strLen - patLen); i++){
      for(int j = 0; j < patLen; j++){      //check for each character of pattern if it is matched
         if(mainString[i+j] != pattern[j])
            break;
      }

      if(j == patLen) {     //the pattern is found
         (*index)++;
         array[(*index)] = i;
      }
   }
}

/*———————————————————————————————————————————————————————————————————————————*/
int main(){
   string mainString;
   string pattern;
   
   cout << "Enter the Main String : ";
   cin >> mainString;
   
   cout << "Enter the Pattern String : ";
   cin >> pattern;
   
   int locArray[mainString.size()];
   int index = -1;
   naivePatternSearch(mainString, pattern, locArray, &index);
   
   cout << endl;

   for(int i = 0; i <= index; i++) {
      cout << "Pattern found at position: " << locArray[i] << endl;
   }
}
