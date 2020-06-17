# ifndef CAMERA_H
# define CAMERA_H

#include <cstddef>

/*
 * Camera will be implemented as a finite-state automaton. 
 */
typedef struct {
    size_t height;
    size_t width;
    size_t channels;
} image_size_t;

template <typename T> struct image_t {
    image_size_t sz;
    T* data; // An array containing flattened image data
};

template <typename T> class Camera
{
    /* OFF: The camera is unpowered. 
     * ON: The camera has been turned on. 
     * READY: The camera is ready to begin recording. 
     * RECORDING: The camera is currently recording. 
     * ERROR: The camera is in a state of error.
     */

    public: 
        enum State {OFF, ON, READY, RECORDING, ERROR};
        Camera(const image_size_t sz) : buf_(new T[sz.height * sz.width * sz.channels]), image_size_(sz) {};
        ~Camera(void) {
            DeInitialize();
            ClearMemory();
            PowerOff();
        };
        virtual void PowerOn(void) = 0;
        virtual void PowerOff(void) = 0;
        virtual void Initialize(void) = 0;
        virtual void DeInitialize(void) = 0;
        virtual void Capture(void) = 0;
        virtual void StartRecording(void) = 0;
        virtual void StopRecording(void) = 0;
       
        /*
         * Methods of a class template must be implemented in header
         */
        void HandleError(void) {
            if (this->state_ != ERROR) 
            {
                return;
            }
            PowerOff();
            PowerOn();
        };
        void ClearMemory(void) {
            delete this->buf_;
        };
        const image_t<T> GetOutput(void) const {
            const image_t<T> output = {this->image_size_, this->buf_};
            return output;
        };
        const State GetState(void) const {
            return this->state_;
        };
        

    protected:
        // Current state of the camera
        Camera::State state_;
        // Raw images are read into buf_. The raw output may require some pre-processing. 
        T* const buf_;
        // output_ shape conforms to specified size (H, W, C)
        // At every time step, internal buffer will be updated.
        const image_size_t image_size_;
};
# endif
