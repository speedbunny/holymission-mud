inherit "room/room";
#include "/obj/door.h"
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "The Entrance to the Waiting rooms";
  long_desc =
    "This room serves as an ante-room to the throne room.  The room itself "+
    "is pretty plain.  To the west is a plain door.  To the east is a golden "+
    "door.  Both of the doors are wide open.  To the north is the Great Hall "+
    "of the kingdom.\n";
  set_light(1);
  items = ({
    "room","The ante-room to the throne room",
    "ante_room","The anteroom to the throne room",
    "door","A door leading to the waiting room",
    "doors","Two doors leading to the waiting rooms",
    "hall","The Great Hall",
  });
  dest_dir = ({
    br+"/grnd_hl.c","north",
    br+"/w-2.c","west",
    br+"/e-2.c","east",
  });
  clone_list = ({ 
    1, 4, "guard", bm+"/guard.c", 0,
//  1, 1, "cap", bm+"/c_guard.c", 0,
  });     
  
  ::reset(arg);
  replace_program("room/room");
}

