add_library(graphics glad.c graphics.cxx application.cxx window.cxx geometry.cxx)
target_include_directories(graphics PUBLIC "${PROJECT_SOURCE_DIR}/include")