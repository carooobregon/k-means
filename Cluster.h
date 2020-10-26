#include <vector>

using namespace std;

class Cluster{
    public:
        Cluster(int, double, double);
        int getCID();
        vector<Item> getMyItems();
        double getcDim1();
        double getcDim2();
        double calculateDistance(Item);
        void addItem(Item);
        void printItems();
        bool isEmpty();
        void resetCluster();

    private:
        int cID;
        double cDim1;
        double cDim2;
        vector<Item> myItems;
        void recalculateDimensions();
        bool hasStarted;

};

Cluster::Cluster(int pCid, double pCDim1, double pCDim2){
    cID = pCid;
    cDim1 = pCDim1;
    cDim2 = pCDim2;
    hasStarted = 0;
}

int Cluster::getCID(){
    return cID;
}

vector<Item> Cluster::getMyItems(){
    return myItems;
}

double Cluster::getcDim1(){
    return cDim1;
}

double Cluster::getcDim2(){
    return cDim2;
}

// Calculates euclidean distance between item and cluster point
double Cluster::calculateDistance(Item curr){
    return sqrt(pow(curr.getDim1() - cDim1, 2)+pow(curr.getDim2() - cDim2,2));
}

// Adds new item to cluster
void Cluster::addItem(Item curr){
    this->myItems.push_back(curr);
}

// Prints every item in current cluster
void Cluster::printItems(){
    cout << "CLUSTER " << cID << endl; 
    for(int i = 0 ; i < myItems.size(); i++){
        cout << this->myItems[i].getID() << " "; 
    }
    cout << endl;
}

// Determines if cluster currentlt has items
bool Cluster::isEmpty(){
    return myItems.empty();
}

// Resets cluster by clearing vector and recalculating dimensions
void Cluster::resetCluster(){
    recalculateDimensions();
    this->myItems.clear();
}

// Recalculates dimensions by calculating the average of the current items in the cluster
void Cluster::recalculateDimensions(){
    double d1 = 0; 
    double d2 = 0;

    for(int i = 0; i < myItems.size(); i++){
        d1 += myItems[i].getDim1();
        d2 += myItems[i].getDim2();
    }
    
    d1 /= myItems.size();
    d2 /= myItems.size();
    // cout << "AVG " << d1 << " " << d2 << endl;
    if(hasStarted){
        this->cDim1 = d1;
        this->cDim2 = d2;
    } else
        hasStarted = true;
}