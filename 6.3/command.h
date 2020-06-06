#ifndef _COMMAND_H_
#define _COMMAND_H_

class Text;

//did not consider about copy control
class Command
{
public:
    virtual ~Command() = default;

public:
    virtual void execute() const = 0;
    virtual void undo() const = 0;
};

class PasteCommand : public Command
{
public:
    PasteCommand(Text * const SomeText)
    : m_Text(SomeText)
    {
    }

public:
    virtual void execute() const override;
    virtual void undo() const override;

private:
    Text *m_Text;
};

#endif
