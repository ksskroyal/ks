

#ifndef GENERATOR_H
#define GENERATOR_H

#include "CookingRecipe.h"

#include <stdio.h>
#include <fstream>
#include <ctime>


class Generator{
private:

	
	int maxTime = 100;
    int maxCal = 1000;
    int maxWorth = 101;
    std::vector<std::string> CookingRecipeNames;
    std::vector<std::string> ratingNames;
public:
	
	Generator();
    void readFiles(std::string, std::string);
    void generate(std::string, int);
    void print();
    CookingRecipe genCookingRecipe();
};

#endif
