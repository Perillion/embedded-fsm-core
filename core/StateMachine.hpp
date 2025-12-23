#pragma once
#include "State.hpp"

template <typename TContext, typename TEvent>
class StateMachine {
public:
    explicit StateMachine(TContext& context)
        : context_(context), currentState_(nullptr) {}

    void initialize(State<TContext, TEvent>* initialState) {
        currentState_ = initialState;
        if (currentState_) {
            currentState_->enter(context_);
        }
    }

    void transitionTo(State<TContext, TEvent>* nextState) {
        if (currentState_) {
            currentState_->exit(context_);
        }
        currentState_ = nextState;
        if (currentState_) {
            currentState_->enter(context_);
        }
    }

    void processEvent(const TEvent& event) {
        if (currentState_) {
            currentState_->handleEvent(context_, event);
        }
    }

    State<TContext, TEvent>* getCurrentState() const {
        return currentState_;
    }

protected:
    TContext& context_;
    State<TContext, TEvent>* currentState_;
};

