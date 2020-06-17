#include "Camera.h"

template <typename T> 
Camera<T>::Camera(image_size_t sz) {
    // This should ensure that vector never gets reallocated
    this->buf_.reserve(sz.height * sz.width * sz.channels);
    this->output_ = {sz, this->buf_};
}

template <typename T>
const image<T> Camera<T>::GetOutput() const {
    return this->output_;
}
