#include "/players/tatsuo/def.h"
inherit "room/room";


void reset(int arg)
  
  if(arg) return;
    ::reset(arg);
    long_desc = "The path turns from dirt to a nice looking "+
                "cobblestone walkway that continues to the "+
                "southeast.  A building with a large water "+
                "wheel spinning at its side lies on the opposite "+
                "bank somewhat further south.  It appears to be "+
                "a mill.\n";

    short_desc = "On the path to the Halfling village";
 
  set_light(1);
  
  dest_dir = ({ HPATH+"p4","southeast", HPATH+"p2","northwest" });

  items = ({  {("walkway","path","cobblestones"}),"Someone went to "+
              "great care arranging them and landscaping them",
              ({"building","mill"}),"You can't reach it from this side "+
              "of the stream",
              ({"water wheel","wheel"}),"It makes the mill work",
              "bank","You see a small frog on the bank",
              "frog","The frog suddenly leaps at your throat/n"+
                     "ripping a HUGE chunk flesh from what used\n"+
                     "to be your airway.  As you feel your life\n"+
                     "slipping away the Frog says :\n\n"+
                     "'STOP LOOKING AT SHIT THAT ISN'T IMPORTANT!'\n\n"+
                     "The Frog hops away" });

   replace_program("room/room");
}


