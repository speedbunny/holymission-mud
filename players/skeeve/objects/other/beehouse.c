inherit "/obj/thing";

#include "/players/skeeve/area.h"

reset(arg) {
int i;
  ::reset(arg);
  if (!arg) {
    set_name("bee-house");
    set_alias("beehouse");
    set_short("A yellow beehouse");
    set_long("It's a house for honeybees.\n"
            +"What a wunderfull perfume, but who makes that nasty sound\n");
    set_weight(10);
  }
}

init() {
  add_action("open", "open");
  add_action("smell","smell");
  add_action ("hear","hear");
}

smell (str) {
  if (!str || !id(str)) return 0;
  write("You smell the pleasant perfume of sweet honey from the beehouse.\n");
  return 1;
} 
hear (str) {
  if (!str || !id(str)) return 0;
  write("You hear a swarm of honey bees.\n");
  return 1;
} 
    
open (str) {
  object bees, ob;
  if (!str || !id(str)) return 0;

  write("As you open the beehouse, it breaks into 1000 pieces.\n"
       +"The bees are angry about this!\n");
  say("As "+this_player()->query_name() + " opens a " + name 
     +", it breaks into 1000 pieces.\n");

  move_object(clone_object(FOOD_DRINK+"honey"),environment(this_player()));
  move_object (bees = clone_object(MONSTERS+"bees"),environment(this_player()));
  bees->attacked_by(this_player());
  if (ob=this_player()->query_attack()) bees->attacked_by(ob);

  destruct(this_object());
  return 1;
}
