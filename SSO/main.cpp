#include <cstring>
#include <climits>
#include <stdexcept>

class SSOString {
    struct Small {
        short len;
        char text[14];
    };

    struct Large {
        short len;
        char* array;
    };

    union {
        Small small;
        Large large;
    };

    char* data() {
        if (size() <= 13)
            return small.text;
        return large.array;
    }

    const char* data() const {
        if (size() <= 13)
            return small.text;
        return large.array;
    }

    void setSize(std::size_t n) {
        if (n > SHRT_MAX)
            throw std::length_error("String is too long");

        char* old = nullptr;
        if (size() > 13)
            old = large.array;

        short len = static_cast<short>(n);

        if (len <= 13)
            small = Small{len, {}};
        else
            large = Large{len, new char[n + 1]};

        delete[] old;
        data()[len] = '\0';
    }

public:
    SSOString(const char* text = "") : small{} {
        setSize(std::strlen(text));
        std::strcpy(data(), text);
    }

    SSOString(const SSOString& other) : small{} {
        *this = other;
    }

    ~SSOString() {
        if (size() > 13)
            delete[] large.array;
    }

    SSOString& operator=(const SSOString& other) {
        if (this != &other) {
            setSize(other.size());
            std::memcpy(data(), other.data(), other.size());
        }
        return *this;
    }

    char& operator[](int i) {
        return data()[i];
    }

    const char& operator[](int i) const {
        return data()[i];
    }

    short size() const {
        return small.len;
    }

    short capacity() const {
        if (size() <= 13)
            return 13;
        return size();
    }

    SSOString operator+(const SSOString& other) const {
        SSOString result;
        std::size_t total = static_cast<std::size_t>(size()) + other.size();
        result.setSize(total);

        std::memcpy(result.data(), data(), size());
        std::memcpy(result.data() + size(), other.data(), other.size());
        return result;
    }
};

static_assert(sizeof(SSOString) == 16, "SSOString must be 16 bytes");
