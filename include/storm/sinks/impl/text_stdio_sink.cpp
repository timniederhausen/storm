/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#include "storm/sinks/text_stdio_sink.hpp"

#include "storm/detail/windows_console_color.hpp"
#include "storm/detail/namespaces.hpp"

#include <boost/asio/write.hpp>

STORM_NS_BEGIN

namespace detail {

static const char colored_text_term[] = "\033[00m";

}

void text_stdio_sink::color_table(const ansi_color_string* color_table,
                                   std::size_t size) noexcept
{
  color_table_ = color_table;
  color_table_size_ = size;
}

void text_stdio_sink::log(basic_logger& logger, const log_record& rec)
{
  fmt::memory_buffer out;
  if (color_table_ && rec.severity < color_table_size_ &&
      color_table_[rec.severity]) {
#if defined(_WIN32)
    if (vtp_enabler_.colors_enabled()) {
#endif
      std::string_view color(color_table_[rec.severity]);
      out.append(color.data(), color.data() + color.size());
      format_(out, logger, rec);
      out.append(detail::colored_text_term,
                 detail::colored_text_term +
                 sizeof(detail::colored_text_term) - 1);
      asio::write(file_, asio::buffer(out.data(), out.size()));
#if defined(_WIN32)
    } else {
      // todo: scoped_console_color
      format_(out, logger, rec);
      asio::write(file_, asio::buffer(out.data(), out.size()));
    }
#endif
  } else {
    format_(out, logger, rec);
    asio::write(file_, asio::buffer(out.data(), out.size()));
  }
}

STORM_NS_END
