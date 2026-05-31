cmake_minimum_required(VERSION 3.25)
project(storm LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC)
add_library(storm::storm ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)
target_compile_definitions(${PROJECT_NAME} PUBLIC STORM_SEPARATE_COMPILATION)
target_link_libraries(${PROJECT_NAME} PUBLIC asioext::asioext Boost::filesystem Boost::system fmt::fmt)

target_sources(${PROJECT_NAME}
  PUBLIC
  include/storm/basic_log_sink.hpp
  include/storm/basic_logger.hpp
  include/storm/detail/config.hpp
  include/storm/detail/namespaces.hpp
  include/storm/log.hpp
  include/storm/log_record.hpp
  include/storm/log_sinks.hpp
  include/storm/sinks/basic_file_sink.hpp
  include/storm/sinks/basic_stdio_sink.hpp
  include/storm/sinks/text_file_sink.hpp
  include/storm/sinks/text_stdio_sink.hpp
  include/storm/source_location.hpp
  PRIVATE
  include/storm/impl/basic_logger.cpp
  include/storm/sinks/impl/basic_file_sink.cpp
  include/storm/sinks/impl/basic_stdio_sink.cpp
  include/storm/sinks/impl/text_file_sink.cpp
  include/storm/sinks/impl/text_stdio_sink.cpp
)

if(WIN32)
  target_sources(${PROJECT_NAME}
    PUBLIC
    include/storm/detail/windows_console_color.hpp
    include/storm/detail/windows_vtp_enabler.hpp
    PRIVATE
    include/storm/detail/impl/windows_console_color.cpp
    include/storm/detail/impl/windows_vtp_enabler.cpp
  )
endif()
