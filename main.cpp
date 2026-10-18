#include <iostream>
#include <string>

int main()
{
    std::string input;

    do {
        std::cout << "You> ";
        // "getline" can recieve whole line input, even input with space
        // check for input errors
        if(!std::getline(std::cin, input)) break; 
        if(input == "/exit") break;
        if(input != "") {
            std::cout << "Agent> received: " << input << "\n";
        }

    } while(true); //all exit conditions are written in the loop body
    
    return 0;
}