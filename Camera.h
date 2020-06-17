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
typedef struct image_size_t
{
    size_t height;
    size_t width;
    size_t channels;
} image_size;

template <typename T>
struct image
{
    image_size_t sz;
    std::vector<T>& data; // An array containing flattened image data
};

template <typename T>
class Camera
{
    /* OFF: The camera is unpowered. 
     * ON: The camera has been turned on. 
     * READY: The camera is ready to begin recording. 
     * RECORDING: The camera is currently recording. 
     * ERROR: The camera is in a state of error.
     */
    enum State {OFF, ON, READY, RECORDING, ERROR};

    public: 
        Camera(image_size_t size);
        virtual void PowerOn(void) = 0;
        virtual void Initialize(void) = 0;
        virtual void StartRecording(void) = 0;
        virtual void StopRecording(void) = 0;
        virtual void PowerOff(void) = 0;
        const image<T> GetOutput(void) const;
    
    protected:
        // Current state of the camera
        Camera::State state_;
        std::vector<T> buf_;
        // output_ shape is (H, W, C)
        // At every time step, internal buffer will be updated.
        const image<T> output_;
};
# endif
