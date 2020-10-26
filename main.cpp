#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

#include "Item.h"
#include "Cluster.h"

using namespace std;

vector<int> assignClusters(vector<Item> items){
    int k1, k2, k3;
    vector<int> klusters;
    int sz = (int)items.size();
    k1 = rand() % sz;
    do{
        k2 = rand() % sz;
    } while(k2 == k1);
    do{
        k3 = rand()  % sz;
    } while(k3 == k1 || k3 == k2);
    klusters.push_back(k1);
    klusters.push_back(k2);
    klusters.push_back(k3);
    return klusters;
}

Item parseString(string currLine, int n){
    size_t found = currLine.find(',');
    double dim1 = stod(currLine.substr(0, found));
    double dim2 = stod(currLine.substr(found+1, currLine.length()-1));
    return Item(n, dim1, dim2);
}

vector<Item> readDataSet(istream& dataset){
    string currLine;
    vector<Item> allItems;
    int n = 0;
    while(dataset >> currLine){
        Item myItem = parseString(currLine, n);
        allItems.push_back(myItem);
        n++;
    }
    return allItems;
}

int main(){
    ifstream myData;
    string filename;
    cout << "Enter file name " << endl;
    cin >> filename;
    myData.open(filename);
    vector<Item> myItems = readDataSet(myData);
    vector<int> myClusters = assignClusters(myItems);
    cout << myClusters[0] << " " << myClusters[1] << " " << myClusters[2] << endl; 
}