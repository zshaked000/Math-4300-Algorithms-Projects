// logos.cpp
// compile with
// c++ -o logos logos.cpp -std=c++11
// execute with
// ./logos

#include<set>
#include<vector>
#include<iostream>
#include"points.cpp"

typedef double mydouble;
typedef long int myint;
class Logo{
private:
 std::vector vertices;
public:
 Logo();
 Logo(const std::vector &);
 Logo(const Logo &);
 std::vector getVertices() const;
 void setVertices(const std::vector &);
 void operator=(const Logo &);
 std::vector moveToTheOrigin() const;
 myint operator<(const Logo &) const;
};
Logo::Logo(){
 vertices.resize(3);
 vertices[0]=Point(0.0,0.0);
 vertices[1]=Point(1.0,0.0);
 vertices[2]=Point(0.0,1.0);
}
Logo::Logo(const std::vector &_v){
 vertices=_v;
}
Logo::Logo(const Logo &_L){
 vertices=_L.vertices;
}
std::vector Logo::getVertices() const{
 return vertices;
}
void Logo::setVertices(const std::vector & _v){
 vertices=_v;
}
void Logo::operator=(const Logo & _L){
 vertices=_L.vertices;
}
std::vector Logo::moveToTheOrigin() const{
 std::vector movedToOrigin=vertices;
 myint len=vertices.size(),i,minI,j;
 myint orientation=1;
 Point minP,cP;
 for(i=0;i<len;++i){
 cP=vertices[i];
 if((i==0)||(cP<minP)){
 minP=cP;
 minI=i;
 }
 }
 // We have now determined that
 // vertices[minI] will be placed at origin.
 // We now want to make sure that the drawing is from the origin
 // towards the smaller neighbor

 Point prevNeighbor, nextNeighbor;
 if(minI>0){
 prevNeighbor=vertices[minI-1];
 }
 else{
 prevNeighbor=vertices[len-1];
 }
 if(minI<len-1){
 nextNeighbor=vertices[minI+1];
 }
 else{
 nextNeighbor=vertices[0];
 }
 if(nextNeighbor orientation=-1;
 }

 for(i=0;i<len;++i){
 j=(minI+ orientation * i + len)%len;
 cP=vertices[j];
 cP.setX(cP.getX()-minP.getX());
 cP.setY(cP.getY()-minP.getY());
 movedToOrigin[i]=cP;
 }
 return movedToOrigin;
}
myint Logo::operator<(const Logo &_L) const{
 std::vector myTranslation=moveToTheOrigin();
 std::vector itsTranslation=_L.moveToTheOrigin();
 myint myLen=myTranslation.size();
 myint itsLen=itsTranslation.size();
 if(myLen<itsLen){
 return 1;
 }
 if(myLen>itsLen){
 return 0;
 }
 myint i=1, itsOver=0;
 while((itsOver==0)&&(i<myLen)){
 if(myTranslation[i]<itsTranslation[i]){
 itsOver=1;
 }
 if(itsTranslation[i]<myTranslation[i]){
 itsOver=2;
 }
 ++i;
 }
 if(itsOver==2){
 itsOver=0;
 }
 return itsOver;
}
Logo getLogoFromInput(const myint & numPoints){
 std::vector pointsInLogo;
 pointsInLogo.clear();
 mydouble x=0.0,y=0.0;
 pointsInLogo.resize(numPoints);
 for(myint i=0;i<numPoints;++i){
 std::cin>>x>>y;
 pointsInLogo[i]=Point(x,y);
 }
 return Logo(pointsInLogo);
}

int main(){
 myint n;
 myint writeMessages=1;
 std::cout<<"Do you want messages to be displayed as you are entering the input? [1=Yes, 0=No] ";
 std::cin>>writeMessages;
 std::set<Logo> setOfLogos;
 n=3;
 while(n>2){
 if(writeMessages==1){
 std::cout<<"How many vertices does the polygon have?";
 std::cout<<std::endl<<"An integer <= 2 will terminate the input. ";
 }
 std::cin>>n;
 if(n>=2){
 if(writeMessages==1){
 std::cout<<"Insert "<<n<<" pairs of real numbers ";
 std::cout<<"that represent the vertices of the polygon."<<std::endl;
 }
 setOfLogos.insert(getLogoFromInput(n));
 }
 }
 myint numLogos=setOfLogos.size();
 if(writeMessages==1){
 std::cout<<"The total number of logos that you provided is ";
 }
 std::cout<<numLogos;
 if(writeMessages==1){
 std::cout<<".";
 }
 std::cout<<std::endl;
 return 0;
}
