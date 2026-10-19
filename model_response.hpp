#pragma once
#include <string>
#include <optional>

struct ToolCall {
    std::string name; //工具名称
};

struct ModelResponse {
    std::string final_answer; //最终回复
    std::optional<ToolCall> tool_call; //工具需求（可选）
};