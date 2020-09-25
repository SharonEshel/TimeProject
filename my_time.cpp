//
// Created by sharon on 9/21/20.
//
#include <sstream>
#include <iostream>
#include <cstdio>
#include "my_time.h"
using namespace std;

//default delimiters
char Time::dayDelimiter='.';
char Time::formatDelimiter=':';

Time::Time(unsigned int myHours,unsigned char myMinutes,unsigned char mySeconds):
        hours(myHours),minutes(myMinutes),seconds(mySeconds){
        if(myHours>100000 || myMinutes>59 || mySeconds>59)
            throw invalid_argument("One or more arguments is invalid");
}

Time::Time(unsigned int mySeconds){
        hours=mySeconds/3600;
        mySeconds-=(hours*3600);
        minutes=mySeconds/60;
        mySeconds-=(minutes*60);
        seconds=mySeconds;
}

Time::~Time() {
}
string nicelyNumberString(string st){
    if(st.length()==1)
        st="0"+st;
    return st;
}

string Time::get_as_str(bool is_using_days) const {
    char s[20];
    if (is_using_days) {
        sprintf(s, "%d%c%02d%c%02d%c%02d\n", (hours / 24), Time::dayDelimiter, hours % 24, Time::formatDelimiter,
                minutes, Time::formatDelimiter,
                seconds);
        return s;
    }
    sprintf(s, "%02d%c%02d%c%02d\n", hours, Time::formatDelimiter, minutes, Time::formatDelimiter, seconds);
    return s;
}

int Time:: get_seconds() const{
    return hours*3600+minutes*60+seconds;
}

Time operator+(const Time& t1,const Time& t2) {
    int seconds= t1.get_seconds()+t2.get_seconds();
    return Time(seconds);
}

 Time operator+(const Time& t1,const unsigned long num) {
    return Time(t1.get_seconds()+num);
}


Time& operator+=( Time& t1,const unsigned long num) {
    t1=Time(t1.get_seconds()+num);
    return t1;
}

bool operator==(const Time& t1,const Time& t) {
    if(t1.get_seconds()==t.get_seconds())
        return true;
    return false;
}

bool operator!=(const Time& t1,const Time& t)  {
    if(t1.get_seconds()!=t.get_seconds())
        return true;
    return false;
}

bool operator<(const Time& t1,const Time& t)  {
    if(t1.get_seconds()<t.get_seconds())
        return true;
    return false;
}

bool operator<=(const Time& t1,const Time& t)  {
    if(t1.get_seconds()<=t.get_seconds())
        return true;
    return false;
}

bool operator>(const Time& t1,const Time& t)  {
    if(t1.get_seconds()>t.get_seconds())
        return true;
    return false;
}

bool operator>=(const Time& t1,const Time& t)  {
    if(t1.get_seconds()>=t.get_seconds())
        return true;
    return false;
}

ostream &operator<<(ostream &out, const Time &t) {
    char s[20];
    sprintf(s, "%d%c%02d%c%02d%c%02d\n", (t.hours / 24), Time::dayDelimiter, t.hours % 24, Time::formatDelimiter,
            t.minutes, Time::formatDelimiter,
            t.seconds);
    out<<s;


    return out;
}

 void Time::enterDelimiters(char day, char format) {
    if(isdigit(day))
        throw invalid_argument("One or more arguments is a digits");
    dayDelimiter=day;
    formatDelimiter=format;
}

void time_reset(Time t) {

}

void time_reset(Time* t) {
    t->hours=0;
    t->minutes=0;
    t->seconds=0;
}


Time operator+(const unsigned long num,const Time& t){
    return Time(t.get_seconds()+num);
}

void print(const Time* t){
    cout<<t->get_as_str(true);
}







