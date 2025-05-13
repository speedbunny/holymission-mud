inherit "room/room";
#include "../valhalla.h"
reset (int arg)
{ object board;
  ::reset(arg);
  if(arg) return 0;


  if(!board)
  {
    board=clone_object(WIZ+"/valhalla/obj/mainboard");
        board->set_name("Valhalla's Main Board");
       board->set_file(WIZ+"/valhalla/obj/mainboard");
       board->set_short("Valhalla's Main Board");
    transfer(board,this_object());
  }

  set_light(1);
  short_desc="Valhalla gangway.",
  long_desc=
        "Valhalla gangway.\n"+
        "       You are in the gangway of Valhalla. The floor is\n"+
        "covered with cold strange looking fog. The wall to your left\n"+
        "is much warmer than the one to your right, besides this, the right\n"+
        "one looks much older than the left one. Strange isn't it?\n";

  items=({
        "way","It's a normal gangway",
        "gangway","It's a normal gangway",
        "fog","It looks really strange, perhaps it's magic",
        "wall","Wich wall do you want to examine",
        "right wall","It's colder and older than the left one",
        "left wall","It's warmer and looks a bit newer than the right one",
        "tower","You are inside it, you can't see very much",
        "castle","You are inside it, you can't see very much",
        "floor","You see the fog floating all around"
         });

   smell="It smell a bit foggy in here";

  dest_dir=({
	ROOM + "floor002","east",
	ROOM + "bridge","south",
	ROOM + "floor035","west",
            });
}
