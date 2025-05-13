
/* snake pit */

inherit "/room/room";

#include "defs.h"

int can_come;
string rope;
object orb;

void reset(int arg) 
{
    if (!arg)
    {
        set_light(1);
        short_desc = "You are in Kantele's snake pit";
        long_desc = BS(short_desc + ". You are surrounded by huge "+
        "brick walls. You wonder if you will ever be able to leave "+
        "this place. "+"@@is_rope@@");

        items = ({
        "pillar","It looks like you can tie a rope to it,\n"+
                 "but its too high up",
        });
     
        if (!orb)
        { 
            orb = clone_object("obj/treasure");
            call_other(orb, "set_name", "power orb");
            call_other(orb, "set_alias", "orb");
            call_other(orb, "set_value",5000);
            call_other(orb, "set_short", "An orb of power");
            call_other(orb, "set_long",
            "These powerful orbs are often needed to cast special spells.\n");
            call_other(orb, "set_alias", "gold orb");
            move_object(orb, this_object());
        }
    }
   can_come = 3;
}

string is_rope()
{
    if (call_other(PATH+"snake_room","query_rope"))
        return "There is a rope hanging down through the hole !";
    return "If you look up you see a small pillar.";
}

void init() 
{
  ::init();
  add_action("go_up","up"); 
  add_action("go_up","u"); 
  add_action ("my_up","climb");
  if (interactive(this_player()) && find_call_out("come_snake")==-1)
      call_out("come_snake",1);
}

void come_snake()
{
  if (can_come && filter_live(this_object(),"slittering snake") < 15)
  { 
      tell_room(this_object(),"You hear a hissing behind the stones.\n");
      CM("snake");
      call_out("come_snake",30);
  }
  else
    can_come--;
}

int go_up() 
{
    if (!call_other(PATH+"snake_room","query_rope"))
    {
        write("You can't go straight up with some kind of support.\n");
        return 1;
    }
    this_player()->move_player("up#"+PATH+"snake_room");
    return 1;
}

int tie(string str)
{
    return 0;
}


int untie(string str) 
{
    if (call_other("players/kantele/snake_room","query_rope")) 
    {
       write ("You can't reach the knot that fixes the rope.\n");
       return 1;
    }
    return 0;
}




