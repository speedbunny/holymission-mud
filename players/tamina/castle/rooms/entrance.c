#include "/players/tamina/defs.h"

inherit "room/room";

void reset(int arg) 
{
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
   "/players/emerald/arthur/rooms/draw","south",
     });

      items = ({
  "portcullis",
"A large grate that is supposed to keep unwanted visitors out",
  "bridge",
"It is still fully functional, and made of real solid oak.  Fortunately  "+
"you can see that the drawbridge is in the lowered position, and you are "+
"free to leave...for just now..",
  "drawbridge",
"It is still fully functional, and made of real solid oak.  Fortunately  "+
"you can see that the drawbridge is in the lowered position, and you are "+
"free to leave...for just now..",
     });
}
