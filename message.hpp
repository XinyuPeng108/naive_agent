#pragma once
#include <string>

enum class Role {
    user,
    agent
};

struct Message{
    Role role;
    std::string content;

    Message(Role _role, std::string _content): role(_role), content(_content) {}
};