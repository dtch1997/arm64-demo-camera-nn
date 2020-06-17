# ifndef BSP_CAMERA_H
# define BSP_CAMERA_H


# include "Camera.h"
# include <cstdint>
# include "stm32746g_discovery_camera.h"

class BSP_Camera : public Camera<uint8_t>
{
    public:
        static const int DEFAULT_RESOLUTION = RESOLUTION_R160x120;

        BSP_Camera(image_size_t sz, uint32_t resolution): Camera<uint8_t>(sz) 
        {
            this->resolution_ = resolution;
        };
        void PowerOn(void);
        void PowerOff(void);
        void Initialize(void);
        void DeInitialize(void);
        void Capture(void);
        void StartRecording(void);
        void StopRecording(void);

    private:
        uint32_t resolution_;
};

# endif
