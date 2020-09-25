//
// Created by sharon on 9/22/20.
//

#include "timers.h"
#include <unistd.h>
#include <list>
//#include <iterator>
#include <iostream>
using namespace std;

void run_timer_1() {
    Time t(1,30);
    MsgPrinter* msp=new MsgPrinter("Hello World!");
    Timer tr(t,msp);
    for(int i=0;i<50;i++) {
        cout<<"Iteration no."<<i<<"\n";
        tr.tick("Min", 2);
    }
    delete msp;
}

void run_timer_2() {
    Time t(7);
    MsgPrinter* msp=new MsgPrinter("Seven Seconds");
    Timer tr(t,msp);
    for(int i=0;i<10;i++) {
        sleep(1);
        cout<<"Iteration no."<<i<<"\n";
        tr.tick();
    }
    delete msp;
}

void run_timer_3(){
    MsgPrinter* printers[3]={new MsgPrinter("This is the message"),
                             new MsgPrinterSurrounding("Surrounded","---Start---","----End----"),
                             new MsgPrinterMultipleSurrounding("Really Surrounded",3,">>>>>>>","<<<<<<<")};
    Time time1(10);
    Timer t1(time1,printers[0]);
    Time time2(15);
    Timer t2(time2,printers[1]);
    Time time3(20);
    Timer t3(time3,printers[1]);
    Time time4(25);
    Timer t4(time4,printers[2]);
    Time time5(30);
    Timer t5(time5,printers[2]);

    for(int i=0;i<40;i++)
    {
        cout<<"Iteration no."<<i<<"\n";
        t1.tick();
        t2.tick();
        t3.tick();
        t4.tick();
        t5.tick();
    }
    for(int i=0;i<3;i++)
    {
        delete printers[i];
    }
}

void run_timer_4(){
    MsgPrinter* printers[]={new MsgPrinter("This is the message"),
                             new MsgPrinterSurrounding("Surrounded","---Start---","----End----"),
                             new MsgPrinterMultipleSurrounding("Really Surrounded",3,">>>>>>>","<<<<<<<")};
    list <Timer> timers_list;
    timers_list.push_front(Timer(Time(10),printers[0]));
    timers_list.push_front(Timer(Time(15),printers[1]));
    timers_list.push_front(Timer(Time(20),printers[1]));
    timers_list.push_front(Timer(Time(25),printers[2]));
    timers_list.push_front(Timer(Time(30),printers[2]));

    list <Timer> :: iterator it;
    for(int i=0;i<80;i++)
    {
        cout<<"Iteration no."<<i<<"\n";
        for(it = timers_list.begin(); it != timers_list.end(); ++it){
            (*it).tick();
        }
    }

    for(int i=0;i<sizeof(printers)/sizeof(MsgPrinter*);i++)
    {
        delete printers[i];
    }


}

