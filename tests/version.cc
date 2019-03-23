#include <canopen/version.h>
#include "catch.h"
#include <string>

TEST_CASE("version")
{
	REQUIRE(std::string(canopen::Version::project_name) == "canopen");
	REQUIRE(std::string(canopen::Version::git_tag) != "");
	REQUIRE(std::string(canopen::Version::build_date) != "");
}
