

#include "myjson.h"
#include "generator.h"
#include "CookingRecipe.h"
int main(){
    Generator gen;
    myjson data;

    int com_number = 0;
    bool exit = false;
    while(!exit){
        std::cout << "Available commands : " << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "1. Generate data.json file" << std::endl;
        std::cout << "2. Print data.json file" << std::endl;
        std::cout << "3. Execute data.json" << std::endl;
        std::cout << "4. Delete record" << std::endl;
        std::cout << "5. Add recipe" << std::endl;


        std::cout << "Enter the number of command : ";
        std::cin >> com_number;
        if(com_number < 0 || com_number > 5){
            std::cout << "error : wrong command number" << std::endl << std::endl;
            continue;
        }

        switch(com_number){
            case 0:
            {
                exit = true;
                break;
            }
            case 1:
            {
                int numbers = 10;
                std::cout << "Enter the number of CookingRecipe to generate : " << std::endl;
                std::cin >> numbers;
                if(numbers <= 0){
                    std::cout << "error : number of CookingRecipe to generate less than zero" << std::endl;
                    break;
                }

                gen.readFiles("RecipeNames.txt", "Ingrediens.txt");
                gen.generate("data.json", numbers);
                data.Clear();
                FILE* fin = fopen("data.json", "r");
                data.Input(fin);
                break;
            }
            case 2:
            {
                data.Print();
                break;
            }
            case 3:
            {
                double m1,m2,k1,k2;
                std::cout << "Enter the range of t and cal: t_min, t_max,cal_min,cal_max: " << std::endl;
                std::cin >> m1 >> m2 >> k1 >> k2;
                data.Execute(m1,m2,k1,k2);
                break;
            }
            case 4:
            {
                std::string name;
                std::cout << "Enter the name of the CookingRecipe to delete : " << std::endl;
                std::cin >> name;
                data.Delete(name);
                break;

            }
            case 5:
            {
                CookingRecipe rent;
                std::string name;double time,cal;
                int num;std::string name_;double value;
                std::cout << "Enter time,cal,name:" << std::endl;
                std::cin >> time >> cal >> name;
                rent.name=name;rent.cal=cal;rent.time=time;
                std::cout << "Enter the number of ingredient:"<< std::endl;
                std::cin>> num; rent.ingredient.reserve(num);

                for(int i = 0; i < num; i++){
                    std::cout << "Enter the name and value:" << std::endl;
                    std::cin >> name_ >> value;
                    rent.ingredient.push_back(std::pair<std::string, double>{name_, value});

                }
               
                data.Add(rent);
                break;
            }

        }
    }
    

    return 0;
}
