#include <vector>

using namespace std;

class Cluster{
    public:
        Cluster(int, double, double);
        int getCID();
        vector<int> getMyItems();
        double getcDim1();
        double getcDim2();
        double calculateDistance(Item);
        void addItem(int);
        void printItems();
        bool isEmpty();
        void resetCluster();

    private:
        int cID;
        double cDim1;
        double cDim2;
        vector<int> myItems;
        void recalculateDimensions();

};

Cluster::Cluster(int pCid, double pCDim1, double pCDim2){
    cID = pCid;
    cDim1 = pCDim1;
    cDim2 = pCDim2;
    // myItems.push_back(0);
}

int Cluster::getCID(){
    return cID;
}

vector<int> Cluster::getMyItems(){
    return myItems;
}

double Cluster::getcDim1(){
    return cDim1;
}

double Cluster::getcDim2(){
    return cDim2;
}

double Cluster::calculateDistance(Item curr){
    return sqrt(pow(curr.getDim1() - cDim1, 2)+pow(curr.getDim2() - cDim2,2));
}

void Cluster::addItem(int curr){
    this->myItems.push_back(curr);
}

void Cluster::printItems(){
    cout << "CLUSTER " << cID << endl; 
    for(int i = 0 ; i < myItems.size(); i++){
        cout << this->myItems[i] << " "; 
    }
    cout << endl;
}

bool Cluster::isEmpty(){
    return myItems.empty();
}

void Cluster::resetCluster(){
    this->myItems.clear();
    recalculateDimensions();
}

void Cluster::recalculateDimensions(){
    double d1 = 0; 
    double d2 = 0;

    for(int i = 0; i < myItems.size(); i++){
        d1 += myItems[i].getDim1();
        d2 += myItems[i].getDim2();
    }

    d1 /= myItems.size();
    d2 /= myItems.size();

    this->cDim1 = d1;
    this->cDim2 = d2;
}
