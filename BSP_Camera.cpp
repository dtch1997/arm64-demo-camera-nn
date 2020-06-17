#include "BSP_Camera.h"
#include "Camera.h"
#include "stm32746g_discovery_camera.h"

void BSP_Camera::PowerOn(void)
{
    BSP_CAMERA_PwrUp();
    this->state_ = Camera::ON;
}

void BSP_Camera::PowerOff(void)
{
    BSP_CAMERA_PwrDown();
    this->state_ = Camera::OFF;
}

void BSP_Camera::Initialize(void) 
{
    if (this->state_ == Camera::READY) 
    {  
        return;
    }

    uint8_t status = BSP_CAMERA_Init(this->resolution_);
    if (status == CAMERA_OK) 
    {
        this->state_ = Camera::READY;
    }
    else 
    {
        this->state_ = Camera::ERROR;
    }
}

void BSP_Camera::DeInitialize(void) 
{
    if (this->state_ == Camera::ON) 
    {
        return;
    }
    
    uint8_t status = BSP_CAMERA_DeInit();
    if (status == CAMERA_OK) 
    {
        this->state_ = Camera::ON;
    }
    else 
    {
        this->state_ = Camera::ERROR;   
    }
}

void BSP_Camera::Capture(void) 
{
    BSP_CAMERA_SnapshotStart(this->buf_);
}

void BSP_Camera::StartRecording(void) 
{
    BSP_CAMERA_ContinuousStart(this->buf_);
}

void BSP_Camera::StopRecording(void) 
{
    BSP_CAMERA_Suspend();
}
