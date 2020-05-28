#ifndef _PROXY_H_
#define _PROXY_H_

#include "subject.h"
#include <memory>

class RealBlog;

class BlogOwnerProxy : public Blog
{
public:
    BlogOwnerProxy(const std::shared_ptr<RealBlog> &RealBlogPtr)
    : Blog()
    , m_RealBlogPtr(RealBlogPtr)
    {
    }

    virtual ~BlogOwnerProxy() override = default;

public:
    virtual void read() override;
    virtual void write() override;

private:
    std::shared_ptr<RealBlog> m_RealBlogPtr;
};

class BlogGuestProxy : public Blog
{
public:
    BlogGuestProxy(const std::shared_ptr<RealBlog> &RealBlogPtr)
    : Blog()
    , m_RealBlogPtr(RealBlogPtr)
    {
    }

    virtual ~BlogGuestProxy() override = default;

public:
    virtual void read() override;
    virtual void write() override;

private:
    std::shared_ptr<RealBlog> m_RealBlogPtr;
};

#endif
