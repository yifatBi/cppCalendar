/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyDate.h
 * Author: yifatbiezuner
 *
 * Created on 08 March 2016, 17:41
 */

#ifndef MYDATE_H
#define MYDATE_H
#define DAY_SUBMISSION  21
#define MONTH_SUBMISSION  3
#define YEAR_SUBMISSION  2016
#include <iostream>

class MyDate {
private:
    int m_day;
    int m_month;
    int m_year;
    char* m_comment;
    bool isValidFebruary(int day,int month)const{if(month!=2||(day<29)){return 1;}return 0;}
    bool isValidDay(int day,int month);
    bool isValidMonth(int month);
    bool isValidYear(int year);

public:
    MyDate();
    MyDate(const MyDate& orig);
    bool changeMonth(int month);
    void init(){set(DAY_SUBMISSION,MONTH_SUBMISSION,YEAR_SUBMISSION);};
    bool set(const int day,const int month,const int year);
    bool setDay(int day);
    bool setMonth(int month);
    bool setYear(int year);
    bool isBefore(MyDate& dateCompare)const;
    bool delay(int shiftDays);
    bool bringForward(int backDays);
    void print()const{std::cout<<m_day<<"/"<<m_month<<"/"<<m_year<<std::endl;}
    bool changeDate(int day);
    void changeComment(char* str);
    void printComment()const;
    virtual ~MyDate();


};

#endif /* MYDATE_H */

