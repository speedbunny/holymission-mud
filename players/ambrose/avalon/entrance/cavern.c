#include "/players/ambrose/defs.h"

inherit "room/room";

reset(arg) {
if(!present("guard")){
   move_object(clone_object("/players/ambrose/avalon/monsters/guard"),this_object());
   }
if (arg)return;
set_light(1);
property=({"no_teleport"});
short_desc = "A large underground Cavern";
long_desc =
 "This part of the cave opens up into a immense cavern.  The ceiling of\n"
+"the cave is lost far above you in the darkness.  Most of the light in\n"
+"the room comes from the doors of a gigantic gate directly in front of\n"
+"you.  The doors are made entirely of mithril, and seem to be glowing\n"
+"with a soft blue light.  The rock formations surrounding the door seem\n"
+"to be carved into pictures of warriors.  There is a guard post near the \n"
+"gate.\n";
dest_dir = ({
         "/players/ambrose/avalon/entrance/entran3","west",
      });
items = ({ "formations","They look like warriors, frozen in combat",
           "gate","Made up solid Mithril, it towers above you",
           "doors","Mithril doors covered in swirling designs."});
}

init() {
  ::init();
  add_action("enter","enter");
  }
enter(str){
  notify_fail("Enter what?\n");
  if(str!="gate")return;

  if(!present("guard")){
     MOVEP("through the gate#players/ambrose/avalon/entrance/cliff");
  }else{
   write("The guard blocks your way.\n");
 }
 return 1;
  }
