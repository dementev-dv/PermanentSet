#ifndef PERM_SET_HPP_
#define PERM_SET_HPP_

template <typename T>
class PermanentSet {
 private:
  struct Node {
    T value;
    Node* left{nullptr};
    Node* right{nullptr};
    Node(T val) : value(val) { }

    void insert(T val) {
      if (val == value) return;
      if (val < value) {
        if (!left)
          left = new Node(val);
        else
          left.insert(val);
      }
      if (val > value) {
        if (!right)
          right = new Node(val);
        else
          right.insert(val);
      }
      return;
    }

    bool find(T val) {
      if (val < value) {
        if (!left)
          return false;
        else
          return left.find(val);
      }
      if (val > value) {
        if (!right)
          return false;
        else
          return right.find(val);
      }
      return true;
    }
  };

  Node* root_{nullptr};

 public:
  PermanentSet() = default;

  void Insert(T val) {
    if (!root_)
      root_ = new Node(val);
    else
      root_.insert(val);
    return;
  }

  bool Contains(T val) {
    if (!root_)
      return false;
    return root_.find(val);
  }
};

#endif // PERM_SET_HPP_
