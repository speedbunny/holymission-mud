inherit "room/room";

#include "/players/skeeve/area.h"
#include "/players/skeeve/door.h"

#define DN "crafted wooden door"
#define DAN "crafted door"
#define ID_D (d=="door")||(d==DN)||(d==DAN)
#define ROOM_ (COTTAGE+"anteroom")
#define DOOR_ ROOM_->query_door_n
#define DOOR_SET ROOM_->set_door_n
#define KEY_ "crafted"
#define KEY_CODE "skeeve2"

long_d () {
  string s;
  s = "It's a finely crafted wooden door. Even though this\n"
    + "door is only an inch thick, it is very sturdy. \n";
  if (DOOR_()) s += "It's closed";
  else       s += "It's open";
  return s;
}

reset(arg) {
  object obj;
  if (!arg) {
    set_light(1);
    short_desc = "sittingroom";
    long_desc = "This sittingroom is an extravagant, luxurious room, "
       +"yet it feels strangely oppressive. This room is dominated by "
       +"a large fireplace set in a red brick wall. Thick beams line the "
       +"ceiling, while a window breaks up the stone supporting wall.\n";
    smell="You smell the scent of burned wood";
    dest_dir = ({
        COTTAGE+"bedroom", "east",
        ROOM_, "south"
      });
    items = ({
      "south", "A "+ DN,
      "door", "@@long_d",
      DAN,    "@@long_d",
      DN,     "@@long_d",
      "window", "Through this portal you can see the moon hovering "
               +"over the Darken Mountains\n",
      "fireplace", "Dried timbers rest within the fireplace",
      "timbers",   "Some half burned timbers",
      "wall",      "There is  window in the wall",
      "beams",     "The beams are made of fine carved wood",
      "ceiling",   "Thick beams line the ceiling"
      });
  }
  CASTLE->add_interior("rug",this_object(),1);
  CASTLE->add_interior("interior",this_object(),"table");
  CASTLE->add_interior("interior",this_object(),"couch");
  CASTLE->add_interior("interior",this_object(),"goblet");
  CASTLE->add_interior("interior",this_object(),"poker");
  CASTLE->add_interior("interior",this_object(),"tapestry");
  CASTLE->add_interior("interior",this_object(),"poker");
  CASTLE->add_interior("interior",this_object(),"brazier");
}

init () {
   ::init();
   add_action ("open","open");
   add_action ("close","close");
   add_action ("lock","lock");
   add_action ("unlock","unlock");
}

open _BEGIN
   _OPEN(ID_D,DN,DOOR_,DOOR_SET,ROOM_)  
_END

close _BEGIN
  _CLOSE(ID_D,DN,DOOR_,DOOR_SET,ROOM_)
_END

lock _BEGIN
  _LOCK(ID_D,DN,KEY_,KEY_CODE,DOOR_,DOOR_SET,ROOM_)
_END

unlock _BEGIN
  _UNLOCK(ID_D,DN,KEY_,KEY_CODE,DOOR_,DOOR_SET,ROOM_)
_END

_MOVE_BEGIN
  _MOVE("south",DN,DOOR_)  
_MOVE_END
