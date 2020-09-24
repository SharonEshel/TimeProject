//
// Created by sharon on 9/21/20.
//
#include <sstream>
#include "my_time.h"

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

string convertIntToStringNicely(int num) {
    stringstream ss;
    ss<<num;
    return nicelyNumberString( ss.str());
}

string convertIntToString(int num) {
    stringstream ss;
    ss<<num;
    return ss.str();
}

string Time::get_as_str(bool is_using_days) const{
    if(is_using_days) {
        return convertIntToString(hours / 24)+ Time::dayDelimiter+convertIntToStringNicely(hours%24) +
        Time::formatDelimiter+convertIntToStringNicely((int)minutes) +Time::formatDelimiter +
        convertIntToStringNicely((int)seconds)+"\n";
        }
    return convertIntToStringNicely(hours) +Time::formatDelimiter+convertIntToStringNicely((int)minutes) +
            Time::formatDelimiter +convertIntToStringNicely((int)seconds)+"\n";
}

int Time:: get_seconds() const{
    return hours*3600+minutes*60+seconds;
}

Time Time:: operator+(const Time& t2)const {
    int seconds= get_seconds()+t2.get_seconds();
    return Time(seconds);
}

Time Time::operator+(const unsigned long num) const{
    return Time(get_seconds()+num);
}


Time& Time::operator+=(const unsigned long num) {
    *this=Time(get_seconds()+num);
    return *this;
}

bool Time::operator==(const Time& t) const {
    if(get_seconds()==t.get_seconds())
        return true;
    return false;
}

bool Time::operator!=(const Time& t) const {
    if(get_seconds()!=t.get_seconds())
        return true;
    return false;
}

bool Time::operator<(const Time& t) const {
    if(get_seconds()<t.get_seconds())
        return true;
    return false;
}

bool Time::operator<=(const Time& t) const {
    if(get_seconds()<=t.get_seconds())
        return true;
    return false;
}

bool Time::operator>(const Time& t) const {
    if(get_seconds()>t.get_seconds())
        return true;
    return false;
}

bool Time::operator>=(const Time& t) const {
    if(get_seconds()>=t.get_seconds())
        return true;
    return false;
}

ostream &operator<<(ostream &out, const Time &t) {

    out<<convertIntToString(t.hours/24)<<Time::dayDelimiter<<convertIntToStringNicely(t.hours%24) <<
        Time::formatDelimiter<<convertIntToStringNicely(t.minutes)<<Time::formatDelimiter<<
        convertIntToStringNicely(t.seconds)<<"\n";
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







