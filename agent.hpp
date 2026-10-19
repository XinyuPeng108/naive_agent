#pragma once
#include <vector>
#include <string>
#include <cstddef>
#include <memory>

#include "message.hpp"
#include "model.hpp"

class Agent{
private:
    std::vector<Message> history;
    std::unique_ptr<Model> model;

public:
    explicit Agent(std::unique_ptr<Model> _model); //agent使用的model需要使用者传入
    std::string respond(const std::string& input);
    std::size_t history_size() const;
};