/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   myMain.cpp
 * Author: yifatbiezuner
 *
 * Created on 08 March 2016, 17:54
 */

#include <cstdlib>
#include <iostream>

#include "MyDate.h"

using namespace std;

/*
 * 
 */
int main() {
    int day,month,year;
    MyDate date1;
    std::cout<<"set valid year 2000:"<<date1.setYear(2000)<<std::endl;
    std::cout<<"set invalid year 1899:"<<date1.setYear(1899)<<std::endl;
    std::cout<<"set invalid year 2102:"<<date1.setYear(2102)<<std::endl;
    std::cout<<"set invalid day -1:"<<date1.setDay(-1)<<std::endl;
    std::cout<<"set invalid day 31:"<<date1.setDay(31)<<std::endl;
    std::cout<<"set valid day 20:"<<date1.setDay(20)<<std::endl;
    std::cout<<"set invalid month -2:"<<date1.setMonth(-2)<<std::endl;
    std::cout<<"set invalid month 13:"<<date1.setMonth(13)<<std::endl;
    std::cout<<"set valid month 2:"<<date1.setMonth(2)<<std::endl;
    std::cout<<"set invalid February day 29:"<<date1.setDay(29)<<std::endl;
//     date1.set(29,2,2000);
//     date1.set(29,2,190);
//     date1.set(29,2,2500);
//     date1.set(29,2,2000);
//     date1.set(29,4,190);
//     date1.set(29,4,2900);
//     date1.set(29,4,2000);
// date1.set(29,0,2000);
// date1.set(29,42,2000);
// date1.set(0,4,2000);
// date1.set(32,4,2000);
//while(day!=0){
//    std::cout << "please enter day,month and year" << std::endl;
//    cin >> day >>month >>year;
//    date1.set(day,month,year);
//    date1.print();
//     std::cout << "change month" << std::endl;
//     cin >> month;
//    date1.changeMonth(month);
//    date1.print();
//}
std::cout <<"Welcome to MyDate"<< std::endl;
    char commant[]= "new comment";
    date1.changeComment(commant);
    date1.printComment();
            std::cout << "please enter day,month and year" << std::endl;
    cin >> day >>month >>year;
    while(day!=0){

//            std::cin>>day;
//            std::cout << "please enter month" << std::endl;
//            std::cin>>month;
//            std::cout << "please enter year" << std::endl;
//            std::cin>>year;
            if(date1.set(day,month,year)){
                date1.print();
                std::cout << "how you would like to change the days? (|365|)?" <<std::endl;
                        cin >> day;
                        date1.changeDate(day);
                        date1.print();
            };
        std::cout << "please enter day,month and year" << std::endl;
        cin >> day >>month >>year;
    }


    system("PAUSE");
    return EXIT_SUCCESS;
}

