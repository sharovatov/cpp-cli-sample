#include <charconv>
#include <cstdint>
#include <iostream>
#include <string_view>

bool parse_integer(std::string_view text, std::int32_t& value) {
    const auto result = std::from_chars(text.data(), text.data() + text.size(), value);
    // Require a valid integer with no trailing characters.
    return result.ec == std::errc{} && result.ptr == text.data() + text.size();
}

int main(int argc, char* argv[]) {
    // argc includes the program name.
    if (argc != 4 || std::string_view(argv[1]) != "add") {
        std::cerr << "Usage: calc add <integer> <integer>\n";
        return 1;
    }

    std::int32_t first = 0;
    std::int32_t second = 0;
    // Reject invalid or out-of-range operands.
    if (!parse_integer(argv[2], first) || !parse_integer(argv[3], second)) {
        std::cerr << "Error: operands must be 32-bit integers.\n";
        return 1;
    }

    // Widen before addition to avoid overflow.
    std::cout << static_cast<std::int64_t>(first) + second << '\n';
    return 0;
}
