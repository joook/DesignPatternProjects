#ifndef _SUBJECT_H_
#define _SUBJECT_H_

class Blog
{
public:
    Blog() = default;
    virtual ~Blog() = default;

public:
    virtual void read() = 0;
    virtual void write() = 0;
};

#endif
