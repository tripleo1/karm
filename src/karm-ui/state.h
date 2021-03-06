#pragma once

#include "hook.h"
#include "ui.h"

namespace Karm::Ui {

template <typename T>
struct State : public Hook {
    T _value;

    State(T value) : _value(value) {
    }

    Text::Str desc() const override {
        return u8"State";
    }

    T const *operator->() const {
        return &_value;
    }

    T const &operator*() const {
        return _value;
    }

    void update(auto fn) {
        fn(_value);
    }
};

template <typename T>
State<T> &useState(T value) {
    return ui().hook<State<T>>(value);
}

} // namespace Karm::Ui
