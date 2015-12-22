#include <hb.h>
#include <hb-ft.h>

#include <glog/logging.h>

#include <string>

namespace hbxx {

class buffer {
public:
  buffer()
    : buf_(CHECK_NOTNULL(hb_buffer_create()))
  {
  }

  ~buffer() { hb_buffer_destroy(buf_); }

  void add_utf8(std::string const& str)
  {
    hb_buffer_add_utf8(buf_, str.data(), str.length(), 0, str.length());
  }

private:
  hb_buffer_t* buf_;
};
}
