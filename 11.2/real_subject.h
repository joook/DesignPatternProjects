#ifndef _REAL_SUBJECT_H_
#define _REAL_SUBJECT_H_

#include "subject.h"

class RealBlog : public Blog
{
public:
    virtual void read() override;
    virtual void write() override;
};

#endif
