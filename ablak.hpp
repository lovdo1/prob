#ifndef ABLAK_HPP_INCLUDED
#define ABLAK_HPP_INCLUDED

#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include <vector>

class Ablak: public Widget
{
protected:
    std::vector<Widget *> k;
public:
    Ablak(int x,int y, int sx, int sy);
    ~Ablak();
    virtual void rajzol();
    virtual void event_loop(std::vector<Widget *> widgets);
    virtual void handle(genv::event ev);
};






#endif // ABLAK_HPP_INCLUDED
