# Copyright 2021 Marcus Müller
# SPDX-License-Identifier: LGPL-3.0-or-later
cmake_minimum_required (VERSION 3.10)
project (constexpr_monte_carlo_pi CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)

find_package(fmt)

add_executable(monte_carlo_pi monte_carlo_pi.cc)
target_link_libraries(monte_carlo_pi fmt::fmt)

install(TARGETS monte_carlo_pi
  RUNTIME
  DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES monte_carlo_pi.hpp xoroshiro128p.hpp
  TYPE INCLUDE
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
