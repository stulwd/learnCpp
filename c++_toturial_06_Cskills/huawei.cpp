// #include <iostream>
// using namespace std;

// int main(){
//     char str[1000];
//     cin.get(str, 1000);
//     //0-25: a-z 
//     //26-51:A-Z 
//     //52-61:0-9 
//     //62   :spacebar
//     int sta[63] = {0};    //index of chr
//     char chr[63];
//     for(int i = 0; i < 63; i++){
//         if(i < 26){
//             chr[i] = 'a' + i;
//         }else if(26 <= i && i < 52){
//             chr[i] = 'A' + (i-26);
//         }else if(52 <= i && i < 62){
//             chr[i] = '0' + (i-52);
//         }else if(i == 62){
//             chr[i] = ' ';
//         }
//     }
//     char *p = str;
//     while(*p != '\0'){
//         if('a' <= *p && *p <= 'z'){
//             sta[(int)(*p-'a')] ++;
//         }else if('A' <= *p && *p <= 'Z'){
//             sta[26 + (int)(*p-'A')] ++;
//         }else if('0' <= *p && *p <= '9'){
//             sta[52 + (int)(*p-'0')] ++;
//         }else if(*p == ' '){
//             sta[62] ++;
//         }
//         p++;
//     };
    
//     //sort
//     int tempInt; char tempChar;
//     for(int i = 62; i >= 1; i--){
//         for(int j = 0; j < i; j++){
//             if(sta[j] < sta[j+1]){
//                 tempInt = sta[j];
//                 sta[j] = sta[j+1];
//                 sta[j+1] = tempInt;
                
//                 tempChar = chr[j];
//                 chr[j] = chr[j+1];
//                 chr[j+1] = tempChar;
//             }else if(sta[j] == sta[j+1]){
//                 if(chr[j] > chr[j+1]){
//                     tempInt = sta[j];
//                     sta[j] = sta[j+1];
//                     sta[j+1] = tempInt;
                    
//                     tempChar = chr[j];
//                     chr[j] = chr[j+1];
//                     chr[j+1] = tempChar;
//                 }
//             }
//         }
//     }
//     for(int i = 0; i < 63; i++){
//         if(sta[i] == 0) break;
//         cout << chr[i];
//     }
//     cout << endl;
// }



#include <iostream>
using namespace std;

int main(){
    int count;
    cin >> count;
    int array[1000];
    for(int i = 0; i < count; i++){
        cin >> *(array+i);
    }
    int flag;
    cin >> flag;
    
    int tempInt;
    for(int i = count-1; i >= 1; i--){
        for(int j = 0; j < i; j++){
            if(flag){
                if(array[j] < array[j+1]){
                tempInt = array[j];
                array[j] = array[j+1];
                array[j+1] = tempInt;
                }
            }else{
                if(array[j] > array[j+1]){
                tempInt = array[j];
                array[j] = array[j+1];
                array[j+1] = tempInt;
                }
            }
        }
    }
    for(int i = 0; i < count; i++){
        cout << array[i] << ' ';
    }    
}