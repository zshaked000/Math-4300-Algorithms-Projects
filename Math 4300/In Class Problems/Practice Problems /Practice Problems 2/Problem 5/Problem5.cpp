#include<iostream>
#include<string>

using namespace std;

class MyTime{
private:
  int hours;
  int minutes;
  int seconds;
public:
  MyTime();
  MyTime(const int &,const int &, const int &);
  MyTime(const MyTime &);
  int getHour();
  int getSecond();
  int getMinute();
  int setHour(int & );
  int setSecond(int & );
  int setMinute(int & );
  MyTime operator<(const MyTime &);
};
MyTime::MyTime(){
  hours = 0;
  minutes = 0;
  seconds = 0;
}
  MyTime::MyTime( const int &h,const int &m ,const int& s){
    hours = h;
    minutes = m;
    seconds = s;
  }

  MyTime::MyTime(const MyTime & copyFrom){
    hours = copyFrom.hours;
    minutes = copyFrom.minutes;
    seconds = copyFrom.seconds;
  }
  int MyTime::getHour(){
    return hours;
  }
  int MyTime::getSecond(){
    return seconds;
  }
  int MyTime::getMinute(){
    return minutes;
  }
  int MyTime::setHour(int &h){
    hours = h;
  }
  int MyTime::setSecond(int &s){
    seconds = s;
  }
  int MyTime::setMinute(int &m){
    minutes = m;
  }

  MyTime MyTime::operator<(const MyTime & copyFrom){
    if(hours < copyFrom.hours){
    return copyFrom;
    }
    if(minutes < copyFrom.minutes){
      return copyFrom;
    }
    if(seconds < copyFrom.seconds){
      return copyFrom;
    }
  }

