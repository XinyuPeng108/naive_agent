#pragma once
#include <string>
#include <optional>

#include "model_response.hpp"

enum class Role {
    user,
    agent,
    tool
};

struct Message{
    Role role;
    std::optional<ToolCall> tool_call;
    std::string content;
};