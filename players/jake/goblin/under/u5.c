inherit "room/room";
#include "/players/jake/defs.h"
object ob;
reset(arg) {
 if(!ob) {
 ob=clone_object("obj/monster");
 ob->set_name("Goblin apparition");
 ob->set_short("A goblin apparition");
 ob->set_alt_name("goblin");
 ob->set_alias("apparition");
 ob->set_long("This is the spirit of a long-dead goblin.\nHe doesn't seem to happy to see you.\n");
 ob->set_level(10);
 ob->set_align(-500);
 ob->set_aggressive(1);
  ob->add_money(500);
 move_object(ob,this_object());
}
 if(arg) return;
 set_light(0);
 short_desc = "Eastern tunnel with an apparition";
 long_desc  = "The tunnel smells of death and decay.  What appears to be blood\n" +
              "is smeared upon one of the earthen walls.  A small skull lies in\n" +
              "the pathway, and several other bones are sticking out of the wall.\n";
 items = ({
  "skull","Hmmm...Looks like that of a goblin!",
  "bones","Probably the rest of the goblin",
  });
 DD = ({
  UN + "u6","east",
  UN + "u4","west",
 });
 ::reset();
replace_program("room/room");
}
