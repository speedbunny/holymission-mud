/*  This is the Barracks  */

#include "/players/tamina/defs.h"
inherit "room/room";

reset(arg) {

     set_light(0);
     short_desc = "Barracks";
     long_desc =
"This appears to have been the place where the personal Guard of \n"+
"King Arthur spent most of their time.  There is not much to see here, \n"+
"except old rusty swords, broken stools, and worn-out armour.\n"+
"There is a stairway against the far wall, leading both upwards and down.\n";

     dest_dir = ({
   CROOMS + "ewing1", "out",
   CROOMS + "barrd", "down",
   CROOMS + "barru", "up",
     });

     items = ({
  "swords",
"Very old, and covered in rust.  Not even worth the bother of "+ 
"cleaning your hands over",
  "stools",
"These at one time had three legs..but that was a long time ago",
  "stairs",
"As you peer up the staircase, the sudden draft almost blows out "+
"your torch.  Downwards, you can see nothing but pitch darkness.  "+
"Upwards, you can feel the very cold wind blowing against your "+
"face",
  "stairway",
"As you peer up the staircase, the sudden draft almost blows out "+
"your torch.  Downwards, you can see nothing but pitch darkness.  "+
"Upwards, you can feel the very cold wind blowing against your "+
"face",
  "armour",
"Old, cracked leather jerkins, of very poor quality",
      });

    ::reset (arg);

    RPR("room/room");

}
