#pragma once
#include "State.hpp"

namespace perillion::core {

class StateMachine {
public:
    void setState(State& newState) {
        if (m_currentState) {
            m_currentState->exit();
        }
        m_currentState = &newState;
        m_currentState->enter();
    }

    void process() {
        if (m_currentState) {
            m_currentState->process();
        }
    }

private:
    State* m_currentState = nullptr;
};

} // namespace perillion::core

