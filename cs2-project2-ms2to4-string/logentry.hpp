#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 

////////////////////////////////////////////////////////////
class Date { 
public:
            Date() {};
            void setDay(String);
            void setMonth(String);
            void setYear(int);
            String getDay() const;
            String getMonth() const;
            int getYear() const;
private:
    String  day, month;
    int     year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
            Time() {};
            void setHour(int);
            void setMinute(int);
            void setSecond(int);
            int getSecond() const;
            int getMinute() const;
            int getHour() const;
  private:
    int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
            LogEntry() {};
            LogEntry(String);
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);
            String getHost() const;
            int getBytes() const;

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);

#endif

