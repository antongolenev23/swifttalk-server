#include <deque>
#include <mutex>
#include <queue>

template <typename T>
class ThreadSafeQueue {
 public:
  ThreadSafeQueue() = default;
  ThreadSafeQueue(const ThreadSafeQueue<T>& other) = delete;
  ThreadSafeQueue<T>& operator=(const ThreadSafeQueue<T>& other) = delete;
  ThreadSafeQueue(ThreadSafeQueue<T>&& other) = delete;
  ThreadSafeQueue<T>& operator=(ThreadSafeQueue<T>&& other) = delete;

  void push(const T& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    deque_.push_back(value);
  }

  T pop() {
    std::lock_guard<std::mutex> lock(mutex_);
    T tmp_value = std::move(deque_.front());
    deque_.pop_front();
    return tmp_value;
  }

  bool empty() {
    std::lock_guard<std::mutex> lock(mutex_);
    return deque_.empty();
  }

 private:
  std::deque<T> deque_;
  std::mutex mutex_;
};