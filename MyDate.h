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
#include <iostream>

class MyDate {
private:
    int m_day;
    int m_month;
    int m_year;
    char* comment;
    bool isValidFebruary(int day,int month)const{if(month!=2||(day<29)){return 1;}return 0;}
    bool isValidDay(int day,int month);
    bool isValidMonth(int month);
    bool isValidYear(int year);

public:
    MyDate();
    MyDate(const MyDate& orig);
    bool changeMonth(int month);
    void init(int day,int month,int year){m_day=day,m_month=month,m_year=year;}
    bool set(int day,int month,int year);
    bool setDay(int day);
    bool setMonth(int month);
    bool setYear(int year);
    bool isBefore(MyDate& dateCompare)const;
    void delay(int shiftDays);
    void bringForward(int backDays);
    void print()const{std::cout<<m_day<<"/"<<m_month<<"/"<<m_year<<std::endl;}
    void changeDate(int day);
    void changeComment(char* str);
    void printComment()const{ std::cout<<comment<<std::endl;};
    virtual ~MyDate();


};

#endif /* MYDATE_H */

