#include "string.hpp"
#include <iostream>

//-- Default --//
String::String() {
    str[0] = '\0';
}

//-- Character --//
String::String(char c) {
    str[0] = c;
    str[1] = '\0';
}

//-- Character Array --//
String::String(const char s[]) {
    int length = 0;
    
    //
    while (s[length] != '\0')
        ++length;
    
    --length;
    
    //
    int i = 0;
    while (i >= 0 && length != -1) {
        str[i] = s[i];
        ++i;
        --length;
    }
    str[i] = '\0';
}

//-- Subscript --//
char& String::operator[](int index) {
    if (index < 0 || index >= STRING_SIZE || index > length()) {
        return str[0];
    }
    return str[index];
}
char String::operator[] (int index) const {
    if (index < 0 || index >= STRING_SIZE || index > length()) {
        return str[0];
    }
    return str[index];
}


int String::capacity() const {
    return STRING_SIZE - 1;
}

int String::length() const {
    int i = 0;
    while (str[i] != '\0') {
        ++i;
    }
    return i;
}

// ------------------------------
// Addition
// ------------------------------
String String::operator+(const String& rhs) const {
    String result = str;
    int offset = result.length();
    int i = 0;
    while (rhs.str[i] != 0) {
        result.str[offset + i] = rhs.str[i];
        ++i;
    }
    result.str[offset + i] = 0;
    return result;
}

String& String::operator+=(String rhs) {
    int offset = length();
    int i = 0;
    while (rhs.str[i] != 0) {
        str[offset + i] = rhs.str[i];
        ++i;
    }
    str[offset + i] = 0;
    return *this;
}
// End Addition //



// ------------------------------
// Comparison
// ------------------------------
bool String::operator==(const String& rhs) const {
    for (int i = 0; i < STRING_SIZE && str[i] != '\0'; ++i) {
        if (str[i] != rhs.str[i])
            return false;
    }
    if ((str[0] == '\0') && (rhs.str[0] != '\0'))
        return false;
    return true;
}

bool operator!=(const String& lhs, const String& rhs) {
//    int i = 0;
//    while (lhs[0] != 0 && rhs[0] != 0) {
//        if (lhs[i] == rhs[i])
//            return false;
//        ++i;
//    }
//    return true;
    
//    for (int i = 0; i < rhs.length(); ++i) {
//        if (lhs[i] == rhs[i])
//            return false;
//    }
//    return true;
    
    for (int i = 0; i < STRING_SIZE && lhs[i] != '\0'; ++i) {
        if (lhs[i] == rhs[i])
            return false;
    }
    if ((lhs[0] == '\0') && (rhs[0] == '\0'))
        return false;
    return true;
}

bool String::operator<(const String& rhs) const {
    if (length() < rhs.length())
        return true;
    if (str[0] == rhs.str[0] || str[0] > rhs.str[0])
        return false;
    int i = 0;
    while (str[i] != 0 && rhs.str[i] != 0) {
        if (str[i] >= rhs.str[i])
            return false;
        ++i;
    }
    return true;
}

bool operator> (const String& lhs, const String& rhs) {
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

bool operator<= (const String& lhs, const String& rhs) {
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

bool operator>= (const String& lhs, const String& rhs) {
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
String String::substr(int start, int end) {
    if (start < 0)
        start = 0;
    if (start > end)
        return String();
    if (end > length())
        end = length();
    //    if (end >= length())
    //        return String();
    
    
    String result = new char[end - start + 2];
//    result.stringSize = end - start + 2;
    
    
    int j = 0;
    for (int i = start; i <= end; ++i) {
        result[j] = str[i];
        ++j;
    }
    result[j] = '\0';
    return result;
}

//-- Findchar --//
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
std::istream& operator>>(std::istream& in, String& rhs) {
    in >> rhs.str;
    return in;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
    out << rhs.str;
    return out;
}
// End I/O //
