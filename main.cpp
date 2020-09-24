#include <iostream>
#include "my_time.h"
#include "msg_printer.h"
#include "timers.h"
using namespace std;
int main() {

    /********************* Test of class Time *************************/

    Time* tm=new Time(400800);
    Time tm5(3,4,1);
    cout<<tm->get_as_str(true);
    Time* tm1;
    try {
        tm1 = new Time(765, 20);
    }
    catch (invalid_argument e) {
        cout<<e.what();
        return -1;
    }

    cout<<tm1->get_as_str(true);
    Time c=*tm+*tm1;
    print(&c);
    Time bb=tm5+tm5;
    print(&bb);
    bb=tm5+2;
    print(&bb);
    bb=10+tm5;
    print(&bb);
    bb+=100;
    print(&bb);
    cout<<tm5;

    /********************* Test of class Timer *************************/

    Time tttt(345324);
    MsgPrinter* mp=new MsgPrinter("lalala");
    Timer tm11(tttt,mp);
    tm11.tick();
    tm11.tick("H");
    tm11.tick("min");
    tm11.tick("m",54);
    tm11.tick(3453240);

    //call to destructor for "new" objects
    delete mp;
    delete tm;
    delete tm1;

    /********************* Call run_timer functions *************************/
    run_timer_1();
    run_timer_2();
    run_timer_3();
    run_timer_4();

    return 0;

}
