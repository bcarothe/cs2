/*
 *  ASTree.cpp
 *  Abstract Syntax Tree
 *
 *  Created by Jonathan Maletic
 *  Copyright 2016 Kent State University. All rights reserved.
 *
 *  Modified by:
 *
 */

#include "ASTree.hpp"


/////////////////////////////////////////////////////////////////////
// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    tree = new AST(*(actual.tree));
}

/////////////////////////////////////////////////////////////////////
// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

/////////////////////////////////////////////////////////////////////
// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

/////////////////////////////////////////////////////////////////////
// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}


/////////////////////////////////////////////////////////////////////
// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    src.tree->print(out);
    return out;
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::mainHeader(std::vector<std::string>& profileNames) {
    tree->mainHeader(profileNames);
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::fileHeader(const std::string& profileName) {
    tree->fileHeader(profileName);
}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
//
void srcML::mainReport(std::vector<std::string>& profileNames) {
        tree->mainReport(profileNames);
}

/////////////////////////////////////////////////////////////////////
//  Inserts a filename.count() into each function body.
//
void srcML::funcCount(const std::string& profilename) {
    tree->funcCount(profilename);
}

/////////////////////////////////////////////////////////////////////
// Inserts a filename.count() for each statement.
//
void srcML::lineCount(const std::string& profilename) {
    tree->lineCount(profilename);
}

    

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}


/////////////////////////////////////////////////////////////////////
// Destructor for AST
//
AST::~AST() {
    if (!child.empty()) {
        std::list<AST*>::iterator ASTIndex;
        ASTIndex = child.begin();
        
        while (ASTIndex != child.end()) {
            delete *ASTIndex++;
        }
    }
    
//    for(std::list<AST*>::const_iterator iter = child.begin(); iter != child.end(); ++iter)
//        delete *iter;
}


/////////////////////////////////////////////////////////////////////
// Copy Constructor for AST
//
AST::AST(const AST& actual) {
    nodeType = actual.nodeType;
    tag = actual.tag;
    closeTag = actual.closeTag;
    text = actual.text;
    
    for (std::list<AST*>::const_iterator iter = actual.child.begin(); iter != actual.child.end(); ++iter) {
        child.push_back(new AST(**iter));
    }
}


/////////////////////////////////////////////////////////////////////
// Constant time swap for AST
//
void AST::swap(AST& b) {
    std::swap(nodeType, b.nodeType);
    std::swap(tag, b.tag);
    std::swap(closeTag, b.closeTag);
    std::swap(text, b.text);
    
    child.swap(b.child);
}

/////////////////////////////////////////////////////////////////////
// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}


/////////////////////////////////////////////////////////////////////
// Returns a pointer to child[i] where (child[i]->tag == tagName)
//
// IMPORTANT for milestone 3
AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}


/////////////////////////////////////////////////////////////////////
// Returns the full name of a <name> node.
//  There are two names.  A simple name (e.g., foo) and a name with
//   a scope (e.g., std::bar).
//
// IMPORTANT for milestone 3
//
std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}


/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables in a main file.
//
void AST::mainHeader(std::vector<std::string>& profileNames) {
    std::string profileString("#include \"profile.hpp\"\n");
    
    size_t i = 0;
    for (std::vector<std::string>::iterator iter = profileNames.begin(); iter < profileNames.end() && i < profileNames.size(); ++iter, ++i) {
            std::string profileName = profileNames[i];
            size_t start = profileName.find("_cpp");
            profileName.replace(start, 4, ".cpp");
            profileString += ("profile " + profileNames[i] + "(\"" + profileName + "\");\n");
    }
    profileString += "\n";
    
    std::list<AST*>::iterator iter2 = child.begin();
    while ((*iter2)->tag != "function")
        ++iter2;
    
    child.insert(iter2, new AST(token, profileString));
}


