inherit "room/room";

#include "/players/skeeve/area.h"
#include "/players/skeeve/door.h"

#define DN "simple wooden door"
#define DAN "simple door"
#define ID_D (str=="door")||(str==DN)||(str==DAN)
#define ROOM_ (COTTAGE+"anteroom")
#define DOOR_ ROOM_->query_door_e
#define DOOR_SET ROOM_->set_door_e

reset(arg) {
  object cupboard;
  if (!arg) {
    set_light(1);
    short_desc = "kitchen";
    long_desc = "You are standing in the kitchen.\n";
    smell = "You smell the delicious taste of a fishsoup";
    dest_dir = ({
        ROOM_, "west"
      });
    items = ({
      "west", "A "+DN,
      "door", "@@long_d",
      DAN,    "@@long_d",
      DN,     "@@>long_d"
      });
  }
  CASTLE->add_interior("stove",this_object());
  CASTLE->add_interior("kettle",this_object());
  cupboard=CASTLE->add_interior("cupboard",this_object());
  CASTLE->add_sphinx_obj("bellows",cupboard);
}

init () {
   ::init();
   add_action ("read","read");
   add_action ("open","open");
   add_action ("close","close");
   add_action ("lock","lock");
   add_action ("unlock","unlock");
}

long_d () {
  string s;
  s = "This door is simple made of wood.\n";
  if (!DOOR_())
    s += "It's something written on it in druidic letters.\n";
  if (DOOR_()) 
    s += "It's closed";
  else
    s += "It's open";
  return s;
}

read (str) {
  if (!str) return 0;

  if (ID_D) {
    if (DOOR_())
       write ("The writing is on the other side of the door.\n");
    else 
      if (this_player()->query_wis() > 10) 
        write ("Kitchen\n");
      else 
        write ("You are not wise enough to read the druidic language!\n");
    return 1;
  }
  return 0;
}

open _BEGIN
   _OPEN(ID_D,DN,DOOR_,DOOR_SET,ROOM_)  
_END

close _BEGIN
  _CLOSE(ID_D,DN,DOOR_,DOOR_SET,ROOM_)
_END

lock _BEGIN
  _NO_LOCK(ID_D,DN)
_END

unlock _BEGIN
  _NO_LOCK(ID_D,DN)
_END

_MOVE_BEGIN
  _MOVE("west",DN,DOOR_)  
_MOVE_END
