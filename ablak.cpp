#include "ablak.hpp"
#include "examplecheckbox.hpp"
#include "widgets.hpp"
#include <vector>
#include <string>
using namespace genv;

Ablak::Ablak(int x, int y, int sx, int sy): Widget(x, y, sx, sy)
{
    ExampleCheckBox *g = new ExampleCheckBox(13,13,30,30);
    k.push_back(g);

}

void Ablak::event_loop(std::vector<Widget*> widgets)
{
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (Widget * w : widgets) {
            w->rajzol();
        }
        gout << refresh;
    }
}

void Ablak::rajzol()
{
    gout.open(1000,1000);

    for(Widget *d:k)
    {
        d->rajzol();
    }
    event_loop(k);
    gout << refresh;
}

void Ablak::handle(event ev)
{

}
