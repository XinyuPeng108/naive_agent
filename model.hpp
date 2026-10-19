#pragma once
#include <string>
#include <vector>

#include "message.hpp"

class Model {
public:
    virtual ~Model() = default; 

    virtual std::string generate_reply(const std::vector<Message>& history) const = 0;
};