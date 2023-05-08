

#include "CookingRecipe.h"

CookingRecipe::CookingRecipe() = default;

CookingRecipe::CookingRecipe(std::string Name_, double Time_, double Cal_, std::vector<std::pair<std::string, double>> ingredient_){
    name = Name_;
    time = Time_;
    cal = Cal_;
    ingredient = ingredient_;
}

void CookingRecipe::print(){
    std::cout << "Name = " << name << std::endl
            << "Time = " << time << std::endl
            << "Cal = " << cal << std::endl
            << "Ingredients : " << std::endl;

    for(int i = 0; i < ingredient.size(); i++){
        std::cout << i << ") Name = " << ingredient[i].first << " Rated = " << ingredient[i].second << std::endl;
    }
    std::cout << std::endl;
}


