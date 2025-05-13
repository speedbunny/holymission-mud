
inherit "room/room";
#include "/players/whisky/genesis/sys/filter_live.h"
#define _to this_object()
#define _mob "/players/muzmuz/island/monsters/"

void reset (int arg) 
{
   if (!present("zwergnase",_to))
      move_object(clone_object (_mob+"zwergnase"),_to);

   if (filter_live(this_object()) < 4)
   {
       move_object(clone_object (_mob+"sandworm"),_to);
       move_object(clone_object (_mob+"sandworm"),_to);
       move_object(clone_object (_mob+"sandworm"),_to);
       move_object(clone_object (_mob+"sandworm"),_to);
   }
  if (!arg) 
  {
      short_desc = "chamber";
       long_desc = "You managed to reach the dune chamber. Here is the residence of the evil\n" +
                   "Zwergnase, the master of Sandworms.\n";

        dest_dir = ({"players/muzmuz/island/rooms/fd","out"});
       
     }
}


                     