/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables for non-main files
//
void AST::fileHeader(const std::string& profileName) {

    //NEED TO IMPLEMENT
    //Skip down a couple lines.
    //For each file profile name, add a new node with a profile 
    // extern declaration.
    //Also, add in the extern declaration for functions and the
    //include for profile.hpp
    
    
    
    std::string profileString("#include \"profile.hpp\"\n");
    std::string name = profileName;
    profileString += ("extern profile " + profileName + ";\n\n");
    
    std::list<AST*>::iterator iter = child.begin();
    while((*iter)->tag != "function") {
        ++iter;
    }
    
    child.insert(iter, new AST(token, profileString));
}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
// Assumes only one return at end of main body.
//
void AST::mainReport(std::vector<std::string>& profileNames) {
    std::string declarations = "\n";
    for (size_t i = 0; i < profileNames.size(); ++i)
        declarations += "\n    std::cout << " + profileNames[i] + " << std::endl;";
    for (std::list<AST*>::iterator iter = child.begin(); iter != child.end(); ++iter)
        if ((*iter)->tag == "function")
            for (std::list<AST*>::iterator iter2 = (*iter)->child.begin(); iter2 != (*iter)->child.end(); ++iter2)
                if((*iter2)->tag == "name") {
                    std::list<AST*>::iterator iter3 = (*iter2)->child.begin();
                    if((*iter3)->text == "main") {
                        while((*iter2)->tag != "block")
                            ++iter2;
                        for (iter3 = --(*iter2)->child.end(); iter3 != (*iter2)->child.begin(); --iter3)
                            if ((*iter3)->tag == "return") {
                                --iter3;
                                (*iter2)->child.insert(iter3, new AST(token, declarations));
                            }
                    }
                }
}


/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each function is executed.
//  Assumes no nested functions.
//
void AST::funcCount(const std::string& profileName) {
    std::string declarations = " " + profileName + ".count(__LINE__, __FUNCTION__);";
    for (std::list<AST*>::iterator iter = child.begin(); iter != child.end(); ++iter)
        if ((*iter)->tag == "function" || (*iter)->tag == "constructor" || (*iter)->tag == "destructor")
            for (std::list<AST*>::iterator iter2 = (*iter)->child.begin(); iter2 != (*iter)->child.end(); ++iter2)
                if((*iter2)->tag == "block") {
                    std::list<AST*>::iterator iter3 = (*iter2)->child.begin();
                    ++iter3;
                    (*iter2)->child.insert(iter3, new AST(token, declarations));
                }
}


/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each statement is executed.
//   No breaks, returns, throw etc.
//   Assumes all construts (for, while, if) have { }.
//
void AST::lineCount(const std::string& profileName) {
    std::string declarations = " " + profileName + ".count(__LINE__);";
    for (std::list<AST*>::iterator iter = child.begin(); iter != child.end(); ++iter)
        if ((*iter)->tag == "function")
            for (std::list<AST*>::iterator iter2 = (*iter)->child.begin(); iter2 != (*iter)->child.end(); ++iter2)
                if((*iter2)->tag == "block") {
                    recursive(iter2, profileName);
                    break;
                }
}


/////////////////////////////////////////////////////////////////////
// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
//
std::istream& AST::read(std::istream& in) {
    AST *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end();
                 ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}


/////////////////////////////////////////////////////////////////////
// Print an AST 
//
std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        switch ((*i)->nodeType) {
            case category:
                (*i)->print(out);
                break;
            case token:
                out << (*i)->text;
                break;
            case whitespace:
                out << (*i)->text;
                break;
        }
    }
    return out;
}

    

/////////////////////////////////////////////////////////////////////
// Utilities
//


/////////////////////////////////////////////////////////////////////
// This returns true if a syntactic category is encountered that
//  will not be profiled.
//
// This is IMPORTANT for milestone 3
bool isStopTag(std::string tag) {
    if (tag == "decl_stmt"            ) return true;
    if (tag == "argument_list"        ) return true;
    if (tag == "init"                 ) return true;
    if (tag == "condition"            ) return true;
    if (tag == "cpp:include"          ) return true;
    if (tag == "macro"                ) return true;
    if (tag == "comment type\"block\"") return true;
    if (tag == "comment type\"line\"" ) return true;
    return false;
}


/////////////////////////////////////////////////////////////////////
// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
//
std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}


/////////////////////////////////////////////////////////////////////
// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
//
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">");}
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<");}
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&");}
    return s;
}


/////////////////////////////////////////////////////////////////////
// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}  
//
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    
/////////////////////////////////////////////////////////////////////
// Recursive function for lineCount
//
//
void AST::recursive(std::list<AST*>::iterator iter0, const std::string& profileName) {
    std::string declarations = " " + profileName + ".count(__LINE__);";
    std::list<AST*>::iterator iter = (*iter0)->child.begin();
    while(iter != (*iter0)->child.end()) {
        if ((*iter)->tag == "expr_stmt")
            (*iter)->child.insert(++iter, new AST(token, declarations));
        else if((*iter)->tag == "block")
            recursive(iter, profileName);
        else if ((*iter)->tag == "for" || (*iter)->tag == "while" || (*iter)->tag == "if" || (*iter)->tag == "else" || (*iter)->tag == "else if" || (*iter)->tag == "case")
            for (std::list<AST*>::iterator iter2 = (*iter)->child.begin(); iter2 != (*iter)->child.end(); ++iter2)
                recursive(iter2, profileName);
        ++iter;
    }
}
