inherit "room/room";
#include "/players/jake/defs.h"
object rat,tail;
int i;
reset(arg) {
if(!rat) {
for(i=0;i<3;i++) {
 rat=clone_object("obj/monster");
 rat->set_name("Large rat");
 rat->set_short("A large rat");
 rat->set_alias("rat");
rat->set_level(5);
 rat->set_align(250);
 rat->set_whimpy(50);
 rat->set_long("A large rat.\n");
 rat->set_race("rat");
 tail=clone_object("obj/treasure");
 tail->set_name("Rat tail");
 tail->set_short("A rat tail");
 tail->set_long("The tail of a rat.\n");
 tail->set_alias("tail");
 tail->set_value(25);
 
 tail->set_weight(1);
 move_object(tail,rat);
 move_object(rat,this_object());
}
 if(arg) return;
 set_light(1);
 short_desc = "Under a grate";
 long_desc  = "The tunnel ends rather abruptly here.  Light shines down through\n" +
              "an iron grate in the ceiling above you.  Footsteps and voices can\n" +
              "be heard from the room above.  Glancing briefly at the walls of\n" +
              "the tunnel in which you stand, you realize that there is no way to\n" +
              "climb up to the grate.\n";
 items = ({
  "grate","An iron grate.\nUnfortunately you can't climb up to it",
  "walls","These dirt walls offer no way of climbing up them",
  });
 DD = ({
  UN + "u2","south",
  });
 ::reset();
 replace_program("room/room");
}
}
