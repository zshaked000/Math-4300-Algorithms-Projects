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
//Check if a user Enters the same point twcie
Point *Points;
Point *temp = new Point[1];
int input1 = 0;
int input2 = 0;
int n = 0;
int i = 0;
while(true){
  cout << "i: " << i << endl;
  n++;
  temp = new Point[n];
  cout << "Enter number: ";
  cin >> input1;
  if(input1 < 0){
    break;
  }
  cout << "Enter number: ";
  cin >> input2;
  if(input2 < 0){
    break;
  }
  Point p(input1,input2);
  temp[i] = p;
  i++;
  if(i > 1){
  delete[] Points;
}
  Points = temp;
}

cout << "Points entered: " << endl;
for(int j = 0; j < i; ++j){
  cout << "j: " << j << endl;
  cout << "( " << Points[j].getX() << " , "  << Points[j].getY() << " )" << "\n";
}
cout << "Program done" <<endl;
  return 0;
}
