inherit "room/room";
#include "/players/whisky/genesis/sys/filter_live.h"
#define _to this_object() 

object ob;


void reset (int arg) 
{
  if (!objectp(ob))
  {
     ob = clone_object("players/muzmuz/island/monsters/zonk");
     move_object (ob,this_object());
  }
  if (filter_live(this_object()) < 3)
  {
    move_object(clone_object ("players/muzmuz/island/monsters/mudmonster"),_to);
    move_object(clone_object ("players/muzmuz/island/monsters/mudmonster"),_to);
    move_object(clone_object ("players/muzmuz/island/monsters/mudmonster"),_to);
  }
  if (!arg) 
  {
    short_desc = "chamber";
    long_desc = "You managed to reach this chamber. It is dark, cool and wet here. \n" +
                 "This is also the residence of Zonk, the owner of Mudmonsters.\n";

      dest_dir = ({"players/muzmuz/island/rooms/fn","out"});

    }
}

