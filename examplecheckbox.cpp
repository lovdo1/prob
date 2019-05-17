#include "examplecheckbox.hpp"
#include "graphics.hpp"
using namespace genv;

ExampleCheckBox::ExampleCheckBox(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    _checked=false;
}

void ExampleCheckBox::rajzol()
{
    gout <<color(255,255,255) << move_to(0,0) << box(500,500);
    for(int j=0;j<15;j++){
    for(int i=0;i<15;i++){
    gout << move_to(_x+i*_size_x, _y+j*_size_y) << color(0,0,0) << box(_size_x, _size_y)<< move_to(_x+i*_size_x+4, _y+j*_size_y+4) << color(200,200,200) << box(_size_x-8, _size_y-8);
    }

    }
    //gout << move_to(_x+_size_x, _y) << color(0,0,0) << box(_size_x, _size_y)<< move_to(_x+_size_x+4, _y+4) << color(200,200,200) << box(_size_x-8, _size_y-8);
    if (_checked) {
        gout << color(255,255,255);
        gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
    }
}

void ExampleCheckBox::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _checked = !_checked;
    }
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = !_checked;
    }
}
bool ExampleCheckBox::is_checked()
{
    return _checked;
}
