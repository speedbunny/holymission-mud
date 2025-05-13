inherit "obj/treasure";
#include "atoi.h"

int get() { return 0; }

reset(int arg)
{ ::reset(arg);

  if(arg) return 0;

  set_alt_name("machine");
  set_name("gambler");
  set_id("The gambling-machine");

  set_short("The gambler");
  set_long(
	"The gambling-machine.\n\n"+
	"Here you can buy you opponents:\n"+
	"Use 'buy' plus the level of the mob you want to buy, for example\n"+
	"	buy 3.\n"+
	"Typing this you will put 3000 coins into the machine and a nice\n"+
	"level three monster will appear.\n");
}

void init()
{ ::init();
  add_action("mybuy","buy");
}

int mybuy(string arg)
{ object mob;
  int lvl,lvl1;

  lvl1=atoi(arg);
  lvl=lvl1*1000;
  if(!arg) return 0;
  else
  if(this_player()->query_money()>=lvl)
  { mob=clone_object("obj/monster");
    mob->set_name("orc");
    mob->set_level(lvl1);
    transfer(mob,environment(this_object()));
    return 1;}
  else
    return 0;
}
