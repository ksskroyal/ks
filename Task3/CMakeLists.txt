cmake_minimum_required(VERSION 3.1)
project(task3)

set(SOURCE ./src/main.cpp ./src/myjson.cpp ./src/generator.cpp src/CookingRecipe.cpp)


include_directories(./inc)
add_subdirectory(./ext/nlohmann)
add_executable(main ${SOURCE})



add_custom_command(
TARGET main
POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy
${CMAKE_SOURCE_DIR}/data/RecipeNames.txt
${CMAKE_CURRENT_BINARY_DIR}/RecipeNames.txt
)

add_custom_command(
TARGET main
POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy
${CMAKE_SOURCE_DIR}/data/Ingrediens.txt
${CMAKE_CURRENT_BINARY_DIR}/Ingrediens.txt
)

target_link_libraries(main nlohmann_json)

add_custom_command(
        TARGET main
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/data/RecipeNames.txt
        ${CMAKE_CURRENT_BINARY_DIR}/RecipeNames.txt
)

add_custom_command(
        TARGET main
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/data/Ingrediens.txt
        ${CMAKE_CURRENT_BINARY_DIR}/Ingrediens.txt
)