//
//  StringUtils.h
//  swapStratCpp
//
//  Created by Leonardo Borrero Luz on 2013-09-17.
//
//

#ifndef __swapStratCpp__StringUtils__
#define __swapStratCpp__StringUtils__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class StringUtils{
public:
    static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
    
    static std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }
};

#endif /* defined(__swapStratCpp__StringUtils__) */
