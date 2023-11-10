

//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"


void Date::setDay(String StringDay) {
    day = StringDay;
}
void Date::setMonth(String StringMonth) {
    month = StringMonth;
}
void Date::setYear(int IntYear) {
    year = IntYear;
}
String Date::getDay() const {
    return day;
}
String Date::getMonth() const {
    return month;
}
int Date::getYear() const {
    return year;
}

void Time::setHour(int IntHour) {
    hour = IntHour;
}
void Time::setMinute(int IntMinute) {
    minute = IntMinute;
}
void Time::setSecond(int IntSecond) {
    second = IntSecond;
}
int Time::getSecond() const {
    return second;
}
int Time::getMinute() const {
    return minute;
}
int Time::getHour() const {
    return hour;
}

int LogEntry::getBytes() const {
    return number_of_bytes;
}
String LogEntry::getHost() const {
    return host;
}


//////////////////////////////////////////////////////////
// REQUIRES:  
// ENSURES: 
//
LogEntry::LogEntry(String s) {
    
    std::cerr << "String: " << s << std::endl;
    std::vector<String> vec = s.split(' ');
    
    if(vec.size() != 10) {
        while (vec.size() < 10)
            vec.push_back("");
        host = "None";
        date.setDay("None");
        date.setMonth("None");
        date.setYear(0);
        time.setHour(0);
        time.setMinute(0);
        time.setSecond(0);
        request = "None";
        status = "None";
        number_of_bytes = 0;
    }
    
    host = vec[0];
    std::vector<String> DateAndTime = vec[3].split(':');
    std::vector<String> FullDate = DateAndTime[0].split('/');
//    std::vector<String> FullDate = DateAndTime;
    
//    String Day = FullDate[0].substr(1, 2);
//    Day = Day.substr(1, FullDate[0].length());
    date.setDay(FullDate[0].substr(1, 2));
    
    String Month = FullDate[1];
    date.setMonth(Month);
    
    int Year = FullDate[2].convertInt();
    date.setYear(Year);
    
    time.setHour(DateAndTime[1].convertInt());
    time.setMinute(DateAndTime[2].convertInt());
    time.setSecond(DateAndTime[3].convertInt());
    
    request = vec[5] + " " + vec[6] + " " + vec[7];
    status = vec[8];
    
    if (vec[9] == '-')
        number_of_bytes = 0;
    else
        number_of_bytes = vec[9].convertInt();
    
}

std::ostream& operator<<(std::ostream& out, const LogEntry& log) {
    out << "Host: " << log.host << '\n';
    
    out << "Day: " << log.date.getDay() << '\n';
    out << "Month: " << log.date.getMonth() << '\n';
    out << "Year: " << log.date.getYear() << '\n';
    
    out << "Hour: " << log.time.getHour() << '\n';
    out << "Minute: " << log.time.getMinute() << '\n';
    out << "Second: " << log.time.getSecond() << '\n';
    
    out << "Request: " << log.request << '\n';
    out << "Status: " << log.status << '\n';
    out << "Bytes: " << log.number_of_bytes << "\n\n";
    
    return out;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
    
    
    std::vector<LogEntry> result;
    char ch;
    int lines = 0;
    in.get(ch);
    while (!in.eof()) {
        String line;
        
        
        while (ch != '\n') {
            line = line + ch;
            in.get(ch);
        }
        LogEntry log(line);
        result.push_back(log);
        if (ch == '\n')
            ++lines;
        in.get(ch);
    }
    return result;
    
//    std::vector<LogEntry> result;
//    String line;
//    char ch;
//    while (in.get(ch) && !in.eof()) {
//        if(ch == '\n') {
//            line[line.capacity()] = 0;
//            if(line[0] != 0) {
//                LogEntry log(line);
//                result.push_back(log);
//                line = String();
//            }
//        }
//        else
//            line += ch;
//    }
//    return result;
    
    
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry> & logs) {
    for (unsigned int i = 0; i < logs.size(); ++i) {
        out << logs[i];
    }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& logs) {
    for (unsigned int i = 0; i < logs.size(); ++i) {
        out << logs[i].getHost() << '\n';
    }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  `
// ENSURES: 
//
int byte_count(const std::vector<LogEntry> & logs) {
    int sum = 0;
    
    for (unsigned int i = 0; i < logs.size(); ++i) {
        sum += logs[i].getBytes();
    }
    
    return sum;
}

