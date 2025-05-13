/*  This is the Secret Passage  */

#include "/players/tamina/defs.h"
inherit "room/room";

reset(arg) {
if (arg) return;

     set_light(-3);
     short_desc = "Passage";
     long_desc =
"As you look aound, you see that this is an old, old passage, with dust\n"+ 
"piled so high on the floor, that it makes you cough uncontrollably.\n"+ 
"It smells very musty here.  The passage continues on north of here...\n";

      property = ({ "no_teleport" });

      dest_dir = ({
   CROOMS + "passage2", "north",
     });  
}

init() {
  ::init();

  if(query_verb() == "enter")
  write(
"You gingerly step into the Iron Maiden, being careful not to spear\n"+
"yourself...\n"+
"SLAMMMMM!!!!!!\n"+
"The door has closed behind you!!\n");

}
