inherit "room/room";

#include "/players/skeeve/area.h"
#include "/players/skeeve/door.h"

#define DN "reinforced wooden door"
#define DAN "reinforced door"
#define ID_D (str=="door")||(str==DN)||(str==DAN)
#define ROOM_ (COTTAGE+"anteroom")
#define DOOR_ ROOM_->query_door_w
#define DOOR_SET ROOM_->set_door_w

long_d () {
  string s;
  s = "This wooden door is reinforced with heavy sheets of steel.\n";
  if (!DOOR_())
    s += "It's something written on it in druidic letters.\n";
  if (DOOR_()) s += "It's closed";
  else       s += "It's open";
  return s;
}

read (str) {
  if (!str) return 0;
  if (ID_D) {
    if (DOOR_())
       write ("The writing is on the other side of the door.\n");
    else 
      if (this_player()-query_wis() > 10) 
        write ("Office\n");
      else 
        write ("You are not wise enough to read the druidic language!\n");
    return 1;
  }
  return 0;
}

reset(arg) {
  object manager;
  if (!arg) {
    set_light(1);
    short_desc = "Office";
    long_desc = 
         "This is the office of druid Lakmir's manager.\n"
       + "This room is devoid of any aesthetic warmth or beauty. It is purely\n"
       + "functional, with no concern for the trivialities of interior design.\n"
       + "The floor is stone inlay while the walls are of cracked terra cotta.\n"
       + "Through a passage in the north side of the room you can look into another room.\n";
    dest_dir = ({
        COTTAGE+"guardroom", "north",
        ROOM_, "east"
      });
    items = ({
      "passage","There is no door at this passage",
      "west", "A "+ DN,
      "door", "@@long_d",
      DAN,    "@@long_d",
      DN,     "@@long_d"
      });
  }  
  manager = CASTLE->add_monster("manager",this_object());
  if (environment(manager)!=this_object()) move_object(manager,this_object());
  CASTLE->add_interior("interior",this_object(),"painting");
}

init () {
   ::init();
   add_action ("read","read");
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
  _NO_LOCK(ID_D,DN)
_END

unlock _BEGIN
  _NO_LOCK(ID_D,DN)
_END

_MOVE_BEGIN
  _MOVE("east",DN,DOOR_)  
_MOVE_END
