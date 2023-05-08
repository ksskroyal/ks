

#ifndef MYJSON_H
#define MYJSON_H

#include <stdio.h>
#include <fstream>
#include <nlohmann/json.hpp>

#include "CookingRecipe.h"

using json = nlohmann::json;



class myjson{
private:
    json data;
    
public:
    
    myjson();
    myjson(char*);
    myjson(FILE*);
    void Input(FILE*);
    void Print();
    void Clear();
    void Execute(double time_min,double time_max,double cal_min,double cal_max);
    void Add(CookingRecipe);
    void Delete(std::string);
    void Save(std::string);
    std::string Dump();
    static json CreateJSON(CookingRecipe);
    json FindCookingRecipe(std::string);
};


#endif
