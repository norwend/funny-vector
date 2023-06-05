#pragma once
#include <stdexcept>

namespace ndr {
	template <typename T = int>
	class Vec {
	private:
		T* elements_ = nullptr;
		int size_ = 0;
		int allocated_ = 2;
		void resize_() {
			allocated_ *= 2;
			T* new_loc = new T[allocated_];
			for (int i = 0; i < this->size_; i++)
				new_loc[i] = elements_[i];
			delete[] elements_;
			elements_ = new_loc;
		}
	public:
		T at(const int& idx) {
			if (idx >= size_ || (idx < 0 && (size_ + idx) > size_))
				throw std::runtime_error("out of bounds");
			if (idx < 0 && (size_ + idx) < size_)
				return elements_[size_ + idx];
			return elements_[idx];
		}
		
		T operator[](const int& idx){
			return this->at(idx);
		}

		int get_size() { return size_; }

		void append(const T& elem) {
			if (size_ + 1 > allocated_) {
				this->resize_();
			}
			elements_[size_++] = elem;
		}
		
		Vec(const int& size = 0) : size_(size) {
			allocated_ = (size_ == 0 ? 1 : size_) * 2;
			elements_ = new T[allocated_];
		}
		
		~Vec() {
			delete[] elements_;
		}
	};
}
