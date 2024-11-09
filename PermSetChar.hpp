#ifndef PERM_SET_CHAR_HPP_
#define PERM_SET_CHAR_HPP_

template <typename T>
class PermanentSet;

template <>
class PermanentSet<char> {
 private:
  bool data_[256] = { false };

 public:
  PermanentSet() = default;

  void Insert(char value) {
    data_[static_cast<unsigned char>(value)] = true;
  }

  bool Contains(char value) const {
    return data_[static_cast<unsigned char>(value)];
  }
};

#endif // PERM_SET_CHAR_HPP_
