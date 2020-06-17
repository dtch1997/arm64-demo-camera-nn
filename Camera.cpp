#include "Camera.h"

template <typename T> 
Camera<T>::Camera(image_size_t sz) {
    this->buf_ = new T[sz.height * sz.width * sz.channels];
    this->output_ = {sz, this->buf_};
}
template <typename T>
Camera<T>::~Camera() {
    delete this->buf_;
}

template <typename T>
const image_t<T> Camera<T>::GetOutput() const {
    return this->output_;
}

template<typename T>
// Default error handling: Turn off and turn on
void Camera<T>::HandleError() {
    if (this->state_ != Camera<T>::ERROR) return;
    PowerOff();
    PowerOn();
}
