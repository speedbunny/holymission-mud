inherit "room/room";

#include "/players/tamina/defs.h"
#define env environment

object kill_ob;

reset(arg) {
  if (!arg) {

    set_light(1);
    short_desc = "River of Lava";
    long_desc = 
"    You are standing amidst the river of Lava which ran\n"+
"    alongside the path from which you just rather stupidly\n"+
"    jumped.  All about you is burning hot molten rock, frying\n"+
"    your skin.\n";

    property = "no_teleport";

   }
}

init() {
object ob;

  MO(ob = CLO(FIRE + "lava"),TO);
  if (TP) 
  {
     ob->burn_player(TP);
     if (!TP->query_wizard()) add_action("block","",1);
  }
  else destruct(ob);
}

block() 
{
  if (TP->query_ghost()) 
  {
     write("\nYour charred body manages somehow to pull itself out of \n"+
           "the lava pool eventually ...\n\n");
     MO(TP, FIRE + "rm4");
     TRM(FIRE + "rm4", "Charred pieces of "+CAP(TPN)+" arrives.\n");
     command("look", TP);
     return 1;
   }
}

burn_player(ob) 
{
  kill_ob = ob; 
}
