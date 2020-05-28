#ifndef _PROXY_H_
#define _PROXY_H_

#include "subject.h"
#include <memory>
#include <string>
#include <thread>
#include <atomic>

class RealImage;

class ImageProxy : public Image
{
friend void runLoadThread(ImageProxy *ImageProxyPtr);

public:
    ImageProxy(const std::string &ImagePath, const std::string &ImageName)
    : Image()
    , m_ImagePath(ImagePath)
    , m_ImageName(ImageName)
    , m_IsLoading(false)
    {
    }

    virtual ~ImageProxy() override = default;

public:
    virtual void paint() override;

private:
    std::shared_ptr<RealImage> m_RealImagePtr;
    std::string m_ImagePath;
    std::string m_ImageName;
    //std::atomic<bool> m_IsLoading;
    bool m_IsLoading;
};

#endif
