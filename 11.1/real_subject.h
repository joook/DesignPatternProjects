#ifndef _REAL_SUBJECT_H_
#define _REAL_SUBJECT_H_

#include "subject.h"
#include <memory>
#include <string>
#include <vector>

class RealImage : public Image
{
public:
    RealImage(const std::string &FileName);

public:
    virtual void paint() override;

private:
    std::shared_ptr<std::vector<std::string>> m_ImageDataPtr;
};

#endif
