#include "mock_model.hpp"

std::string MockModel::generate_reply(const std::vector<Message>& history) const {
    if(!history.empty()){
        Message response = history.back();
        return "received: " + response.content;
    }
    return "No dialogue history.";
}