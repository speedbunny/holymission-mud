inherit "room/room";
#include "/players/jake/defs.h"
object king, obj;
reset(arg) {
if(!king) {
king=clone_object("/obj/monster");
king->set_name("Goblin King");
king->set_alias("king");
king->set_alt_name("goblin");
king->set_short("The Goblin King");
king->set_long("This is the Goblin King.  He rules over all of the goblin lands.\n" +
      "He is very powerful and wise, but something seems to be bothering him at\n" +
      "the moment.  Maybe if you 'talk to' him he could tell you what is wrong.\n");
king->set_level(20);
king->set_al(250);
king->set_ac(10);
king->set_male();
king->set_spell_mess1("The Goblin King smashes " + TPN + " with his bare fist.");
king->set_spell_mess2("The Goblin King smashes you with his bare fist.  You feel like dying!");
king->set_chance(20);
king->set_spell_dam(30);
move_object(king, this_object());
obj=clone_object("obj/weapon");
obj->set_name("heavy mace");
obj->set_alias("mace");
obj->set_class("10");
obj->set_value(2000);
obj->set_weight(2);
obj->set_short("A heavy mace");
obj->set_long("The goblin kings heavy war mace.  It has bashed the skull of many\n" +
     "an opponent.\n");
move_object(obj, king);
king->init_command("wield heavy mace");
}
if (arg) return;
 set_light(1);
 short_desc = "The Goblin Kings throne room";
 long_desc = "You have entered the Goblin Kings throne room.  The room is\n" +
  "lavishly decorated with silk tapestries, and beautiful ornaments of all\n" +
  "shapes and sizes.  Luxurious, thick carpeting covers the floor.  There are two\n" +
  "thrones that stand against the western wall, but only one seens to be used.\n" +
  "The empty thorne has a small picture sitting on it, and a small plaque lies\n" +
  "at the base of the throne.  A large chandolier hangs from the ceiling and\n" +
  "provides a brilliant light that brightens the room.\n";
 DD = ({
  KI + "k3","east",
      });
}
