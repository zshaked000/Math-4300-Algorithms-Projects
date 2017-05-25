// HW4.1.cpp : Defines the entry point for the console application.
//
#include <iostream>

class BagOfPoints{
private:
double *sequenceX;
double *sequenceY;
int numPoints;
public:
BagOfPoints(const int & =0);
BagOfPoints(const BagOfPoints &);
BagOfPoints(BagOfPoints &&);
void operator=(const BagOfPoints &);
void operator=(BagOfPoints &&);
~BagOfPoints();
double getX(const int &) const;
double getY(const int &) const;
int getLength() const;
void setTerm(const int &, const double &, const double &);
void setLength(const int &);
};

double BagOfPoints::getX(const int &k) const {
    return sequenceX[k];
}

double BagOfPoints::getY(const int &k) const {
    return sequenceY[k];
}

int BagOfPoints::getLength() const {
    return numPoints;
}

void BagOfPoints::setTerm(const int & i, const double &x, const double &y) {
    sequenceX[i] = x;
    sequenceY[i] = y;
}

void BagOfPoints::setLength(const int &n) {
    double *tempy = new double[n];
    double *tempx = new double[n];
    for (int i = 0; i < n; ++i) {
        tempx[i] = sequenceX[i];
        tempy[i] = sequenceY[i];
    }
    delete[] sequenceX;
    delete[] sequenceY;
    sequenceX = tempx;
    sequenceY = tempy;
}

BagOfPoints::BagOfPoints(const int& k) {
    numPoints = k;
    sequenceX = new double[numPoints];
    sequenceY = new double[numPoints];
}
BagOfPoints::BagOfPoints(const BagOfPoints &copyFrom) {
    //delete[] sequenceX, delete[] sequenceY;
    numPoints = copyFrom.numPoints;
    sequenceX = new double[numPoints];
    sequenceY = new double[numPoints];
    for (int i = 0; i < numPoints; ++i) {
        sequenceX[i] = copyFrom.sequenceX[i];
        sequenceY[i] = copyFrom.sequenceY[i];
    }
}
void BagOfPoints::operator=(const BagOfPoints &copyFrom) {
    delete[] sequenceX, delete[] sequenceY;
    numPoints = copyFrom.numPoints;
    sequenceX = new double[numPoints];
    sequenceY = new double[numPoints];
    for (int i = 0; i < numPoints; ++i) {
        sequenceX[i] = copyFrom.sequenceX[i];
        sequenceY[i] = copyFrom.sequenceY[i];
    }
}

BagOfPoints::BagOfPoints(BagOfPoints&& moveFrom) {
    sequenceX = moveFrom.sequenceX;
    sequenceY = moveFrom.sequenceY;
    moveFrom.sequenceX = nullptr;
    moveFrom.sequenceY = nullptr;
}

void BagOfPoints::operator=(BagOfPoints&& moveFrom) {
    sequenceX = moveFrom.sequenceX;
    sequenceY = moveFrom.sequenceY;
    moveFrom.sequenceX = nullptr;
    moveFrom.sequenceY = nullptr;
}

BagOfPoints::~BagOfPoints() {
    delete[] sequenceX;
    delete[] sequenceY;
}

BagOfPoints reflectPoints(const BagOfPoints& bag) {
    BagOfPoints reflectedBag = bag;
    for (int i = 0; i < bag.getLength(); ++i) {
        double newX = -1 * bag.getX(i), newY = -1 * bag.getY(i);
        reflectedBag.setTerm(i, newX, newY);
    }
    return reflectedBag;
}

int main()
{
    std::cout << "Enter the number of points you wish to have in your bag: ";
    int n; std::cin >> n;
    std::cout << "Enter points: " << std::endl;
    BagOfPoints bP(n);
    double x, y;
    for (int i = 0; i < n; ++i) {
        std::cout << "(x,y): ";
        std::cin >> x >> y;
        bP.setTerm(i,x,y);
    }
    return 0;
}
