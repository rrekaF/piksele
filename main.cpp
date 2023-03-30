#include <iostream>
#include <cmath>

using namespace std;

int pic[200][320];

bool symRow(int row){
    int i = 0;
    int j = 319;
    while(i != 159 && j != 160){
        if(pic[row][i] != pic[row][j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool isContrasting(int row, int col){
    if(row == 0 && col == 0){
        if(abs(pic[row][col] - pic[row+1][col+1]) > 128){
            return true;
        }
        if(abs(pic[row][col] - pic[row][col+1]) > 128){
            return true;
        }
        if(abs(pic[row][col] - pic[row+1][col]) > 128){
            return true;
        }
    }
    if(row == 0 && col != 0 && col != 3){
        if(abs(pic[row][col] - pic[row+1][col]) > 128){
            return true;
        }
        if(abs(pic[row][col] - pic[row][col-1]) > 128){
            return true;
        }
        if(abs(pic[row][col] - pic[row][col+1]) > 128){
            return true;
        }
    }
}

int main()
{

    int maxi = -1;
    int mini = 256;

    for(int i = 0; i < 200; i ++){
        for(int j = 0; j < 320; j++){
            cin >> pic[i][j];
        }
    }

    for(int i = 0; i < 200; i ++){
        for(int j = 0; j < 320; j++){
            if(pic[i][j] < mini){
                mini = pic[i][j];
            }
            if(pic[i][j] > maxi){
                maxi = pic[i][j];
            }
        }
    }
    cout << mini << " " << maxi << endl;

    int toRemove = 0;
    for(int i = 0; i < 200;i++){
        if(!symRow(i)){
            toRemove++;
        }
    }

    cout << toRemove;

    int contrasting = 0;
    for(int i = 0; i < 200; i++){
        if (isContrasting){
            contrasting++;
        }
    }
    //cout << contrasting << endl;
    int seq = 0;
    int maxSeq = -1;
    for(int i = 0; i < 320; i++){
        //cout << "checking col " << i << " so far " << maxSeq << endl;
        for(int j = 0; j < 199; j++){
            if(pic[j][i] == pic[j+1][i]){
                seq++;
                //cout << pic[i][j] << " = " << pic[i][j+1] << " adding 1, current: " << seq << " comparing " << j <<" " << j+1 << endl;
                if(seq > maxSeq){
                    maxSeq = seq;
                }
            } else {
                 //cout << pic[j][i] << " at " << j << " " << i << " is not " << pic[j+1][i] << " at " <<  j+1 << " " << i << endl;
                seq = 0;
            }
        }
        seq = 0;
    }
    cout << maxSeq << endl;
    return 0;
}
