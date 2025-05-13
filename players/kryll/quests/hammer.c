inherit "/obj/weapon";

#include "/players/kryll/quests/quest_defs.h"
#include <material.h>

void reset(int arg){
  ::reset(arg);
  if(arg) return;

  set_name("maul");
  set_alias_list(({ "hammer", "Hobbe's Maul", "hobbe_quest_item" }));
  set_class(10);
  set_short("A large maul");
  set_long("This is Hobbe's maul. It has a wooden shaft and an iron "+
    "head. It looks to be used for a specific task and could break "+
    "if used for something else.\n");
  set_type(1);
  set_two_handed(1);
  set_value(80);
  set_size(3);
  set_material(IRON);
  set_weight(5);
  set_hit_func(this_object());
}

weapon_hit(ob) {
  write("You smash your maul against " + ob->query_name() + "\n");
  say(this_player()->query_name() + " smashes the maul against " +
      ob->query_name() + ".\n");
  if(!random(4)) {
    write("The maul breaks and the head flies off!\n\n");
    say("The maul breaks and the head of it flies past your own head.\n");
    HOBBE_QUEST->set_item("maul", 0);
    destruct(this_object());
    return 0;
  }
  return 1;
}

query_quest_object() {
  return 1;
}

drop(silently) {
  ::drop(silently);
  write("As the hammer leaves your hands, it suddenly vanishes!\n");
  HOBBE_QUEST->set_item("maul", 0);
  destruct(this_object());
  return 1;
}
