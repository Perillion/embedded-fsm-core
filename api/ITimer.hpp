#pragma once
#include <cstdint>

namespace perillion::hal {

class ITimer {
public:
    virtual ~ITimer() = default;

    virtual void start(uint32_t timeout_ms) = 0;
    virtual bool hasExpired() const = 0;
    virtual void stop() = 0;
};

} // namespace perillion::hal

