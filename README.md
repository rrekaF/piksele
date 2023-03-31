# piksele
#include <iostream>
#include <cmath>
using namespace std;

bool isPali(string num){
    for(int i = 0; i < num.size(); i++){
        if(num[i] != num[num.size()-1-i]){
            return false;
        }
    }
    return true;
}

int conv(int base, string num){
    int res = 0;
    if(base == 10){
        return stoi(num);
    }
    for(int i = num.size()-1; i >= 0; i--){
        if(num[i] >= '0' && num[i]<='9'){
            res += (int(num[i])-'0')*pow(base, num.size()-1-i);
        }
        if(num[i] >= 'A' && num[i] <='Z'){
            res += (int(num[i]-'A'+10)*pow(base, num.size()-1-i));
        }
    }
    return res;
}


int main(){

    int base;
    string num;

    int counter = 0;

    for(int i = 0; i < 300; i++){
        cin >> base;
        cin >> num;
        if(isPali(num)){
            counter++;
        }
        //cout << base << " " << num << " " << conv(base, num) << endl;



    }
    //cout << counter;


/*
    for(int i = 0; i < 255; i++){
        cout << i << ": " << char(i) << endl;
    }
*/

    return 0;
}
