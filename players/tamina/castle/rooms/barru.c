/*  This is the Barracks - 1st floor  */

#include "/players/tamina/defs.h"

inherit "room/room";
status has_cloned;
object ob,*ghosts;

void reset(int arg) 
{
  ob = present("ghoul");
  if (!ob || !living(ob))
  MO(CLO(CMONS + "ghoul"), TO);

  if(arg) return;
  ghosts = allocate(3);

     set_light(1);
     short_desc = "Barracks -  First Floor ";
     long_desc =
"As you mount the stairs, a dreadfully cold gust of wind smacks you in \n"+
"face.  Your torch flickers dangerously in the strong breeze...\n"+
"You notice how bare this room looks: there are no pieces of furniture\n"+
"whatsoever here.  To add to the drab decorations, there are several holes\n"+
"in the walls, and cracks in the roof. \n";     
 
    dest_dir = ({
   CROOMS + "barracks", "down",
     });

     items = ({
  "holes",
"You can see through these, with the bare moors being the cheery view",
  "decorations",
"They are very depressing, and dull indeed",
  "walls",
"They are in very bad condition here, and you wonder how this "+
"small tower has managed to remain upright",
  "roof",
"The roof is in very poor condition as well, with large cracks "+
"and even some holes where you can see the overcast sky above",
      });

}

init() {
  ::init();
  call_out("ghosts",10,TP);
}

ghosts (obj) {

 int i;
 int num_ghosts;

  if ( has_cloned == 1 ) return ;

  if (!present(obj,TO)) return ;

  if (num_ghosts == 3) return ;

  for (i = 0; i < 3; i++) {
    if (!ghosts[i]) {
       ghosts[i] = CLO(CMONS + "ghost");
       transfer(ghosts[i], TO);

      has_cloned = 1;
    }
    else num_ghosts++;
  }

  TRM(TO,
   "\nAs if from nowhere, a sudden wailing, and shrieking pierces the air!!\n\n"+
   "White sheets and cloth appear, flying in the air.\n"+
   "And, there appeared three ghosts to wreak their revenge!!\n");

  return 1;

}
