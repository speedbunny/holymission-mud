inherit "room/room";
#include "/players/jake/defs.h"
object ob,we;
reset(arg) {
 if(!ob) {
 ob=clone_object("/obj/monster");
 ob->set_name("Goblin caretaker");
 ob->set_short("A goblin caretaker");
 ob->set_alias("goblin");
 ob->set_alt_name("caretaker");
 ob->set_level(10);
 ob->set_hp(500);
 ob->set_align(200);
 ob->set_long("A rather strong goblin.  His job is to take care of the\n"
            + "castle horses.\n");
 we=clone_object("/obj/weapon");
 we->set_name("whip");
 we->set_short("A whip");
 we->set_wc(10);
 we->set_weight(3);
 we->set_value(1500);
 we->set_long("A leather whip.  It would hurt to get hit by it!\n");
 move_object(we,ob);
 move_object(ob,this_object());

ob->init_command("wield whip");

}
 if(arg) return;
 set_light(1);
 short_desc = "An empty stall";
 long_desc  = "You are standing in a large horse stall.  The straw bed is\n" +
              "freshly raked, and the trough and water pail are both full.\n" +
              "There is a small pile of boards on the floor,  and it appears\n" +
              "that some of the stall boards are being replaced.\n";
 items = ({
 "pile","A small pile of boards",
 "boards","A small pile of boards",
 "bed","A bed made of straw for a horse",
 "trough","A wooden food trough",
 "pail","A water pail",
 });
 DD = ({
  CAS + "s9","east",
});
::reset();
replace_program("room/room");
}
