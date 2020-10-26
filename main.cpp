#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

#include "Item.h"
#include "Cluster.h"

using namespace std;

void assignClusters(vector<Item> items, vector<Cluster> &clusters){
    double minDistance = 100000;
    int minID = 1000 ;
    for(int i = 0 ; i < items.size(); i++){
        for(int j  = 0 ; j < clusters.size(); j++){
            double k = clusters[j].calculateDistance(items[i]);
            if(k < minDistance){
                minDistance = min(k, minDistance);
                minID = j;
            }
        }
        minDistance = 10000;
        clusters[minID].addItem(items[i].getID());
    }
}

vector<Cluster> initClusters(vector<Item> items){
    int k1, k2, k3;
    k1 = 0;
    k2 = 2;
    k3 = 4;
    vector<Cluster> klusters;
    // int sz = (int)items.size();
    // k1 = rand() % sz;
    // do{
    //     k2 = rand() % sz;
    // } while(k2 == k1);
    // do{
    //     k3 = rand()  % sz;
    // } while(k3 == k1 || k3 == k2);
    klusters.push_back(Cluster(k1, items[k1].getDim1(), items[k1].getDim2()));
    klusters.push_back(Cluster(k2, items[k2].getDim1(), items[k2].getDim2()));
    klusters.push_back(Cluster(k3, items[k3].getDim1(), items[k3].getDim2()));

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

void printAllClusters(vector<Cluster> k){
    for(int i = 0; i < k.size(); i++){
        k[i].printItems();
    }
}

int main(){
    ifstream myData;
    string filename;
    cout << "Enter file name " << endl;
    cin >> filename;
    myData.open(filename);
    vector<Item> myItems = readDataSet(myData);
    vector<Cluster> myClusters = initClusters(myItems);
    assignClusters(myItems, myClusters);
    printAllClusters(myClusters);
}