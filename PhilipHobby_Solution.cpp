#include <iostream>
#include <array>

int main(){
    std::array<int, 9> myArray = {1, 2, 3, 5, 6, 7, 8, 9, 10};
    std::array<bool, ((myArray.size()) + 1)> answer = {false};

    for (int i = 0; i < myArray.size(); i++){
        answer[myArray[i] - 1] = true;
    }
    for (int i = 0; i < answer.size(); i++){
        if (answer[i] == false){
            std::cout << i + 1 << " is missing.";
            break;
        }
    }
}