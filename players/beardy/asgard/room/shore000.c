inherit"room/room";
#include "../asgard.h"

reset(int arg)
{ ::reset(arg);
  if(arg) return 0;

  set_light(1);
  short_desc="River.",
  long_desc="You are in the middle of a river.\n"+
            "Perhaps it's better to turn round.\n";

  items=({
            "grass"    ,"Believe me there is no grass",
            "trees"    ,"You see no trees at all",
            "mountains","They are very far in the north",
            "silhouette","You see the faint silhouette of some mountains",
            "river"     ,"You suppose there is a way to cross it"
         });

   smell="The air smells fresh in here";

   dest_dir= ({ ROOM + "shore001","south"});
  // hidden_dir=({ ROOM + "shore024","north"});

}
