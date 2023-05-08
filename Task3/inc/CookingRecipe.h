

#ifndef COOKINGRECIPE_H
#define COOKINGRECIPE_H



#include <iostream>
#include <vector>
#include <algorithm>

struct CookingRecipe
        {
    std::string name;
    double time;double cal ;
    std::vector<std::pair<std::string, double> >  ingredient;
    CookingRecipe();
    CookingRecipe(std::string, double, double, std::vector<std::pair<std::string, double>>);
    void print();
    
};

#endif
