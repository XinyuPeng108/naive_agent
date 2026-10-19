#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

#include "agent.hpp"
#include "mock_model.hpp"

int main()
{
    std::string input;
    Agent agent(std::make_unique<MockModel>());

    do {
        std::cout << "You> ";
        
        if(!std::getline(std::cin, input)) break; 
        if(input == "/exit") break;
        if(input != "") {
            std::cout << "Agent> " << agent.respond(input) << "\n";
            std::cout << "History: " << agent.history_size() << "\n";
        }

    } while(true); 
    
    return 0;
}