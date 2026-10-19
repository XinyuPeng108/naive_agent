#pragma once
#include <string>
#include <vector>

#include "message.hpp"
#include "model_response.hpp"

class Model {
public:
    virtual ~Model() = default; 

    virtual ModelResponse generate_reply(const std::vector<Message>& history) const = 0;
};