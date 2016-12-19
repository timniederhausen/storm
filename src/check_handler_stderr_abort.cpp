#include <storm/check.hpp>

#include <cstdio>
#include <cstdlib>

STORM_NS_BEGIN

bool handle_check_failure(const char* filename, int lineno,
                          const char* function, const char* expr,
                          const char* msg)
{
	std::fprintf(stderr,
	             "[%s:%d]: %s: CHECK %s failed\n",
	             filename, lineno, function, expr);
	std::abort();
	return true;
}

STORM_NS_END
