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
