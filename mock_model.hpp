#pragma once
#include <vector>

#include "message.hpp"
#include "model.hpp"

class MockModel : public Model {
public:
    std::string generate_reply(const std::vector<Message>& history) const override;
};