#pragma once
#include <vector>

#include "message.hpp"
#include "model.hpp"

class MockModel : public Model {
public:
    ModelResponse generate_reply(const std::vector<Message>& history) const override;
};