#include <iostream>
#include <string>
#include <random>
#include <algorithm>

int main(){
    const std::string comp_rsp[3] = {"Rock", "Scissors", "Paper"};
    std::string user_rsp;
    int user_score = 0, comp_score = 0, times = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2); 
    while (times < 10){
        std::cout<<"Enter Rock, Scissors or Paper: ";
        std::cin>>user_rsp;
        std::transform(user_rsp.begin(), user_rsp.end(), user_rsp.begin(), ::tolower);

        
        int comp_choice = dis(gen);
        std::string comp_rsp_choice = comp_rsp[comp_choice];
        
        
        std::cout << "Computer chose: " << comp_rsp_choice << std::endl;
        if ((user_rsp == "rock" && comp_rsp_choice == "Scissors") ||
            (user_rsp == "scissors" && comp_rsp_choice == "Paper") ||
            (user_rsp == "paper" && comp_rsp_choice == "Rock")){
            std::cout << "You win!" << std::endl;
            user_score++;
            std::cout << "Your score: " << user_score << " : " << comp_score << std::endl;
        } else if ((user_rsp == "rock" && comp_rsp_choice == "Paper") ||
                   (user_rsp == "scissors" && comp_rsp_choice == "Rock") ||
                   (user_rsp == "paper" && comp_rsp_choice == "Scissors")){
            std::cout << "You lose!" << std::endl;
            comp_score++;
            std::cout << "Your score: " << user_score << " : " << comp_score << std::endl;
        } else if ((user_rsp == "rock" && comp_rsp_choice == "Rock") ||
                   (user_rsp == "scissors" && comp_rsp_choice == "Scissors") ||
                   (user_rsp == "paper" && comp_rsp_choice == "Paper")){
            std::cout << "Draw!" << std::endl;
        } else {
            std::cout << "Invalid input!" << std::endl;
        }

        times++;
    }

    std::cout << "Game Over! Final score: " << user_score << " : " << comp_score << std::endl;
    return 0;
}