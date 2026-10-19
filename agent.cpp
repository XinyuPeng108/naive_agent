#include <memory>
#include <utility>
#include <stdexcept>
#include "agent.hpp"

Agent::Agent(std::unique_ptr<Model> _model) {
    if(!_model){
        throw std::invalid_argument("模型不可为空");
    }
    model = std::move(_model);

}

std::string Agent::respond(const std::string& input) {
    //保存用户消息
    Message user_input{Role::user, std::nullopt, input};
    history.push_back(user_input);
    //循环调用模型
    Message agent_message; //本次循环需要记入history的message
    std::size_t cnt = 0;
    while(true){
        //模型根据输入，判断reply应该是工具调用还是直接回复
        ModelResponse response = model->generate_reply(history);
        //若无工具调用需求，直接返回response里的final_answer
        if(!response.tool_call){
            agent_message = Message{Role::agent, std::nullopt, response.final_answer};
            history.push_back(agent_message); //记入历史
            return response.final_answer;
        }
        else{ //若需要工具调用
            if(cnt == 4){
                throw std::runtime_error("工具调用次数超过上限");
            }
            ToolCall tc = *(response.tool_call);
            //判断工具类型
            if(tc.name == "history_size"){
                std::string history_size = std::to_string(history.size());
                agent_message = Message{Role::tool, tc, "History: " + history_size};
            }
            else {
                agent_message = Message{Role::tool, tc, "未知工具: "+tc.name};
            }
            history.push_back(agent_message); //记入历史
            ++cnt;
        }
        
    }
}

std::size_t Agent::history_size() const{ 
    return history.size();
}