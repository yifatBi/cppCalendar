//
// Created by yifat biezuner on 13/03/2016.
//

#ifndef CALENDAR_H
#define CALENDAR_H

#include <array>
#include "MyDate.h"

class Calendar {
private:
    MyDate* m_dates[30];
public:
    Calendar() ;
    void setDate (int num, MyDate& my_date);
    bool isFree(int num);
    int firstFree();
    void insertDate(MyDate& my_date);
    int oldest();
    int datesNum(MyDate& _mydate);
    void deleteAll();
    void deleteDate(int num);
    void print();
};

#endif //CALENDAR_H
