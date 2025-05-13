#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg){
   if(arg) return;

     set_light(1);
     short_desc = "Kitchen ";
     long_desc = 
"As you take the north-eastern passage, you smell an awful stench coming\n"+ 
"from ahead.  It reminds you of rotten meat, and other foods.  But when\n"+ 
"you reach the end of the passage, you instantly recognise this room as\n"+ 
"being an old, disused kitchen, where the servants would have prepared\n"+ 
"King Arthur and his guests's meals.  Strewn around this rather large \n"+
"room are pots and pans or varying sizes and different states of possible\n"+ 
"usage.  There is a vacuous sink attached to the wall next to an old iron\n"+
"range.  To your left, you see another exit leading into a smaller room.\n";

     dest_dir = ({
   CROOMS + "reception","southwest",
   CROOMS + "pantry","pantry",
     });

     items = ({
  "sink",
"An enormous, empty sink, that is covered in rust", 
  "range",
"An old oven and hob that looks very heavy, and as though it hadn't been "+
"been used in some time",
  "pots",
"Empty copper pots",
  "pans",
"Empty copper pans",
     });

    ::reset (arg);

    RPR("room/room");
}

