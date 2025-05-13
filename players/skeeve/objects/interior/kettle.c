inherit "/obj/container";

#include "/players/skeeve/area.h"

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("kettle");
  set_max_weight(12);
  set_short("A medium kettle");
  set_long("It's a medium kettle. It smells like a fishsoup.\n");
  set_value(100);
  set_weight(2);
  set_can_get(0);
}

init() {
    add_action("stir", "stir");
    add_action("scoop", "scoop");
}

stir(str) {
  object kettle, stove,spoon;
  kettle = this_object();
  stove = present("stove",environment(kettle));
  if (!stove->query_hot_enough()) {
    write ("First you shout heat the soup!\n");
    return 1;
  }
  if (!(this_player()->query_wielded()) 
   || !(this_player()->query_wielded())->id("spoon")) {
    write ("Autsch!!! This kettle is to hot to do that whithout spoon.\n");
    this_player()->hit_player(random(10),7);
    return 1;
  }
  if (!str || !((str == "water") || (str == "kettle") 
   || (str == "soup") || (str == "fishsoup"))) return 0;
  if  (  !present("cook water", kettle) 
      || !present("salmon fillet", kettle) 
      || !present("herring fillet", kettle)
      || !present("tunny fillet", kettle)
      || !present("perch fillet", kettle)
      || !present("cod fillet", kettle)
      )
    write("Something is missing ?\n");
  else {
    destruct(present("cook water", kettle));
    destruct(present("salmon fillet", kettle));
    destruct(present("herring fillet", kettle));
    destruct(present("tunny fillet", kettle));
    destruct(present("perch fillet", kettle));
    destruct(present("cod fillet", kettle));
    transfer (clone_object(FOOD_DRINK+"fishsoup"),kettle);
    write("The fishsoup is ready.\n");
  }
  return 1;
}

scoop(str) {
object bottle,soup;
  if (!str || !(  (str == "soup") || (str == "fishsoup")
                ||(str == "soup in bottle") || ("fishsoup in bottle")) )
     return 0;
  
  if (!soup = present("fishsoup",this_object())) {
    write ("There is no fishsoup in this kettle!\n");
    say(capitalize(this_player()->query_name())
     + " scoops fishsoup but but there is no fishsoup to scoop!\n");
    return 1;
  }
  if (!bottle = present ("bottle",this_player())) {
    write ("You have no bottle for the fishsoup!\n");
    say(capitalize(this_player()->query_name())
     + " scoops fishsoup but have no bottle!\n");
    return 1;
  }

  if (bottle) {
    write("The bottle is now full with fishsoup.\n");
    say(capitalize(this_player()->query_name())
     + " fills a bottle with fishsoup.\n");
     
    destruct (soup);  
    destruct (bottle);
    bottle=clone_object(FOOD_DRINK+"fishsoupbottle");
   
    if (transfer(bottle,this_player()))
      transfer(bottle,environment(this_object()));
  }
  return 1;
}
