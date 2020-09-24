//
// Created by sharon on 9/22/20.
//

#ifndef TIMEPROJECT_TIMERS_H
#define TIMEPROJECT_TIMERS_H
#include "msg_printer.h"
/**
 * creates a timer to 01::30::00 and decreases it by 2 minutes 50 times.
 * In each decrease prints the iteration
 */
void run_timer_1();
/**
 * creates a timer to 00::00::07 and decreases it by one second 10 times.
 * In each decrease prints the iteration
 */
void run_timer_2();
/**
 * creates 5 timers to 10,15,20,25 and 30 seconds and decreases them by one second 40 times.
 * In each decrease prints the iteration
 */
void run_timer_3();
/**
 * creates 5 timers to 10,15,20,25 and 30 seconds in list<> and decreases them by one second 80 times.
 * In each decrease prints the iteration
 */
void run_timer_4();
#endif //TIMEPROJECT_TIMERS_H
