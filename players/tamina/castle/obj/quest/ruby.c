inherit "/obj/treasure";

#include "/players/tamina/defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("red ruby");
  set_weight(2);
  set_value(900 + random(500));
  set_short("A Red Ruby");
  set_long("A heavy ruby, that sparkles with a strange firey colour.\n"+
           "There is a strange writing glimmering in flames in the ruby...\n");
  set_read("...Death may not come to us in the pit, after all...\n");

}

int id(string str)
{
  return str == name || str == "ruby" || str == "quest_item" ||
	    str == "fire key";
}

