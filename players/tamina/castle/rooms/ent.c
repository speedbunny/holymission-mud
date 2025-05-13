inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
   ::reset(arg);
   if (arg) return;

     set_light(1);
     short_desc = "Castle Entrance Hall";
     long_desc = 
"You have just passed under the ominous portcullis, that hangs\n"+ 
"precariously above the huge gates.  This is the Entrance Hall to the\n"+
"great castle of the renowned King Arthur, Camelot.  However, it looks\n"+ 
"largely deserted now, since word got out of the evil practices that\n"+
"are rumoured to be carried out within these walls.\n"+
"Ahead of you is the rather shabby-looking Courtyard.\n";
    
      dest_dir = ({
   CROOMS + "courtyard","north",
     });

      items = ({
  "portcullis",
"A large grate that is supposed to keep unwanted visitors out",
  "bridge",
"@@chk_bridge@@",
  "drawbridge",
"@@chk_bridge@@",
     });
}

string chk_bridge()
{
  if ("/players/tamina/castle/rooms/draw"->query_down() == 1)
    return 
"It is still fully functional, and made of real solid oak.  Fortunately  "+
"you can see that the drawbridge is in the lowered position, and you are "+
"free to leave...for just now..";
  else
    return "The bridge is raised, blocking any exit";
}

void init()
{
  add_action("my_south", "south");
  ::init();
}

int my_south()
{
  if ("/players/tamina/castle/rooms/draw"->query_down() == 1)
  {
    write("You leave Camelot, passing over the drawbridge.\n");
    MPL("south.#/players/tamina/castle/rooms/draw");
    return 1;
  }
  else
  {
    NFAIL("You cannot go south.\n"+
	  "The drawbridge is raised, blocking your exit.\n");
    return 0;
  }
}
