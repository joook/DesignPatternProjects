#ifndef _SINGLETON_H_
#define _SINGLETON_H_

//destructor func will not be called,
//resources will be freed after the process ends
class Singleton
{
private:
    Singleton() { m_Id++; }
    Singleton(const Singleton &OriSingleton) = delete;
    Singleton & operator=(const Singleton &OriSingleton) = delete;

public:
    static Singleton &getInstance();
    void printId();

private:
    static int m_Id;
};

#endif
