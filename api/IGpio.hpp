#pragma once

namespace perillion::hal {

class IGpio {
public:
    virtual ~IGpio() = default;

    virtual void write(bool state) = 0;
    virtual void toggle() = 0;
    virtual bool read() const = 0;
};

} // namespace perillion::hal

