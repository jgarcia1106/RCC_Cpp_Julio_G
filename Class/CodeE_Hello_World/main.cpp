#include <iostream>

int main() {
    const float caloriesPerCookie = 75.0f; // Assuming each cookie has 75 calories
    int cookiesEaten;
    float totalCalories;

    std::cout << "Calorie-Counter" << std::endl;
    std::cout << "How-many-cookies-did-you-eat?";
    std::cin >> cookiesEaten;

    // Calculate the total calories consumed
    totalCalories = cookiesEaten * caloriesPerCookie;

    // Output formatted to match the expected result
    std::cout << "You-consumed-" << static_cast<int>(totalCalories) << "-calories.";
    
    return 0;
}
