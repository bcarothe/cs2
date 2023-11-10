#include "string.hpp"
#include <iostream>
#include <vector>

//-- Default --//
// Sets 1st index as null terminator
String::String() {
    stringSize = 1;
    str = new char[stringSize];
    str[0] = '\0';
}

//-- Character --//
// Sets 1st index as provided char and 2nd index as null terminator
String::String(char c) {
    stringSize = 2;
    str = new char[stringSize];
    str[0] = c;
    str[1] = '\0';
}

//-- Character Array --//
// Sets each index of char array to str
String::String(const char* s) {
    
    int length = 0;
    while (s[length] != '\0')
        ++length;
    
    stringSize = length + 1;
    str = new char[stringSize];
    
    int i = 0;
    while (i < stringSize) {
        str[i] = s[i];
        ++i;
    }
}

//-- Copy Constructor --//
String::String(const String& rhs) {
    stringSize = rhs.stringSize;
    str = new char[stringSize];
    for (int i = 0; i < rhs.stringSize; ++i)
        str[i] = rhs.str[i];
}

//-- Destructor --//
// Deletes new str
String::~String() {
    delete[] str;
}

//-- Swap --/
// Swaps 2 Strings
void String::swap(String& rhs) {
    char *tmpstr = str;
    str = rhs.str;
    rhs.str = tmpstr;
    int temp = stringSize;
    stringSize = rhs.stringSize;
    rhs.stringSize = temp;
}

//-- Assignment Copy --//
String& String::operator=(String rhs) {
    swap(rhs);
    return *this;
}

//-- Accessor/Modifier --//
char& String::operator[](int index) {
    if (index < 0 || index >= stringSize || index > length()) {
        return str[0];
    }
    return str[index];
}

//-- Accessor --/
char String::operator[] (int index) const {
    if (index < 0 || index > stringSize || index > length()) {
        return str[0];
    }
    return str[index];
}

//-- Capacity --//
// Length of str without null terminator
int String::capacity() const {
    return stringSize - 1;
}

//-- Length --//
// Number of characters in str
int String::length() const {
    int i = 0;
    while (str[i] != '\0') {
        ++i;
    }
    return i;
}

// ------------------------------
// Concatination
// ------------------------------
String String::operator+(const String& rhs) const {
    String result(length() + rhs.length() + 1, str);
    
    int offset = length();
    int i = 0;
    
    while (rhs.str[i] != 0) {
        result.str[offset + i] = rhs.str[i];
        ++i;
    }
    
    result.str[offset + i] = 0;
    return result;
}

String& String::operator+=(String rhs) {
    String temp(str);
    String result = temp + rhs;
    swap(result);
    return *this;
}

//
String operator+(const char* lhs, const String& rhs) {
    return String(lhs) + rhs;
}
//
String operator+(char lhs, const String& rhs) {
    return String(lhs) + rhs;
}
// End Addition //



// ------------------------------
// Comparison
// ------------------------------
bool String::operator==(const String& rhs) const {
    int temp = 0;
    for (int i = 0; i < stringSize && str[i] != '\0'; ++i, temp = i) {
        if (str[i] != rhs.str[i])
            return false;
    }
    if (str[temp] == '\0' && rhs.str[temp] != '\0')
        return false;
    if ((str[0] == '\0') && (rhs.str[0] != '\0'))
        return false;
    return true;
}

bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

//
bool operator==(const char* lhs, const String& rhs) {
    if (lhs[0] == rhs[0] && rhs.length() == 1)
        return true;
    return false;
}
//
bool operator==(char lhs, const String& rhs) {
    if (lhs == rhs[0] && rhs.length() == 1)
        return true;
    return false;
}

bool String::operator<(const String& rhs) const {
    //    if ((str[0] == rhs.str[0] && str[1] == 0 && rhs.str[2] == 0) || str[0] > rhs.str[0])
    //        return false;
    //    int i = 0;
    //    while (str[i] != 0 || rhs.str[i] != 0) {
    //        if (str[i] < rhs.str[i])
    //            return true;
    //        if (str[i] > rhs.str[i])
    //            return false;
    //        ++i;
    //    }
    //    return true;
    
    int i = 0;
    while (str[i] != 0 || rhs.str[i] != 0) {
        if (str[i] < rhs.str[i]) {
            return true;
        }
        else if (str[i] > rhs.str[i]) {
            return false;
        }
        ++i;
    }
    return false;
}

//
bool operator<(const char* lhs, const String& rhs) {
    if (lhs[0] < rhs[0] && 1 <= rhs.length())
        return true;
    return false;
}
//
bool operator<(char lhs, const String& rhs) {
    if (lhs < rhs[0] && 1 <= rhs.length())
        return true;
    return false;
}

