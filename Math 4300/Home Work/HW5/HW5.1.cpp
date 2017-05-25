// tree_example.cpp
// compile with
// c++ -o t_e tree_example.cpp -std=c++11
// execute with
// ./t_e
#include<iostream>

typedef long int myint;
class Frac{
private:
  myint num;
  myint den;
public:
  Frac(const myint& =0, const myint& =1);
  Frac(const Frac&);
  void operator=(const Frac&);
  myint getNum() const;
  myint getDen() const;
  void setNum(const myint &);
  void setDen(const myint &);
  myint operator<(const Frac &) const;
  myint operator>(const Frac &) const;

};
Frac::Frac(const myint& _num, const myint &_den){
  num=_num;
  den=_den;
  if(den==0){num=0;den=1;}
  if(den<0){num*= -1;den*= -1;}
}
Frac::Frac(const Frac& _copyFrom){
  num=_copyFrom.getNum();
  den=_copyFrom.getDen();
}
myint Frac::getNum() const{return num;}
myint Frac::getDen() const{return den;}
void Frac::setNum(const myint & _n){num=_n;}
void Frac::setDen(const myint & _d){
  den=_d;
  if(den==0){num=0;den=1;}
  if(den<0){num*=-1; den*=-1;}
}
void Frac::operator=(const Frac & _copyFrom){
  den=_copyFrom.getDen();
  num=_copyFrom.getNum();
}
myint Frac::operator<(const Frac & _cW) const{
  if( num * _cW.getDen() < den * _cW.getNum()){
    return 1;
  }
  return 0;
}
myint Frac::operator>(const Frac &_cW) const{
  if( num * _cW.getDen() > den * _cW.getNum()){
    return 1;
  }
  return 0;
}

class TNode{
public:
  Frac value;
  TNode * lChild;
  TNode * rChild;
  TNode();
};
TNode::TNode(){
  lChild=nullptr;
  rChild=nullptr;
  std::cout << "New Node intialized" << '\n';
}
void insert(TNode*& root, const Frac& fr){
  if(root==nullptr){
    root= new TNode;
    root->value= fr;
  }
  else{
    if(fr<root->value){insert(root->lChild,fr);}
    if(fr>root->value){insert(root->rChild,fr);}
  }
}
void printAll(TNode * root){
  if(root!=nullptr){
    printAll(root->lChild);
    std::cout<<(root->value).getNum();
    std::cout<<"/";
    std::cout<<(root->value).getDen();
    std::cout<<" ";
    printAll(root->rChild);
  }
}

class SetOfFractions{
private:
TNode* root;
public:
SetOfFractions();
SetOfFractions(const SetOfFractions & );
SetOfFractions(SetOfFractions &&);
void operator=(const SetOfFractions &);
void operator=(SetOfFractions &&);
myint isElement(const Frac &) const;
myint insertInS(const Frac &);
void printAllFractions() const;
~SetOfFractions();
};

SetOfFractions::SetOfFractions(){
  root = new TNode;
}

SetOfFractions::SetOfFractions(const SetOfFractions &copyFrom){
  // while(copyFrom.root != nullptr){
  //   copyFrom->value = root->value;
  //   root->lChild;
  // }
}

int main(){
  // myint a,b,c;
  // Frac tempFr;
  // TNode *root;
  // root=nullptr;
  // a=1;
  // while(a!=0){
  //   std::cout<<"Insert a ";
  //   std::cin>>a;
  //   if(a==1){
  //     std::cout<<"Insert b and c ";
  //     std::cin>>b>>c;
  //     tempFr.setNum(b);tempFr.setDen(c);
  //     insert(root,tempFr);
  //   }
  //   if(a==2){
  //     printAll(root);
  //     std::cout<<std::endl;
  //   }
  // }
  //TNode *root = new TNode;
  SetOfFractions *set = new SetOfFractions;
  return 0;
}
