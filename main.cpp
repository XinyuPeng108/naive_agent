#include <iostream>
#include <string>
#include <vector>

class Agent{
private:
    std::vector<std::string> inputs;

public:
    std::string respond(const std::string& input) {
        inputs.push_back(input); //inputs 是一个私有成员，其操作只能封装在类内
        return "received: " + input;
    }

    long long history_size() const{ 
        return inputs.size();
    }
};


int main()
{
    std::string input;
    Agent agent;
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