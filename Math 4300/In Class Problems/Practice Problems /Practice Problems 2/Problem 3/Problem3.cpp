// points.cpp
// compile with
// c++ -o points points.cpp -std=c++11
// execute with
// ./points

#include<set>
#include<vector>
#include<iostream>

typedef double mydouble;
typedef long int myint;

class Point{
private:
 mydouble x;
 mydouble y;
public:
 Point(const mydouble & = 0.0, const mydouble & = 0.0);
 Point(const Point &);
 mydouble getX() const;
 mydouble getY() const;
 void setX(const mydouble &);
 void setY(const mydouble &);
 void operator=(const Point &);
 myint operator<(const Point &) const;
 //void operator--(const Point &);
};

Point::Point(const mydouble & _x, const mydouble & _y){
 x=_x;y=_y;
}
Point::Point(const Point & _P){
 x=_P.x;
 y=_P.y;
}
mydouble Point::getX() const{
 return x;
}
mydouble Point::getY() const{
 return y;
}
void Point::setX(const mydouble &_num){
 x=_num;
}
void Point::setY(const mydouble &_num){
 y=_num;
}
void Point::operator=(const Point &_P){
 x=_P.x;y=_P.y;
}
myint Point::operator<(const Point &_P) const{
 if(x<_P.x){
 return 1;
 }
 if(x>_P.x){
 return 0;
 }
 if(y<_P.y){
 return 1;
 }
 return 0;
}

// void Point::operator--(const Point & _P){
//   x -= _P.x;
//   y -= _P.y;
// }

class Polygon{
private:
  //Point *verticies; //vector<Point> verticies; myint mun_verticies
  std::vector<Point> vertices;
  myint numPoints;
public:
  void setVertices(const std::vector<Point> &);
  std::vector<Point> translateToOrgin();
  int operator<(const Polygon &) const; //declare order by points,
};

void Polygon::setVertices(const std::vector<Point> &_vertices){
  verticies = _vertices;
}

std::vector<Point> Polygon::translateToOrgin(){
 Point min = verticies[0];
 std::vector<Point> shiftedVertices;
 int i = 0;
//find smalles Point
for ( i = 0; i < vertices.size(); i++) {
  if(vertices[i] < max){
    min = vertices[i];
  }
}

for(int j = 0; j < vertices.size(); ++j){
shiftedVertices.pushback(vertices[i]);
++i;
}

for(int j = 0; j < i ++j){
  shiftedVertices.pushback(vertices[i]);
  ++i;
}

for(int j = 0; j < shiftedVertices.szie(); ++j){
  shiftedVertices[i].setX(shiftedVertices[i].getX() - shiftedVertices[0].getX());
  shiftedVertices[i].setY(shiftedVertices[i].getY() - shiftedVertices[0].getY());
}
return shiftedVertices;
}

//void translateToOrgin()
//Idea for polygon comaprison
//put point at the origin
int main(){
std::set<Polygon> logos;
Polygon P;
std::vector<Point> temp;
myint numPoints;
while (numPoints > 2) {
  //Collect all the vertices
  //Vector Temp has all the vertices
  P.setVertices(temp);
  logos.insert(P);
  std::cout << "Enter numPoints: ";
  std::cin >> numPoints;
}

std::cout << "Size: " << logos.size() << '\n';
 return 0;
}
