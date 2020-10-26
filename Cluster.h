
using namespace std;

class Cluster{
    public:
        Cluster(int, double, double);
        int getCID();
        vector<Item> getMyItems();
        double getcDim1();
        double getcDim2();
        double calculateDistance(Item);

    private:
        int cID;
        vector<Item> myItems;
        double cDim1;
        double cDim2;

};

Cluster::Cluster(int pCid, double pCDim1, double pCDim2){
    cID = pCid;
    cDim1 = pCDim1;
    cDim2 = pCDim2;
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

double Cluster::calculateDistance(Item curr){
    return sqrt(pow(curr.getDim1() - cDim1, 2)+pow(curr.getDim2() - cDim2,2));
}