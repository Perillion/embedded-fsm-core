#pragma once

namespace perillion::core {

class State {
public:
    virtual ~State() = default;
    virtual void enter() {}
    virtual void exit() {}
    virtual void process() {}
};

} // namespace perillion::core

