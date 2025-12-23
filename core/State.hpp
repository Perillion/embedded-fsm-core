#pragma once

template <typename TContext, typename TEvent>
class State {
public:
    virtual ~State() = default;

    virtual void enter(TContext& context) {}
    virtual void exit(TContext& context) {}
    virtual void handleEvent(TContext& context, const TEvent& event) {}
};

