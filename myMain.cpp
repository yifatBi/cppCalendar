/*

 */

/* 
 * File:   myMain.cpp
 * Author: Yifat Biezuner
 *
 * Created on 08 March 2016, 17:54
 */

#include <cstdlib>
#include <iostream>
#include "MyDate.h"
#include "Calendar.h"

#define BOOL_STR(b) ((b)?"true":"false")

using namespace std;

/*
 * 
 */
int main() {
    MyDate date1;
    MyDate date2;
    char invalidComment[] ="much much much longer";
    char validComment[] = "new _comment";
    ///test My Date
    cout<<"Test setYear :"<<endl;
    cout<<"set valid year 2000 expected return true----> actual return :"<<BOOL_STR(date1.setYear(2000))<<endl;
    cout<<"set invalid year 1899 expected return false----> actual return :"<<BOOL_STR(date1.setYear(1899))<<endl;
    cout<<"set invalid year 2102 expected return false----> actual return :"<<BOOL_STR(date1.setYear(2102))<<endl;
    cout<<"Test setMonth :"<<endl;
    cout<<"set invalid month expected return false----> actual return :"<<BOOL_STR(date1.setMonth(-2))<<endl;
    cout<<"set invalid month expected return false----> actual return :"<<BOOL_STR(date1.setMonth(13))<<endl;
    cout<<"set valid month 2 expected return true----> actual return :"<<BOOL_STR(date1.setMonth(2))<<endl;
    cout<<"Test setDay :"<<endl;
    cout<<"set invalid day -1 expected return false----> actual return :"<<BOOL_STR(date1.setDay(-1))<<endl;
    cout<<"set valid day 20 expected return true----> actual return :"<<BOOL_STR(date1.setDay(20))<<endl;
    cout<<"set invalid February day 29 expected return false----> actual return :"<<BOOL_STR(date1.setDay(29))<<endl;
    date1.setMonth(1);
    cout<<"set month to January and check invalid day 31 expected return false----> actual return :"<<BOOL_STR(date1.setDay(31))<<endl;
    cout<<"set valid day 30 expected return false----> actual return :"<<BOOL_STR(date1.setDay(30))<<endl;
    cout<<"Test changeComment :"<<endl;
    cout<<"change _comment to: '"<<validComment<<"' length "<<strlen(validComment);
    cout<<endl<<" current _comment: "<<endl;
    date1.printComment();
    date1.changeComment(validComment);
    cout<<" expected return new _comment----> actual return :";
    date1.printComment();
    date1.changeComment(invalidComment);
    cout<<"change _comment to invalid length _comment : '"<<invalidComment<<"' length "<<strlen(invalidComment);
    cout<<endl<<" current _comment: "<<endl;
    date1.printComment();
    cout<<"expected return new _comment----> actual return :";
    date1.printComment();
    cout<<"Test init function :"<<endl;
    date1.init();
    cout<< "After init the date expected 21/3/2016 and the result is: ";
    date1.print();
    cout<<endl;
    cout<<"Test set function :"<<endl;
    cout<<"set(29,2,2000) expected return false----> actual return :"<< BOOL_STR(date1.set(29,2,2000))<<endl;
    cout<<"set(0,2,2000) expected return false----> actual return :"<< BOOL_STR(date1.set(0,2,2000))<<endl;
    cout<<"set(29,2,190) expected return false----> actual return :"<< BOOL_STR(date1.set(29,2,190))<<endl;
    cout<<"set(29,2,2500) expected return false----> actual return :"<< BOOL_STR(date1.set(29,2,2500))<<endl;
    cout<<"set(29,5,2500) expected return false----> actual return :"<< BOOL_STR(date1.set(29,5,2500))<<endl;
    cout<<"set(29,5,100) expected return false-----> actual return :"<< BOOL_STR(date1.set(29,5,100))<<endl;
    cout<<"set(0,5,2000) expected return false-----> actual return :"<< BOOL_STR(date1.set(0,5,2000))<<endl;
    cout<<"set(32,5,2000) expected return false-----> actual return :"<< BOOL_STR(date1.set(32,5,2000))<<endl;
    cout<<"set(30,0,2000) expected return false-----> actual return :"<< BOOL_STR(date1.set(30,0,2000))<<endl;
    cout<<"set(30,20,2000) expected return false-----> actual return :"<< BOOL_STR(date1.set(30,20,2000))<<endl;
    cout<<"expected the day to be as is was inited 21/3/2016-----> actual result : ";
    date1.print();
    cout<<"set(30,12,2000) expected return true-----> actual return :"<< BOOL_STR(date1.set(30,12,2000))<<endl;
    cout<<"set(12,2,2000) expected return true-----> actual return :"<< BOOL_STR(date1.set(12,2,2000))<<endl<<endl;
    cout<<"Test isBefore :"<<endl;
    date2.set(12,2,2000);
    cout<<"isBefore for 2 equal dates: ";
    cout<<endl;
    cout<<"date1:";
    date1.print();
    cout<<"date2:";
    date2.print();
    cout<<"expect return false------> actual return :"<<BOOL_STR(date1.isBefore(date2))<<endl;
    date2.set(11,2,2000);
    cout<<"isBefore with days: ";
    cout<<endl;
    cout<<"date1:";
    date1.print();
    cout<<"date2:";
    date2.print();
    cout<<"expect return false------> actual return :"<<BOOL_STR(date1.isBefore(date2))<<endl;
    date2.set(12,1,2000);
    cout<<"isBefore with month: ";
    cout<<endl;
    cout<<"date1:";
    date1.print();
    cout<<"date2:";
    date2.print();
    cout<<"expect return false------> actual return :"<<BOOL_STR(date1.isBefore(date2))<<endl;
    date2.set(12,2,1999);
    cout<<"isBefore with year: ";
    cout<<endl;
    cout<<"date1:";
    date1.print();
    cout<<"date2:";
    date2.print();
    cout<<"expect return false------> actual return :"<<BOOL_STR(date1.isBefore(date2))<<endl;
    date2.set(13,2,2000);
    cout<<"isBefore with days: ";
    cout<<endl;
    cout<<"date1:";
    date1.print();
    cout<<"date2:";
    date2.print();
    cout<<"expect return true------> actual return :"<<BOOL_STR(date1.isBefore(date2))<<endl;
    date2.set(12,3,2000);
    cout<<"isBefore with month: ";
    cout<<endl;
    cout<<"date1:";
    date1.print();
    cout<<"date2:";
    date2.print();
    cout<<"expect return true------> actual return :"<<BOOL_STR(date1.isBefore(date2))<<endl;
    date2.set(12,2,2001);
    cout<<"isBefore with year: ";
    cout<<endl;
    cout<<"date1:";
    date1.print();
    cout<<"date2:";
    date2.print();
    cout<<"expect return true------> actual return :"<<BOOL_STR(date1.isBefore(date2))<<endl<<endl;
    cout<<"Test Delay :"<<endl;
    cout<<"delay with invalid num -2 : expect return false------> actual return :"<<BOOL_STR(date1.delay(-2))<<endl;
    cout<<"delay with invalid num 366 : expect return false------> actual return :"<<BOOL_STR(date1.delay(366))<<endl;
    cout<<"delay in 2 days to invalid date : current date ";
    date1.set(29,12,2100);
    date1.print();
    cout<<"expect return false------> actual return :"<<BOOL_STR(date1.delay(2))<<endl;
    cout<<"expected date 29/12/2100--------> actual return : ";
    date1.print();
    date1.set(1,1,2000);
    cout<<"delay days in same month delay with 5 days:"<<endl;
    cout<<"current Date : ";
    date1.print();
    cout<<"expected date 6/1/2000 ------> actual return : ";
    date1.delay(5);
    date1.print();
    cout<<"delay days change month delay with 30 days:"<<endl;
    cout<<"current Date : ";
    date1.print();
    cout<<"expected date 6/2/2000 ------> actual return : ";
    date1.delay(30);
    date1.print();
    cout<<"delay days with February between with 30 days:"<<endl;
    cout<<"current Date : ";
    date1.print();
    cout<<"expected date 8/3/2000 ------> actual return : ";
    date1.delay(30);
    date1.print();
    cout<<"delay days change years with 2 days:"<<endl;
    cout<<"current Date : ";
    date1.set(30,12,2000);
    date1.print();
    cout<<"expected date 2/1/2001 ------> actual return : ";
    date1.delay(2);
    date1.print();
    cout<<endl;
    cout<<"Test bringForword actualy go backword :"<<endl;
    cout<<"bringForword with invalid num -2 : expect return false------> actual return :"<<BOOL_STR(date1.bringForward(-2))<<endl;
    cout<<"bringForword with invalid num 366 : expect return false------> actual return :"<<BOOL_STR(date1.bringForward(366))<<endl;
    cout<<"bringForword in 2 days to invalid date : current date ";
    date1.set(1,1,1900);
    date1.print();
    cout<<"expect return false------> actual return :"<<BOOL_STR(date1.bringForward(2))<<endl;
    cout<<"expected date 1/1/1900--------> actual return : ";
    date1.print();
    date1.set(12,4,2000);
    cout<<"go past days in same month back with 5 days:"<<endl;
    cout<<"current Date : ";
    date1.print();
    cout<<"expected date 7/4/2000 ------> actual return : ";
    date1.bringForward(5);
    date1.print();
    cout<<"go past days change month back with 30 days:"<<endl;
    cout<<"current Date : ";
    date1.print();
    cout<<"expected date 7/3/2000 ------> actual return : ";
    date1.bringForward(30);
    date1.print();
    cout<<"go past days with February between back 30 days:"<<endl;
    cout<<"current Date : ";
    date1.print();
    cout<<"expected date 5/2/2000 ------> actual return : ";
    date1.bringForward(30);
    date1.print();
    cout<<"go past days change years with 2 days:"<<endl;
    cout<<"current Date : ";
    date1.set(1,1,2000);
    date1.print();
    cout<<"expected date 29/12/1999 ------> actual return : ";
    date1.bringForward(2);
    date1.print();
    cout<<"Test print :"<<endl;
    date1.set(23,12,2007);
    cout<<"expected 23/12/2007 ------> actual result : ";
    date1.print();
    cout<<endl;
    //Test Calendar
    Calendar calendar;
    cout<<"Test Calendar :"<<endl;
    cout<<"Test setDate :"<<endl;
    cout<<"setDate(2,currentDate) current date : ";
    date1.print();
    cout<<"expected value in cell 2 is the same and the result------>";
    calendar.setDate(2,date1);
    calendar.printCell(2);
    cout<<"Test printCall empty cell :"<<endl;
    cout<<"expected 1 : this cell is empty ----------> actual result : ";
    calendar.printCell(1);
    cout<<endl;
    cout<<"Test isFree : "<<endl;
    cout<<"not free cell 2 expected result false -------> actual result "<<BOOL_STR(calendar.isFree(2))<<endl;
    cout<<"Free cell 1 expected result true -------> actual result "<<BOOL_STR(calendar.isFree(1))<<endl;
    cout<<"Test firstFree and fillAllWithVal: "<<endl;
    cout<<"expected firstFree 1 --------> actual result "<<calendar.firstFree()<<endl;
    calendar.fillAllWithVal(date1);
    cout<<"after fill all with val expected firstFree 0 --------> actual result "<<calendar.firstFree()<<endl;
    cout<<"Test print full calendar ------> actual result "<<endl;
    calendar.print();
    cout<<endl;
    cout<<"Test datesNum : "<<endl;
    cout<<"expected 30---------> actual result "<<calendar.datesNum(date1)<<endl;
    cout<<"expected oldest 1---------> actual result "<<calendar.oldest()<<endl;
    cout<<"Test deleteDateCell call 4 has been deleted:"<<endl;
    calendar.deleteDate(4);
    cout<<"expected datesNum 29---------> actual result "<<calendar.datesNum(date1)<<endl;
    cout<<"expected firstFree 5--------> actual result : "<<(calendar.firstFree())<<endl;
    cout<<"Insert to one empty cell in array expect result true --------> actual result "<<BOOL_STR(calendar.insert(date2))<<endl<<endl;
    cout<<"Test insert and empty dates:"<<endl;
    cout<<"Insert to full dates array expect result false --------> actual result "<<BOOL_STR(calendar.insert(date2))<<endl;
    calendar.deleteAll();
    cout<<"Test print empty calendar expected:Empty Calendar------> actual result ";
    calendar.print();
    cout<<"expected oldest 0---------> actual result "<<calendar.oldest()<<endl;
    cout<<"expected datesNum 0---------> actual result "<<calendar.datesNum(date1)<<endl;
    cout<<"Insert to empty dates array expect result true --------> actual result "<<BOOL_STR(calendar.insert(date2))<<endl;
    cout<<"expected val in first cell result ";
    date2.print();
    cout<<"actual result ";
    calendar.printCell(0);
    date1.setYear(1999);
    calendar.setDate(19,date1);
    cout<<"expected oldest 20---------> actual result "<<calendar.oldest()<<endl;
    calendar.print();
    return EXIT_SUCCESS;
}

