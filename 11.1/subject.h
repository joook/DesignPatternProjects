#ifndef _SUBJECT_H_
#define _SUBJECT_H_

class Image
{
public:
    Image() = default;
    virtual ~Image() = default;

public:
    virtual void paint() = 0;
};

#endif
