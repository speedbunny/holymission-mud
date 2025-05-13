
inherit "room/room";
#include "../garden.h"

#define env environment
object kill_ob;

reset(arg) {
  if (!arg) {
    set_light(1);
    property = "no_teleport";
    short_desc="Inside the oven";
    long_desc = "You are inside an burning oven, it's incredibly hot !\n";
  }
}

init() {
object ob;

  move_object(ob=clone_object(OBJ+"/flames"),this_object());
  if (this_player()) {
     ob->burn_player(this_player());
     if (!this_player()->query_wizard()) add_action("block","",1);
  }
  else destruct(ob);
}

block() {
  if (this_player()->query_ghost()) {
     write("\n\nYour smoking remains pass through an opening in the oven ...\n\n");
     move_object(this_player(),ROOM+"/house2");
     say("Smoking remains of "+capitalize(this_player()->query_real_name())+
	" arrives.\n");
     command("look",this_player());
     return 1;
  }
}

burn_player(ob) { kill_ob=ob; }
