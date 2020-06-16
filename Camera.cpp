#include "Camera.h"
#include <tuple>

Camera::Camera(std::tuple<int> output_size) {
    this->output_size_ = output_size; 
}

const image& Camera::GetOutput() const {
    return this->output_;
}
