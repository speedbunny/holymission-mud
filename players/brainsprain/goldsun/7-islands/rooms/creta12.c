inherit "/players/brainsprain/goldsun/7-islands/rooms/creta9";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
    clone_list= ({
               1, 2, "squirrel", "obj/monster", ({"set_name","squirrel",
                                                  "set_alias","monster",
                                                  "set_race","squirrel",
                                                  "set_level",1,
                                                  "set_long",
"This chittering red squirrel hops from the ground to the tree and back "+
"down again.  It grabs acorns off of the ground and stuffs it's mouth. "+
"This squirrel has red fur and a scraggly tail.  It is somewhat smaller "+
"than the gray squirrels you might have seen.",
                                                  "set_short","Red squirrel",
                                                  "set_ac",2,
                                                  }),
                          });
 ::reset(arg);
 long_desc=
"You are in the dense forest between Madaros and Idhe.  Many different "+
"kinds of trees grow up towards the sky.  They have been here for "+
"thousands of years. The ground is covered by grass and moss. Fog plays "+
"between the branches above and make fantastic figures.\n";
 items = ({
    "mountains","Madaros and Idhe.  They are very high"
    "mountain","the tall mountain to the north is named Idhe",
    "idhe","It is a tall mountain to the north",
    "madaros","It is a very tall mountain",
     });

dest_dir=({ 
    ir+"/creta10", "west",
    ir+"/creta16","east"
           });

}

