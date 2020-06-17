# ifndef CAMERA_H
# define CAMERA_H

# include <vector>
# include <tuple>

//typedef std::vector<char> row;
//typedef std::vector<row> layer;
//typedef std::vector<layer> image;

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
        Camera(image_size_t size);
        ~Camera(void);
        virtual void PowerOn(void) = 0;
        virtual void PowerOff(void) = 0;
        virtual void Initialize(void) = 0;
        virtual void DeInitialize(void) = 0;
        virtual void Capture(void) = 0;
        virtual void StartRecording(void) = 0;
        virtual void StopRecording(void) = 0;
        virtual void HandleError(void);
        
        const image_t<T> GetOutput(void) const;
        const State GetState(void);
        

    protected:
        // Current state of the camera
        Camera::State state_;
        // Raw images are read into buf_. The raw output may require some pre-processing. 
        T* buf_;
        // output_ shape conforms to specified size (H, W, C)
        // At every time step, internal buffer will be updated.
        const image_t<T> output_;
};
# endif
