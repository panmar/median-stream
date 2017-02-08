#pragma once

#define TEST(expr, msg) if (!(expr)) { printf("%s:%d: %s\n", __FILE__, __LINE__, (msg)); }