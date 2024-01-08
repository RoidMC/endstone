// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <functional>
#include <memory>
#include <mutex>
#include <random>
#include <string_view>

namespace endstone::sym {
class SymbolHandler {
public:
    SymbolHandler() = default;
    SymbolHandler(const SymbolHandler &) = delete;
    SymbolHandler(SymbolHandler &&other) noexcept
    {
        other.valid_ = false;
    }
    SymbolHandler &operator=(const SymbolHandler &) = delete;
    SymbolHandler &operator=(SymbolHandler &&) = delete;

    virtual ~SymbolHandler() = default;
    virtual void enumerate(const char *module, std::function<bool(const std::string &, size_t)> callback) = 0;

protected:
    bool valid_ = true;
};

std::unique_ptr<SymbolHandler> create_handler();
}  // namespace endstone::sym