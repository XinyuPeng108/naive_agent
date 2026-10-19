#include "mock_model.hpp"

ModelResponse MockModel::generate_reply(const std::vector<Message>& history) const {
    if(!history.empty()){
        const Message& response = history.back(); //我们只需要查看最后一条消息，无需另外复制一份
        if(response.role == Role::tool){
            if(response.tool_call){
                ToolCall tc = *(response.tool_call);
                if(tc.name == "history_size"){
                    return ModelResponse {response.content, std::nullopt};
                }
            }
            
        }
        if(response.content == "/count" && response.role == Role::user){
            return ModelResponse{"", ToolCall{"history_size"}};
        }
        ModelResponse model_response{"received: " + response.content, std::nullopt};
        return model_response;
    }
    return ModelResponse{"No dialogue history.", std::nullopt};
}