// class TrainSchedule{
// // // private:
// //   std::string routeName;
// //   MyTime startingTime;
// //   std::string* stationNames;
// //   int numberOfStations;
// // public:
// //   TrainSchedule();
// //   TrainSchedule(std::string , MyTime ,std::string* ,int);
// //   TrainSchedule::TrainSchedule(const std::string& ,const MyTime &, const std::string*, int)
// //   TrainSchedule(TrainSchedule &);
// //   TrainSchedule(TrainSchedule&, MyTime&);
// //   void operator=(TrainSchedule &);
// //   TrainSchedule(TrainSchedule&&);
// //   void operator=(TrainSchedule&&);
// //   std::string getRouteName();
// //   void setRouteName(std::string & );
// //   void setStartingTime(MyTime );
// //   MyTime getStartingTime();
// //   void setNumberOfStations(int);
// //   int getNumberOfStations();
// //   void setStationName(int n, std::string Name);
// //   std::string getStationName(int n);
// //   ~TrainSchedule();
// // };
// // TrainSchedule::TrainSchedule(){
// //   numberOfStations = 0;
// //   stationNames = NULL;
// //   startingTime = MyTime(0,0,0);
// //   routeName = "";
// // }
// // TrainSchedule::TrainSchedule(std::string rName ="", MyTime newTime = MyTime(0,0,0) ,std::string* stName = new std::string[0], int numStation =0 ){
// //   routeName = rName;
// //   startingTime = newTime;
// //   stationNames = stName;
// //   numStation = numberOfStations;
// // };
// // TrainSchedule::TrainSchedule(const std::string& rName ,const MyTime &tme, const std::string* stName, int numStation){
// //   routeName = rName;
// //   startingTime = tme;
// //   stationNames = new std::string[numberOfStations];
// //   numberOfStations = numStation;
// //  }
// // TrainSchedule::TrainSchedule(TrainSchedule & copyFrom){
// //   routeName = copyFrom.routeName;
// //   startingTime = copyFrom.startingTime;
// //   delete[] stationNames;
// //   stationNames = copyFrom.stationNames;
// //   numberOfStations = copyFrom.numberOfStations;
// // }
// // TrainSchedule::TrainSchedule(TrainSchedule& copyTrain, MyTime& copyTime){
// //   routeName = copyTrain.routeName;
// //   startingTime = copyTime;
// //   delete[] stationNames;
// //   stationNames = copyTrain.stationNames;
// //   numberOfStations = copyTrain.numberOfStations;
// // }
// // void TrainSchedule::operator=(TrainSchedule & copyFrom){
// //   routeName = copyFrom.routeName;
// //   startingTime = copyFrom.startingTime;
// //   delete[] stationNames;
// //   stationNames = copyFrom.stationNames;
// //   numberOfStations = copyFrom.numberOfStations;
// // }
// // TrainSchedule::TrainSchedule(TrainSchedule&& moveFrom){
// //   routeName = moveFrom.routeName;
// //   startingTime = moveFrom.startingTime;
// //   delete[] stationNames;
// //   stationNames = moveFrom.stationNames;
// //   numberOfStations = moveFrom.numberOfStations;
// // }
// // void TrainSchedule::operator=(TrainSchedule&& moveAssignFrom){
// //   routeName = moveAssignFrom.routeName;
// //   startingTime = moveAssignFrom.startingTime;
// //   delete[] stationNames;
// //   stationNames = moveAssignFrom.stationNames;
// //   numberOfStations = moveAssignFrom.numberOfStations;
// // }
// // std::string TrainSchedule::getRouteName(){
// //   return routeName;
// // };
// // void TrainSchedule::setRouteName(std::string &rName){
// //   routeName = rName;
// // }
// // void TrainSchedule::setStartingTime(MyTime tme){
// //   startingTime = tme;
// // }
// // MyTime TrainSchedule::getStartingTime(){
// //   return startingTime;
// // }
// // void TrainSchedule::setNumberOfStations(int number){
// //   numberOfStations = number;
// // }
// // int TrainSchedule::getNumberOfStations(){
// //   return numberOfStations;
// // }
// // void TrainSchedule::setStationName(int n,std::string name){
// //   stationNames[n] = name;
// // }
// // std::string TrainSchedule::getStationName(int n){
// //   return stationNames[n];
// // }
// // TrainSchedule::~TrainSchedule(){
// //   delete[] stationNames;
// // }
// class TrainSchedule{
// private:
//  std::string routeName;
//  MyTime startingTime;
//  std::string * stationNames;
//  int numberOfStations;
// public:
//  TrainSchedule();
//  TrainSchedule(const TrainSchedule &);
//  TrainSchedule(const TrainSchedule &, const MyTime &);
//  void operator=(const TrainSchedule &);
//  TrainSchedule(TrainSchedule &&);
//  void operator=(TrainSchedule &&);
//  void setStartingTime(const MyTime &);
//  void setNumberOfStations(const int &);
//  void setStationName(const int &, const std::string &);
//  int getNumberOfStations() consts;
//  std::string getStationName(const int &) const;
// };
//
// ///////////////////////////////////////////////////
class TrainSchedule{
private:
 std::string routeName;
 MyTime startingTime;
 std::string * stationNames;
 int numberOfStations;
public:
 TrainSchedule(const std::string & = "userDidNotProvideTheName");
 TrainSchedule(const TrainSchedule &);
 TrainSchedule(const TrainSchedule &, const MyTime &);
 void operator=(const TrainSchedule &);
 TrainSchedule(TrainSchedule &&);
 void operator=(TrainSchedule &&);
 void setStartingTime(const MyTime &);
 void setNumberOfStations(const int &);
 void setStationName(const int &, const std::string &);
 int getNumberOfStations() const;
 std::string getStationName(const int &) const;
 MyTime getStartingTime() const;
 std::string getRouteName() const;
 void setStationName(const std::string &);
 void setRouteName(const std::string &);
 virtual ~TrainSchedule();
};
TrainSchedule::TrainSchedule(const std::string & _userInput){
 routeName=_userInput;
 numberOfStations=0;
 stationNames=nullptr;
 startingTime=MyTime(0,0,0);
}
std::string TrainSchedule::getRouteName() const{ return routeName; }
std::string TrainSchedule::getStationName(const int & i) const{
 if(i<numberOfStations){
 return stationNames[i];
 }
 return "Not Found";
}
int TrainSchedule::getNumberOfStations() const{ return numberOfStations; }
MyTime TrainSchedule::getStartingTime() const{ return startingTime; }
void TrainSchedule::setStartingTime(const MyTime &_T){ startingTime=_T; }
void TrainSchedule::setRouteName(const std::string & _s){ routeName=_s; }
void TrainSchedule::setStationName(const int & _i, const std::string & _s){
 if(_i<numberOfStations){
 stationNames[_i]=_s;
 }
}
void TrainSchedule::setNumberOfStations(const int & _n){
 if(_n!=numberOfStations){
 std::string *helper;
 helper=new std::string[_n];
 int min=_n;
 if(min>numberOfStations){
 min=numberOfStations;
 }
 for(int i=0;i<min;++i){
 helper[i]=stationNames[i];
 }
 delete[] stationNames;
 stationNames=helper;
 numberOfStations=_n;
 }
}
TrainSchedule::TrainSchedule(const TrainSchedule & _tS){
 routeName=_tS.routeName;
 numberOfStations=_tS.numberOfStations;
 stationNames=nullptr;
 if(numberOfStations>0){
 stationNames=new std::string[numberOfStations];
 for(int i=0;i<numberOfStations;++i){
 stationNames[i]=(_tS.stationNames)[i];
 }
 }
 startingTime=_tS.startingTime;
}
void TrainSchedule::operator=(const TrainSchedule & _tS){
 if(numberOfStations>0){
 delete[] stationNames;
 }
 routeName=_tS.routeName;
 stationNames=nullptr;
 numberOfStations=_tS.numberOfStations;
 if(numberOfStations>0){
 stationNames=new std::string[numberOfStations];
 for(int i=0;i<numberOfStations;++i){
 stationNames[i]=(_tS.stationNames)[i];
 }
 }
 startingTime=_tS.startingTime;
}
int main(){
  // TrainSchedule oldTS("JFK AirTrain without a driver");
  // oldTS.setStartingTime(MyTime(9,52,15));
  // oldTS.setNumberOfStations(5);
  // oldTS.setStationName(0,"Jamaica Station");
  // oldTS.setStationName(1,"Federal Circle");
  // oldTS.setStationName(2,"Terminal 1");
  // oldTS.setStationName(3,"Terminal 2");
  // oldTS.setStationName(4,"Terminal 5");
  // TrainSchedule newTS(oldTS,MyTime(7,45,23));
  // std::cout<<"The new train has the name ’"<<newTS.getRouteName();
  // std::cout<<"’"<<std::endl;
  // std::cout<<"The new train starts at ";
  // std::cout<<newTS.getStartingTime().getH()<<":";
  // std::cout<<newTS.getStartingTime().getM()<<":";
  // std::cout<<newTS.getStartingTime().getS()<<std::endl;
  // std::cout<<"The stations on the route are:"<<std::endl;
  // for(int i=0;i<newTS.getNumberOfStations();++i){
  //  std::cout<<"’"<<newTS.getStationName(i)<<"’ ";
  // }
  // std::cout<<std::endl;
  return 0;
}