bool operator>(const String& lhs, const String& rhs) {
    if (lhs.length() > rhs.length())
        return true;
    if (lhs[0] == rhs[0] || lhs[0] < rhs[0])
        return false;
    int i = 0;
    while (lhs[i] != 0 && rhs[i] != 0) {
        if (lhs[i] <= rhs[i])
            return false;
        ++i;
    }
    return true;
}

bool operator<=(const String& lhs, const String& rhs) {
    if (lhs[0] > rhs[0])
        return false;
    int i = 0;
    while (lhs[i] != 0 && rhs[i] != 0) {
        if (lhs.length() <= rhs.length())
            return true;
        if (lhs[i] >= rhs[i])
            return false;
        ++i;
    }
    return true;
}

bool operator>=(const String& lhs, const String& rhs) {
    if (lhs[0] < rhs[0])
        return false;
    int i = 0;
    while (lhs[i] != 0 && rhs[i] != 0) {
        if (lhs.length() >= rhs.length())
            return true;
        if (lhs[i] <= rhs[i])
            return false;
        ++i;
    }
    return true;
}

//-- Substr --/
// Returns a string within a string provided beginning and end points
String String::substr(int start, int end) {
    if (start < 0)
        start = 0;
    if (start > end)
        return String();
    if (end > length())
        end = length();
    //    if (end >= length())
    //        return String();
    
    String result;
    result.resetCapacity(end-start+2);
    //    result.str = new char[end - start + 2];
    //    result.stringSize = end - start + 2;
    
    
    int j = 0;
    for (int i = start; i <= end; ++i) {
        result[j] = str[i];
        ++j;
    }
    result[j] = '\0';   // Bug: Makes result empty
    return result;
}

//-- Findchar --//
// Finds the first index of a provided character from a starting point
int String::findchar(int start, char ch) const {
    if (start < 0)
        start = 0;
    while (start < length()) {
        if (str[start] == ch)
            return start;
        ++start;
    }
    return -1;
}

//-- Findstr --//
// Finds index of a part of a string
int String::findstr(int start, String find) const {
    int result = 0;
    //    int length1 = length();
    //    int length2 = find.length();
    int findLength = 0;
    
    int i = 0;
    
    if (start < 0)
        start = 0;
    
    while (start < length()) {
        if (str[start] == find[i]) {
            if (i == 0)
                result = start;
            ++findLength;
            ++i;
        }
        else if (findLength == find.length()) {
            return result;
        }
        ++start;
    }
    return -1;
}

// ------------------------------
// I/O
// ------------------------------
//-- Input --//
std::istream& operator>>(std::istream& in, String& rhs) {
    in >> rhs.str;
    return in;
}

//-- Output --//
std::ostream& operator<<(std::ostream& out, const String& rhs) {
    out << rhs.str;
    return out;
}
// End I/O //

//String::String(int size) {
//
//}
//String::String(int size, const char*) {
//
//}
//void String::resetCapacity(int newcap) {
//    str = new char[newcap];
//
//}


//-- Split --//
// Splits a string into multiple strings based on a provided character
std::vector<String> String::split(char ch) const {
    std::vector<String> result;
    String temp;
    
    for (int i = 0; str[i] != '\0' && i < length(); ++i) {
        
        // Adds each char of String to temp string until provided character
        if (str[i] != ch) {
            temp += str[i];
        }
        
        // Puts completed temp string to each index of vector
        else if (temp != "") {
            if (temp != ch)
                result.push_back(temp);
            temp = str[++i];
            while (temp == ch)
                temp = str[++i];
        }
    }
    return (result.push_back(temp), result);
}

// ==============================
// Private
// ==============================

String::String(int size) {
    str = new char[size];
    stringSize = size;
}

String::String(int size, const char* s) {
    str = new char[size];
    stringSize = size;
    
    int length = 0;
    while (s[length] != '\0')
        ++length;
    
    ++length; //account for null
    
    int i = 0;
    while ( i < length ) {
        str[i] = s[i];
        ++i;
    }
}

//-- Resets Capacity --//
void String::resetCapacity(int newSize) {
    char temp[length()];
    for (int i = 0; i < length(); ++i) {
        temp[i] = str[i];
    }
    str = new char[newSize];
    stringSize = newSize;
    for (int i = 0; i < newSize && temp[i] != 0; ++i) {
        str[i] = temp[i];
    }
    str[newSize] = 0;
    return;
}

int String::convertInt() {
    int result = 0;
    int i = 0;
    while (i < stringSize - 1) {
        result += (str[i] - 48);
        if (i != stringSize - 2)
            result = result * 10;
        ++i;
    }
    return result;
    
}
