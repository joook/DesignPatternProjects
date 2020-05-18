#ifndef _COMMAND_H_
#define _COMMAND_H_

class Text;

//did not consider about copy control
class Command
{
public:
    Command(Text * const SomeText)
    : m_Text(SomeText)
    {
    }

    virtual void execute() const = 0;
    virtual void undo() const = 0;

public:
    Text *m_Text;
};

class PasteCommand : public Command
{
public:
    PasteCommand(Text * const SomeText)
    : Command(SomeText)
    {
    }

    virtual void execute() const override;
    virtual void undo() const override;
};

#endif
