#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

#include "Item.h"
#include "Cluster.h"

using namespace std;

// Determines numbers to use to initialize clusters
vector<int> randomizeNumbers(int sz){
    int k1,k2,k3;

    vector<int> nums;
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(4);

    k1 = rand() % sz;
    do{
        k2 = rand() % sz;
    } while(k2 == k1);
    do{
        k3 = rand()  % sz;
    } while(k3 == k1 || k3 == k2);
    // nums.push_back(k1);
    // nums.push_back(k2);
    // nums.push_back(k3);
    return nums;
}

// Prints all items in every cluster
void printAllClusters(vector<Cluster> &k){
    for(int i = 0; i < k.size(); i++){
        k[i].printItems();
    }
}

// Resets clusters by using the resetCluser() function which calculates average and clears vectors of assigned items
void resetAllClusters(vector<Cluster> &k){
    for(int i = 0; i < k.size(); i++){
        k[i].resetCluster();
    }
}

// Determines if any of the clusters are empty
bool areClustersEmpty(vector<Cluster> myClusters){
    for(int i =0 ; i < myClusters.size(); i++){
        if(myClusters[i].isEmpty())
            return true;
    }
    return false;
}

// Assings clusters by calculating euclidean distance between point and clusters.
// Finds minimum distance and adds it to cluster
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
        clusters[minID].addItem(items[i]);
    }
}

// Iterates as many K's as requested or until a cluster becomes empty
void iterateKs(vector<Item> myItems, vector<Cluster> &myClusters){
    int k = 4;
    int i = 0;
    do {
        resetAllClusters(myClusters);
        assignClusters(myItems, myClusters);
        i++;
    }while(i < k && !areClustersEmpty(myClusters));
}

// Initializes clusters
vector<Cluster> initClusters(vector<Item> items){
    vector<int> nums = randomizeNumbers((int)items.size());
    vector<Cluster> klusters;
    for(int i = 0 ; i < nums.size(); i++){
        int currN = nums[i];
        klusters.push_back(Cluster(currN, items[currN].getDim1(), items[currN].getDim2()));
    }
    return klusters;
}

// Parses input strings
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
    vector<Cluster> myClusters = initClusters(myItems);
    // assignClusters(myItems, myClusters);
    iterateKs(myItems, myClusters);
    printAllClusters(myClusters);
}