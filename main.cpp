#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <sstream>
#include <fstream>

using namespace std;

vector<vector<int>> construct(const string &f){
    vector<vector<int>> res;
    fstream inputFile;
    inputFile.open(f);
    string line;

    while ( getline( inputFile, line ) ) {
        stringstream ls;
        ls << line;
        int c;
        vector<int> t;
        while(!ls.eof()){
            ls >> c;
            t.push_back(c);
        }
        res.push_back(t);
    }
    return res;
}

bool isPrime(int i){
    for(int j = 2; j <= sqrt(i); j++){
        if(i % j == 0){return false;}
    }
    return i != 1;
}

int explore(vector<vector<int>> pyramid, int row, int col,int sum = 0){
    if(isPrime(pyramid[row][col])) // prime?
        return 0;
    if(row == 0) // top?
        return sum + pyramid[row][col];

    if(col == pyramid[row].size()-1) // if right parent does not exist
        return explore(pyramid,row-1,col-1,sum + pyramid[row][col]);
    else if(col == 0) // if left parent does not exist
        return explore(pyramid,row-1,col,sum + pyramid[row][col]);
    else{
        return max(explore(pyramid,row-1,col-1,sum + pyramid[row][col]),explore(pyramid,row-1,col,sum + pyramid[row][col]));
    }
}

bool explore2(vector<vector<int>> pyramid, int row, int col,int& sum, int& maxsum){
    if(row >= pyramid.size()) // end of the pyramid
        return true;
    if(col >= pyramid[row].size()) // not end of the pyramid
        return false;
    if(isPrime(pyramid[row][col])) // prime?
        return false;

    sum += pyramid[row][col];
    maxsum = max(sum,maxsum);
    int temp = sum;
    bool b1 = explore2(pyramid,row+1,col,sum,maxsum);
    bool b2 = explore2(pyramid,row+1,col+1,temp,maxsum);
    return b1 || b2;
}

int solvePyramid(const string & f) {
    vector<vector<int>> pyramid = construct(f);

    int res = INT_MIN;
    int last = pyramid.size()-1;
    for(int i = 0; i < pyramid[last].size(); i++) {
        int cur = explore(pyramid, last, i);
        res = max(res, cur);
    }
    cout << "Result: " << res;
    return res;
}

int solvePyramid2(const string & f) {
    vector<vector<int>> pyramid = construct(f);

    int res = 0, sum = 0;
    explore2(pyramid,0,0,sum,res);
    cout << "Result: " << res;
    return res;
}

int main() {
    //solvePyramid("file3.txt");
    solvePyramid2("file3.txt");
    return 0;
}


