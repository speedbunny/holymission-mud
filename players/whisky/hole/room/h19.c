
 
inherit "room/room";
#include "../hole.h"
#include "/players/patience/GenObj/move_blocked.h"

object o1,m;
 
void reset(int arg) 
{
    if (!o1) { 
        o1=clone_object(MONST+"executor");
        move_object(o1,this_object());
        move_blocked(m=clone_object("obj/money"),
            this_object(),o1);
        m->set_money(10000+random(10000));
    }
    if (arg) return;
    set_light(0);
    short_desc = "In a dark hole";
    no_castle_flag = 0;
    long_desc = BS(
        "You are now on the last floor of the black hole. "
        + "The heat here burns your skin and you can hardly breathe. "
        + "You get the strange feeling that this is the home of a great "
        + "evil. Run away before you die ! "
        + "A tiny little corridor leads further up.");
    dest_dir = 
        ({
    PATH+"h18","up",
        });
}
 
