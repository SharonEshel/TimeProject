//
// Created by sharon on 9/21/20.
//

#include "msg_printer.h"

MsgPrinter::MsgPrinter(const string myMessage):message(myMessage) {
}

void MsgPrinter::print() {
    cout<<"Message:"<<message<<"\n";
}

MsgPrinter::~MsgPrinter() {
    cout<<"End of MsgPrinter:"<<message<<"\n";
}

string MsgPrinter::getMessage() const {
    return message;
}

void MsgPrinter::setMessage(const string& st) {
    message=st;
}


Timer::Timer(Time t, MsgPrinter* p):target(t),pprinter(p),clock(0) {
}

Timer::~Timer() {
}

MsgPrinterSurrounding::MsgPrinterSurrounding(const string& st,  char* const before_msg,  char* const after_msg) : MsgPrinter(st) {
    before=new char[strlen(before_msg)+1];
    after=new char[strlen(after_msg)+1];
    strcpy(before, before_msg);
    strcpy(after, after_msg);
}

void MsgPrinterSurrounding::print_before() {
    cout<<before<<"\n";
}

void MsgPrinterSurrounding::print_after() {
    cout<<after<<"\n";
}

void MsgPrinterSurrounding::print() {
    print_before();
    MsgPrinter::print();
    print_after();
}

MsgPrinterSurrounding::~MsgPrinterSurrounding() {
    delete [] before;
    delete [] after;
    cout<<"End of MsgPrinterSorrounding:";
    cout<<getMessage()<<"\n";
}

MsgPrinterSurrounding::MsgPrinterSurrounding(const MsgPrinterSurrounding &mps)
        : MsgPrinter(MsgPrinter::getMessage()) {
    before=new char[strlen(mps.before)+1];
    after=new char[strlen(mps.after)+1];
    strcpy(before, mps.before);
    strcpy(after, mps.after);
}

MsgPrinterSurrounding& MsgPrinterSurrounding::operator=(const MsgPrinterSurrounding &mps){
    setMessage(mps.getMessage());
    delete [] before;
    delete [] after;
    before=new char[strlen(mps.before)+1];
    after=new char[strlen(mps.after)+1];
    strcpy(before, mps.before);
    strcpy(after, mps.after);
    return *this;
}


MsgPrinterMultipleSurrounding::MsgPrinterMultipleSurrounding(const string & st,const char ch, char *const before_msg,
        char *const after_msg) :MsgPrinterSurrounding(st,before_msg,after_msg),times(ch){

}

MsgPrinterMultipleSurrounding::MsgPrinterMultipleSurrounding(const MsgPrinterMultipleSurrounding & msg):
    MsgPrinterSurrounding(msg) {
    times=msg.times;
}

void MsgPrinterMultipleSurrounding::set_times(const unsigned char t) {
    times=t;
}

unsigned char MsgPrinterMultipleSurrounding::get_times() const {
    return times;
}

void MsgPrinterMultipleSurrounding::print_before() {
    for(int i=0;i<times;i++)
        MsgPrinterSurrounding::print_before();
}

void MsgPrinterMultipleSurrounding::print_after() {
    for(int i=0;i<times;i++)
        MsgPrinterSurrounding::print_after();
}

MsgPrinterMultipleSurrounding::~MsgPrinterMultipleSurrounding() {
    cout<<"End of MsgPrinterMultipleSurrounding: "<<getMessage()<<"\n";
}


