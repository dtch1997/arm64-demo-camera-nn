# ifndef CAMERA_H
# define CAMERA_H

# include <vector>
# include <tuple>

typedef std::vector<char> row;
typedef std::vector<row> layer;
typedef std::vector<layer> image;

/*
 * Camera will be implemented as a finite-state automaton. 
 */
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
        Camera(std::tuple<int> output_size);
        virtual void PowerOn(void) = 0;
        virtual void Initialize(void) = 0;
        virtual void StartRecording(void) = 0;
        virtual void StopRecording(void) = 0;
        virtual void PowerOff(void) = 0;
        const image& GetOutput(void) const;
    
    protected:
        // Current state of the camera
        Camera::State state_;
        // output_ shape is (H, W, C)
        // At every time step, internal buffer will be updated.
        mutable image output_;
        std::tuple<int> output_size_;
};
# endif
