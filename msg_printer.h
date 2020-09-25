//
// Created by sharon on 9/21/20.
//

#ifndef TIMEPROJECT_MSG_PRINTER_H
#define TIMEPROJECT_MSG_PRINTER_H
#include <iostream>
//#include <string.h>
#include "my_time.h"
//using namespace std;

class MsgPrinter{
public:
    /**
    * constructor
    * @param myMessage- string to initialize "message"
    */
    MsgPrinter(const std::string);
    /**
     * destructor
     */
    virtual ~MsgPrinter();
    /**
     * prints message
     */
    virtual void print();
    /**
     * getter for "message"
     * @return- "message" string
     */
    std::string getMessage() const;
    /**
    * setter for "message"
    * @param st- a string to change "message" to
    */
    void setMessage(const std::string&);

private:
    std::string message;
};

class Timer{
public:
    /**
    * constructor
    * @param t- the target of clock
    * @param p- pointer to MsgPrinter for message when the clock ends
    */
    Timer(Time,MsgPrinter*);
    /**
     * destructor
     */
    ~Timer();
    /**
     * increments the clock by one second
     */
    inline void tick(){
        clock+=1;
        if(clock>=target)
            pprinter->print();
    }
    /**
     * increments the clock by some seconds
     * @param num- the seconds to increment
     */
    inline void tick(unsigned int num) {
        clock+=num;
        if(clock>=target)
            pprinter->print();
    }
    /**
     * increments the clock by a minute or a second
     * @param st- if equals to  “M”, “m”, “Min”, “min”, “Minute” or “minute” increments in one minute
     *              if equals to “H”, “h”, “Hour”, “hour” increments in one hour
     *              else throws invalid_argument exception
     */
    inline void tick(std::string st) {
        if(st=="M"||st=="m"||st=="Min"||st=="min"||st=="Minute" ||st=="minute")
            clock+=60;
        else if(st=="H"|| st=="h"|| st=="Hour"|| st=="hour")
            clock+=3600;
        else
            throw std::invalid_argument("The string argument is invalid");
        if(clock>=target)
            pprinter->print();
    }
    /**
     * increments the clock by some minutes or some seconds
     * @param st- if equals to “M”, “m”, “Min”, “min”, “Minute” or “minute” increments in some minute
     *              if equals to “H”, “h”, “Hour”, “hour” increments in some  hour
     * @param num- number of minutes/seconds to increment
     */
    inline void tick(std::string st, unsigned int num) {
        if (st == "M" || st == "m" || st == "Min" || st == "min" || st == "Minute" || st == "minute")
            clock += 60 * num;
        else if (st == "H" || st == "h" || st == "Hour" || st == "hour")
            clock += 3600 * num;
        if (clock >= target)
            pprinter->print();
    }
private:
    Time target;
    Time clock;
    MsgPrinter* pprinter;
};

class MsgPrinterSurrounding: public MsgPrinter{
protected:
    /**
     * prints print_before
     */
    virtual void print_before();
    /**
     * prints print_after
     */
    void print_after();
public:
    /**
    * constructor
    * @param st- the message string
    * @param before_msg- the string to print before message
    * @param after_msg- the string to print after message
    */
    MsgPrinterSurrounding(const std::string& st, char* const before_msg=0,  char* const after_msg=0);
    /**
    * copy constructor
    * @param mps- the object to copy
    */
    MsgPrinterSurrounding( const MsgPrinterSurrounding& mps);
    /**
     * destructor
     */
    virtual ~MsgPrinterSurrounding();
    /**
     * assignment between two objects
     * @return- the object with the changes
     */
    MsgPrinterSurrounding& operator = (const MsgPrinterSurrounding&);
    /**
     * prints the before_msg,message and  after_msg
     */
    virtual void print() override;
private:
    char* before;
    char* after;
};

class MsgPrinterMultipleSurrounding: public MsgPrinterSurrounding{
public:
    /**
    *constructor
    * @param st- the message string
    * @param ch- how many time to print the surrounding messages
     * @param before_msg- the string to print before message
    * @param after_msg- the string to print after message
    */
    MsgPrinterMultipleSurrounding(const std::string& st,const char ch=2,char* const before_msg=0,char* const after_msg=0);
    /**
    * copy constructor
    */
    MsgPrinterMultipleSurrounding(const MsgPrinterMultipleSurrounding &);
    /**
     * destructor
     */
    virtual ~MsgPrinterMultipleSurrounding();
    /**
     * setter for "times"
     * @param t- number that "times" should be equal to
     */
    void set_times(const unsigned char t);
    /**
     * getter for "times"
     * @return the value of "times"
     */
    unsigned char get_times() const;

protected:
    unsigned char times;
    /**
     * prints print_before "times" times
     */
    virtual void print_before() override;
    /**
     * prints print_after "times" times
     */
    void print_after();
};
#endif //TIMEPROJECT_MSG_PRINTER_H
