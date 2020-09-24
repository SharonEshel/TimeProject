//
// Created by sharon on 9/21/20.
//
#ifndef TIMEPROJECT_MY_TIME_H
#define TIMEPROJECT_MY_TIME_H

#include <iostream>
#include <string.h>
using namespace std;

class Time{
private:
    static char dayDelimiter;
    static char formatDelimiter;
    unsigned int hours;
    unsigned char minutes;
    unsigned char seconds;
public:
    /**
     * constructor
     * @param myHours- the number that "hours" should be initialize to
     * @param myMinutes- the number that "minutes" should be initialize to
     * @param mySeconds- the number that "seconds" should be initialize to
     * throw invalid_argument if one or more arguments is invalid
     */
    Time(unsigned int myHours,unsigned char myMinutes,unsigned char mySeconds=0);
    /**
     * constructor
     * @param mySeconds- how many seconds the clock should be initialize to
     */
    Time(unsigned int mySeconds);
    /**
     * destructor
     */
    ~Time();
    /**
    * create a nice string of clock
    * @param is_using_days- if the representation includes days
    * @return- nice string represents the clock
    */
    string get_as_str(bool) const;
    /**
    * calculates how many seconds the clock has
    * @return- number of seconds in clock
    */
    int get_seconds() const;
    /**
    * calculates the sum of two clocks
    * @param t2- the clock is added to the object
    * @return- Time object that includes the sum of two clocks
    */
    Time operator+(const Time& t2)const;
    /**
    * calculates the sum of a clock and num
    * @param num- number that added as seconds to the returned object
    * @return-Time object that includes the sum of a clock and seconds
    */
    Time operator+(const unsigned long num)const;
    /**
    * calculates the sum of a clock and num
    * @param num- number that added as seconds to the object
    * @return- the object after addition of seconds
    */
    Time& operator+=(const unsigned long num);
    /**
    * checks if the object equals to another clock
    * @param t- the object for checking
    * @return- true if the object equals, else returns false
    */
    bool operator==(const Time& t)const;
    /**
    * checks if the object doesn't equal to another clock
    * @param t- the object for checking
    * @return- true if the object doesn't equal, else returns false
    */
    bool operator!=(const Time& t)const;
    /**
    * checks if the object is smaller then another clock
    * @param t- the object for checking
    * @return- true if the object is smaller, else returns false
    */
    bool operator<(const Time& t)const;
    /**
    * checks if the object is smaller or equals to another clock
    * @param t- the object for checking
    * @return- true if the object is smaller or equals, else returns false
    */
    bool operator<=(const Time& t)const;
    /**
    * checks if the object is bigger then another clock
    * @param t- the object for checking
    * @return- true if the object is bigger, else returns false
    */
    bool operator>(const Time& t)const;
    /**
    * checks if the object is bigger or equals to another clock
    * @param t- the object for checking
    * @return- true if the object is bigger or equals, else returns false
    */
    bool operator>=(const Time& t)const;
    /**
    * changes the delimiters in the clock presentation
    * @param day- delimits between the days and the hours
    * @param format- delimits between the days and the hours, minutes and seconds
     * throws invalid_argument if one or more delimiters is a digit
    */
    static void enterDelimiters (char day,char format);

    /**
    * represents the clock (cout function)
    * @param out- the output stream object where characters are inserted
    * @param t- the object to represent
    * @return- the stream to use for printing
    */
    friend ostream& operator<<(ostream& out,const Time& t );
    /**
     * resets the object by zeros
     * @param t- the object to resetting
     */
    friend void time_reset(Time* t);
};

/**
 * calculates the sum of a number and a clock (in this order)
 * @param num- number that added as seconds to the returned object
 * @param t- clock  that added as seconds to the return object
 * @return-Time object that includes the sum of a clock and seconds
 */
Time operator+(const unsigned long,const Time &);
/**
 * prints the clock
 * @param t- the clock that printed
 */
void print(const Time* t);
#endif //TIMEPROJECT_MY_TIME_H
