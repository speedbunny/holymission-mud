inherit "/obj/monster";

#include "/players/matt/defs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("old dwarf");
  set_race("dwarf");
  set_short("An old dwarf");
  set_long("This small dwarf is very old, with thinning whitish hair.\n" +
	   "He looks very feeble indeed, and judging by the condition\n" +
	   "of his clothes and furnishings, he is very poor as well.\n");
  set_level(1);
  reduce_hit_point(50);
  set_gender(1);
  set_al(200);
  add_money(5);
  load_chat(20, ({
    "Dwarf groans: Please, please help me...\n",
    "The old dwarf twitches fitfully.\n",
    "Old dwarf looks at you pleadingly.\n",
    "Dwarf croaks: I need fruit from the Tree...\n",
    "Dwarf whispers: Find the Tree of Life.\n",
    "Dwarf croaks: Without the fruit I will surely die.\n",
    "Dwarf mutters: ...rumors...Eastern Forest...dreams...\n"
  }));
}

init() {
  ::init();
  add_action("give", "give");
}

give(arg) {
  object fruit, dwarf, gem;
  if(arg == "fruit to dwarf" || arg == "golden fruit to dwarf") {
    fruit = present("golden fruit", TP);
    if(fruit) {
      if((NWFORESTB + "rooms/b21")->query_planter() == TP->RNAME) {
	write("You give the golden fruit to the old dwarf.\n");
	say(TP->SNAME + " gives the golden fruit to the old dwarf.\n");
	TELLR(ENV(TO),
	      "He takes it in his shaking hands, and slowly eats it.\n");
	TELLR(ENV(TO),
	      "In a rush, color suddenly returns to the dwarf's face!\n");
	TELLR(ENV(TO),
	      "He sits up, rubs his eyes, and smiles warmly.\n");
	TELLR(ENV(TO),
	      "Dwarf says: Thank you, " + TP->SNAME + ".\n");
	TELLR(ENV(TO),
	      "Dwarf says: I am indebted to you. Please accept this.\n");
	write("The dwarf gives you something.\n");
	say("The dwarf gives something to " + TP->SNAME + ".\n");
	dwarf = clone_object(NWPLAINS + "monsters/young_dwarf");
	MOVE(dwarf, ENV(TO));
	dwarf->set_savior(TP);
        gem = clone_object(NWPLAINS + "objects/glowgem");
	transfer(gem, TP);
	TP->set_quest("cure_dwarf");
	write_file(LOGS + "cure_dwarf.log",
		   TP->SNAME + " solved the quest on " + ctime(time()) +
		   " at level " + TP->LEVEL + ".\n");
	destruct(fruit);
	destruct(TO);
	return 1;
      }
      write("The dwarf feebly refuses.\n");
      return 1;
    }
    write("You don't have that.\n");
    return 1;
  }
}

