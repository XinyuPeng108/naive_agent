#include <memory>
#include <utility>
#include <stdexcept>
#include "agent.hpp"

Agent::Agent(std::unique_ptr<Model> _model) {
    if(!_model){
        throw std::invalid_argument("模型不可为空");
    }
    model = std::move(_model);

}

std::string Agent::respond(const std::string& input) {
    Message user_input(Role::user, input);
    history.push_back(user_input);

    std::string response = model->generate_reply(history);
    Message agent_response(Role::agent, response);
    history.push_back(agent_response);
    return response;
}

std::size_t Agent::history_size() const{ 
    return history.size();
}