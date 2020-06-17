#include "Camera.h"

template <typename T>
Camera<T>::~Camera() {
    PowerOff();
    DeInitialize();
    ClearMemory();
}

template <typename T>
const image_t<T> Camera<T>::GetOutput() const {
    return this->output_;
}

template <typename T>
void Camera<T>::ClearMemory() {
    delete this->buf_;
}

template<typename T>
// Default error handling: Turn off and turn on
void Camera<T>::HandleError() {
    if (this->state_ != Camera<T>::ERROR) return;
    PowerOff();
    PowerOn();
}
