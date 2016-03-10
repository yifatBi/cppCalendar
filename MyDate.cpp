/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyDate.cpp
 * Author: yifatbiezuner
 * 
 * Created on 08 March 2016, 17:41
 */

#include "MyDate.h"
#include <iostream>
#include <stdlib.h> 

MyDate::MyDate() {
}

MyDate::MyDate(const MyDate& orig) {
}

MyDate::~MyDate() {
}

bool MyDate::isValidMonth(int month) {
   if(0<month&&month<13){
       return 1;
   }
    std::cout<< "the month is invalid"<<std::endl;
    return 0;
}
bool MyDate::isValidYear(int year) {
    if(1899<year&&year<2101){
        return 1;
    }
    std::cout<< "the year is invalid"<<std::endl;
    return 0;
}
bool MyDate::isValidDay(int day,int month) {
    if(!isValidFebruary(day,month)){
        std::cout<<"sorry dear February its a short month"<<std::endl;
    }else if(day<1||day>31){
        std::cout<< "the day is invalid"<<std::endl;
    }else{
        return 1;
    }
    return 0;
}
void MyDate::setDay(int day){
    if(isValidDay(day,m_month)){
       m_day=day; 
    }
}
void MyDate::setMonth(int month){
    if(isValidMonth(month)){
       m_month=month; 
    } 
}
bool MyDate::setYear(int year){
    if(isValidYear(year)){
       m_year=year; 
       return 1;
    } 
    return 0;
}
bool MyDate::set(int day, int month, int year){
    if(isValidDay(day,month)&&
        isValidMonth(month)&&
        isValidYear(year)){
        m_day=day;
        m_month=month;
        m_year=year;
        std::cout<< "All data is Valid"<<std::endl;
        return 1;
    }
    return 0;
}
/**
 * Get month and change the date according to the month
 * @param month
 * @return if the new date is valid or not(according to the year)
 */
bool MyDate::changeMonth(int month){
    int tempCalc = (m_month+month);
    m_month= tempCalc%12;
    if(m_month<=0){m_month = (12+m_month);}
    tempCalc=(tempCalc<=0)?-1:(tempCalc/12);
    return setYear(m_year+tempCalc);
}

bool MyDate::isBefore(MyDate& dateCompare)const{
    bool beforeInYears = m_year<dateCompare.m_year;
    bool beforeInMonths = m_year==dateCompare.m_year&&m_month<dateCompare.m_month;
    bool beforeInDays =  m_year==dateCompare.m_year&&m_month==dateCompare.m_month&&m_day<dateCompare.m_day;
    return  (beforeInYears||beforeInMonths||beforeInDays);
}

void MyDate::changeDate(int day){
    int tempCalc = m_day+day;
    int monthChange = -1;
    bool isCurrentBeforeFeb;
    MyDate febCheck;
    febCheck.set(28,2,m_year);
    bool isPrevBeforeFeb = isBefore(febCheck);
    if(tempCalc<0){tempCalc = (31+tempCalc);changeMonth(-1);}
    if(tempCalc%31==0)m_day=31;
    else{m_day = abs(tempCalc%31);}
     if(tempCalc!=0) {
         monthChange =(tempCalc / 31);
     }
    if(monthChange)changeMonth(monthChange);

     isCurrentBeforeFeb = isBefore(febCheck);
    //if the feb check is false and the year has been changed
    //update the feb check according current year
    if(day>0&&!isPrevBeforeFeb&&m_year!=febCheck.m_year){
        febCheck.setYear(m_year);
        isCurrentBeforeFeb =isBefore(febCheck);
        if(isCurrentBeforeFeb)isPrevBeforeFeb= true;
    }
    else if(day<0&&m_year!=febCheck.m_year&&isPrevBeforeFeb) {
        febCheck.setYear(m_year);
        isCurrentBeforeFeb = isBefore(febCheck);
        if(isCurrentBeforeFeb) isPrevBeforeFeb = false;
    }
    //Check if is invalid February
    if(!isValidFebruary(m_day,m_month)){
        if(day>0){
        m_day = m_day%28;
        m_month++;
        }else{
          m_day=(m_day-3);  
        }
    }
    //Check if there was February between the months and if so call the function again with shift of 3 days
    else if(day>0&&isPrevBeforeFeb&&!isCurrentBeforeFeb||day<0&&!isPrevBeforeFeb&&isCurrentBeforeFeb) {
        tempCalc = day > 0 ? 3 : -3;
        changeDate(tempCalc);
    }
}
void MyDate::delay(int shiftDays){
    changeDate(shiftDays);
}
void MyDate::bringForward(int backDays) {
    changeDate(backDays);
}

