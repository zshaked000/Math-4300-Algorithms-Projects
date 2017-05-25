#include <iostream>
#include <cmath>

using namespace std;

typedef double mydouble;

class Point{
private:
 mydouble x;
 mydouble y;
public:
 Point(const mydouble & = 0.0, const mydouble & = 0.0);
 Point(const Point & );
 mydouble getX() const;
 mydouble getY() const;
 void setX(const mydouble &);
 void setY(const mydouble &);
 void operator=(const Point & );
 mydouble distanceFrom(const Point &) const;
};

Point::Point(const mydouble &xValue , const mydouble &yValue){
x = xValue;
y = yValue;
};

Point::Point(const Point &copyFrom ){
  x = copyFrom.x;
  y = copyFrom.y;
}

mydouble Point::getX() const{
  return x;
};
mydouble Point::getY() const{
  return y;
};
void Point::setX(const mydouble &X){
  x= X;
};
void Point::setY(const mydouble &Y){
  y = Y;
};
void Point::operator=(const Point & copyFrom){
  x = copyFrom.x;
  y = copyFrom.y;
};

mydouble Point::distanceFrom(const Point&p) const{
mydouble xdist = x - p.x;
mydouble ydist = y - p.y;
mydouble sum = pow(xdist,2) + pow(ydist,2);
mydouble dist = sqrt(sum);
return dist;
}

int main(){
  cout << "Enter point 1: ";
  int x; int y;
  cin >> x >> y;
  Point p1(x,y);
  cout << "Enter point 2: ";
  cin >> x >> y;
  Point p2(x,y);
  cout << "dist: " << p1.distanceFrom(p2) << endl;
  cout << "Program done";
  return 0;
}
