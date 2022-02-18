#include "infix-postfix.h"
#include <stack>
#include <unordered_map>
#include <iostream>

std::string infix_to_postfix(const std::string& infix){
    std::unordered_map<char, int> op_priority = {{'+', 1}, {'*', 2}, {'/', 2}};

    std::string postfix = "";
    std::stack<char> ops;

    int i = 0;
    while(i < infix.length()){
        if(std::isdigit(infix[i])){
            std::string digit = "";
            while(i < infix.length() && std::isdigit(infix[i])){
                digit += infix[i];
                i++;
            }
            postfix += digit + ' ';
        }
        else if(infix[i] == '('){
            ops.push('(');
            i++;
        }
        else if(infix[i] == ')'){
            while(ops.top() != '('){
                postfix += ops.top();
                ops.pop();
            }
            ops.pop();
            i++;
        }
        else{
            while(!ops.empty() && op_priority[ops.top()] >= op_priority[infix[i]]){
                postfix += ops.top();
                ops.pop();
            }
            ops.push(infix[i]);
            i++;
        }
    }

    while(!ops.empty()){
        postfix += ops.top();
        ops.pop();
    }

    std::cout << postfix << std::endl;

    return postfix;
}

int eval_postfix(const std::string& postfix){
    int res = 0;
    std::stack<int> operands;

    int i = 0;
    while(i < postfix.size()){
        if(std::isdigit(postfix[i])){
            std::string digit = "";
            while(i < postfix.length() && std::isdigit(postfix[i])){
                digit += postfix[i];
                i++;
            }
            i++; // for space

            operands.push(std::stoi(digit.c_str()));
        }
        else{
            int operand2 = operands.top();
            operands.pop();

            int operand1 = operands.top();
            operands.pop();

            switch(postfix[i]){
                case '+' :
                    operands.push(operand1 + operand2);
                    break;
                case '-' :
                    operands.push(operand1 - operand2);
                    break;
                case '*' :
                    operands.push(operand1 * operand2);
                    break;
                case '/' :
                    operands.push(operand1 / operand2);
                    break;
                default:
                    break;
            }

            i++;
        }
    }

    return operands.top();
}
