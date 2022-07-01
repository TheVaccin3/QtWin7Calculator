cmake_minimum_required(VERSION 3.5)
project(Win7Calc CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# configure Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Widgets Core Test REQUIRED)

# EDIT
# add any files you create related to the GUI here
# excluding tests
set(gui_src
  message_widget.hpp
  repl_widget.hpp
  main_window.hpp
  button_panel.hpp
  )


# EDIT
# add any files you create related to the Calculator program here
set(calc_src
  ${gui_src}
  Calculator.cpp
  )

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

# create the Calculator executable
add_executable(Calculator ${calc_src})
target_link_libraries(Calculator Qt5::Widgets)


# enable clang-tidy with -DTIDY=TRUE
if(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX AND TIDY)
  add_custom_target(tidy
    COMMAND ${CMAKE_COMMAND} -E env "source=${CMAKE_CURRENT_SOURCE_DIR}" env "build=${CMAKE_CURRENT_BINARY_DIR}"
    ${CMAKE_CURRENT_SOURCE_DIR}/scripts/tidy.sh
    )
endif()

