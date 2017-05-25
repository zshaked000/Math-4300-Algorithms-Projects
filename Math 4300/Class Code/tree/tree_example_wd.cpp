// tree_example_wd.cpp
// compile with
// c++ -o t_e_wd tree_example_wd.cpp -std=c++11
// execute with
// ./t_e_wd
//
// This code contains the function that deletes a node from the tree.
//
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
void insert(TNode*& root, const int& b,const int&c=1){
  Frac fr(b,c);
  insert(root,fr);
}
void deleteNode(TNode*& root){
  if(root!=nullptr){
    if(root->lChild!=nullptr){
      TNode *helper=root->lChild;
      if(helper->rChild!=nullptr){
        TNode *h2=helper->rChild;
        while(h2->rChild!=nullptr){
          helper=helper->rChild;
          h2=h2->rChild;
        }
        root->value=h2->value;
        if(h2->lChild==nullptr){
          delete h2;
          helper->rChild=nullptr;
        }
        else{
          deleteNode(h2);
        }
      }
      else{
        root->value=helper->value;
        if(helper->lChild==nullptr){

          delete helper;
          root->lChild=nullptr;
        }
        else{
          deleteNode(helper);
        }
      }

    }
    else{
      if(root->rChild!=nullptr){
        TNode *helper=root->rChild;
        if(helper->lChild!=nullptr){
          TNode *h2=helper->lChild;
          while(h2->lChild!=nullptr){
            helper=helper->lChild;
            h2=h2->lChild;
          }
          root->value=h2->value;
          if(h2->rChild==nullptr){
            delete h2;
            helper->lChild=nullptr;
          }
          else{
            deleteNode(h2);
          }
        }
        else{
          root->value=helper->value;
          if(helper->rChild==nullptr){

            delete helper;
            root->rChild=nullptr;
          }
          else{
            deleteNode(helper);
          }
        }




      }
      else{
        delete root;
        root=nullptr;
      }
    }
  }
}

myint deleteValue(TNode *&root, const Frac &fr){
  if(root==nullptr){
    return 0;
  }
  if(fr<root->value){
    return deleteValue(root->lChild,fr);
  }
  if(fr>root->value){
    return deleteValue(root->rChild,fr);
  }
  deleteNode(root);
  return 1;
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
int main(){
  myint a,b,c;
  Frac tempFr;
  TNode *root;
  root=nullptr;
  insert(root,19);
  insert(root,37);
  insert(root,9);
  insert(root,15);
  insert(root,5);
  insert(root,7);
  insert(root,3);
/*
  insert(root,12);
  insert(root,10);
  insert(root,13);
  insert(root,14);*/
  a=1;
  while(a!=0){
    std::cout<<"Insert a ";
    std::cin>>a;
    if(a==1){
      std::cout<<"Insert b and c ";
      std::cin>>b>>c;
      tempFr.setNum(b);tempFr.setDen(c);
      insert(root,tempFr);
    }
    if(a==2){
      printAll(root);
      std::cout<<std::endl;
    }
    if(a==3){
      std::cout<<"Insert b and c ";
      std::cin>>b>>c;
      tempFr.setNum(b);tempFr.setDen(c);
      deleteValue(root,tempFr);
    }
    if(a==5){
      deleteNode(root);
    }
  }

  return 0;
}
