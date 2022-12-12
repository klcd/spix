/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include "Exists.h"

#include <Scene/Scene.h>

namespace spix {
namespace cmd {

Exists::Exists(ItemPath path, std::promise<bool> promise)
: m_path(std::move(path))
, m_promise(std::move(promise))
{
}

void Exists::execute(CommandEnvironment& env)
{
    auto item = env.scene().itemAtPath(m_path);

    if (item) {
        m_promise.set_value(true);
    } else {
        m_promise.set_value(false);
    }
}

} // namespace cmd
} // namespace spix
