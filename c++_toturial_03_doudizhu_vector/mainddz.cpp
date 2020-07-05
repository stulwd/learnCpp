#include <iostream>
#include "landOwner.h"

using namespace std;

int main(){
    landOwner* ptrLandOwner1 = new landOwner();
    landOwner* ptrLandOwner2 = new landOwner("专业斗地主");
    landOwner* ptrLandOwner3 = new landOwner("周扒皮");
    
    ptrLandOwner1 -> showIofo();
    ptrLandOwner2 -> showIofo();
    ptrLandOwner3 -> showIofo();

    ptrLandOwner1 -> touchCard(20);
    // srand(time(NULL));
    // int array[54] = {0};
    // for(int j = 0; j < 1000; j++){
    //     ptrLandOwner1 -> touchCard(20);
    //     for(int i = 1; i <= 54; i++){
    //        array[i-1] += ptrLandOwner1->test(i);
    //     }
    //     ptrLandOwner1 -> initCards();
    // }
    // int max = array[0], min = array[0];
    // int rich, poor;
    // int rounddif[100];
    // for(int i = 0; i < 54; i++){
    //     if(array[i] > max){
    //         max = array[i];
    //         rich = i;
    //     }
    //     if(array[i] < min){
    //         min = array[i];
    //         poor = i;
    //     }
    //     cout << "array[" << i << "]=" << array[i] << endl;
    // }
    // rounddif[0] = array[rich] - array[poor];
    // int roundNum = 10;
    // for(int round = 1; round <= roundNum; round++){    
    //     for(int j = 0; j < 1000; j++){
    //         ptrLandOwner1 -> touchCard(20);
    //         for(int i = 1; i <= 54; i++){
    //         array[i-1] += ptrLandOwner1->test(i);
    //         }
    //         ptrLandOwner1 -> initCards();
    //     }
    //     rounddif[round] = array[rich] - array[poor];
    // }
    // for(int round = 1; round <= roundNum; round++){
    //     cout << "ROUND1: rich - poor = " << rounddif[round] << endl;
    // }
    delete ptrLandOwner1;
    delete ptrLandOwner2;
    delete ptrLandOwner3;

    /*区间遍历
    int num[] = {1,2,3,4,5,6,7,8,9,10};
    for(auto item : num){
        cout << item << endl;
    }
    */
    return 0;
}