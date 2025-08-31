#include <cstdint>
#include <vector>

struct Header {
  uint32_t size_ = 0;
};

struct Message {
  Header header_;
  std::vector<uint8_t> body;
};