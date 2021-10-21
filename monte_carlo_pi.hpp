// Copyright 2021 Marcus Müller
// SPDX-License-Identifier: LGPL-3.0-or-later
#pragma once
#include "xoroshiro128p.hpp"
#include <cstdint>

namespace monte_carlo_pi {
constexpr rng::xoroshiro128p::result_type seed = 0xdeadbeef;
template <typename fp_t = double>
constexpr fp_t the_count(unsigned int howmany)
{
    unsigned int sum = 0;
    rng::xoroshiro128p rng(seed);
    for (auto idx = howmany; idx; --idx) {
        auto result = rng();
        uint64_t lower = result & 0xFFFFFFF;
        uint64_t upper = (result >> 31) & 0xFFFFFFF;

        std::uint64_t mag_sq = upper * upper + lower * lower;
        if (mag_sq <= (0x1ULL << 56)) {
            sum++;
        }
    }
    return static_cast<fp_t>(4 * sum) / howmany;
}
constexpr auto pi = monte_carlo_pi::the_count(242500);
} // namespace monte_carlo_pi
