
using namespace std;

// Determines a generic item that has two dimensions

class Item{
    public: 
        Item(int,double,double);
        int getID();
        double getDim1();
        double getDim2();

    private:
        int id;
        double dim1;
        double dim2;
};

Item::Item(int pId, double pDim1, double pDim2){
    id = pId + 1;
    dim1 = pDim1;
    dim2 = pDim2;
}

int Item::getID(){
    return id;
}

double Item::getDim1(){
    return dim1;
}

double Item::getDim2(){
    return dim2;
}
