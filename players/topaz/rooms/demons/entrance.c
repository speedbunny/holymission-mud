inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {

     short_desc = "A dark cavern";
      long_desc = "You are in a small cave.\n" +
                  "There is just barely enough light to see by.\n" +
                  "You see blood stains on the cave walls.\n" +
                  "\n" +
                  "You feel that there is great evil deeper in the cave.\n" +
                  "It might be a good idea if you left now!\n";

      dest_dir = ({ATTACH + "clearing","north",
                   DEMONS + "cave1","southeast",
 
                     });

     items =({"cave","You're in it!  You feel nervous",
               "wall","It is covered in blood",
               "walls","They are covered in blood.  You feel sick",
               "blood","It looks like there was some kind of massacre here"});

        set_light (1);
        smell = "You definately smell blood.";
    }
}

init(){
  ::init();

       add_action("southeast", "southeast");
       }

southeast(){
  if(this_player()->query_level()>=10)
    {this_player()->move_player("southeast#players/topaz/rooms/demons/cave1");
         return 1; }
    else {
         write("You don't feel experienced enough to enter this area.\n");
         return 1; }
}
