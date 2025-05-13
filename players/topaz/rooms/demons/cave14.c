inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {

     short_desc = "A small alcove";
     long_desc = "This small alcove is elaborately decorated.\n" +
                  "There are some paintings on the walls and the railing\n" +
                  "on the stairway leading up is encrusted with jewels.\n" +
                  "It seems peaceful here.\n";

      dest_dir = ({"players/topaz/rooms/demons/cave10","west",
                   "players/topaz/rooms/demons/cave15","up",
 
                     });

     items =({"alcove","This alcove is decorated nicely",
              "painting","Upon closer inspection, it shows a demon lady" +
                         " cutting a\ndwarf's heart out",
              "paintings","Upon closer inspection, they show hideous acts" +
                          " being performed\nby demon ladies",
              "wall","It has a painting on it",
              "walls","They have paintings on them",
              "stairs","They lead up",
              "stairway","It leads up",
              "railing","It sparkles with all the jewels",
              "jewels","They sparkle brightly",
              });
       set_light (1);
       smell = "You smell a light touch of perfume.";
  }
extra_reset();
}

extra_reset() {
object guard;
int i;

  if(present("guard",this_object())) return;
  for(i=0;i<3;i++) {
    guard=clone_object(MDEMONS + "queensguard");
    move_object(guard,this_object());
  }
}
