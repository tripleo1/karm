#pragma once

#include "widget.h"

namespace Karm::Ui {

struct _Dock : public _Widget {
};

void dock(Children children = {}) {
    widget([&] {
        children();
    });
}

} // namespace Karm::Ui
