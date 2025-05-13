inherit "room/room";
 
// Contains the door and key macros needed to make the objects.
#include "/obj/door.h"
 
// Must declare these global objects. The doors must be called obj_1 and
// obj_2 because of the macro but the key can be anything.
object obj_1, obj_2, key;
 
void reset(int arg) {
 
// Checks to see if the door is in the room
// the MAKE_ROOMS macro is in the /obj/door.h header file and
// will be used until something better is done.
// the order of parameters is = this room, direction, other room where
//     you'll go out to, direction in the other room, lock type, code
//     for door (only keys with this code unlocks it), long desc,
//     whether closed or not (1=closed, 0=open), whether locked or
//     not (1=locked, 0=unlocked), whether it can be locked (1=can,
//     0=cannot)
// also note that a macro call must be all on one line or a "\" must
// be after the last letter and then continued on the next line. this
// is due to the C-interpreter.
  if(!present("door")) {
    MAKE_DOORS("/doc/examples/exa07", "south", "/doc/examples/exa08",\
               "north", "metal", "key002",\
               "This is an old wooden door, but it is still strong.\n",\
               1, 1, 1);
  }
 
// check for a key and if not one, make one using another macro.
// the order of parameters is = the key object, key type, key code
// then you must move the key to the room. the room macro
// automatically moves the doors to the appropriate rooms, but the
// key macro does not.
  if(!present("key")) {
    MAKE_KEY(key, "metal", "key002");
    move_object(key, this_object());
  }
 
  ::reset(arg);
  if(arg) return; /* Don't do anything except on initialisation */
 
  set_light(1);
  short_desc = "Cellar";
 
  long_desc =
    "This is the cellar of the house. You can see several wine "+
    "barrels on the ground.\n";
 
  dest_dir = ({
    "/doc/examples/exa06", "west",
    "/doc/examples/exa08", "south",
  });
 
  items = ({
    "barrels", "Old empty wine barrels",
    "ground", "It is what you are standing on",
    "cellar", "You are in it",
  });
}
