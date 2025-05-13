inherit "room/room";

#include "/players/skeeve/area.h"
#define CN capitalize(this_player()->query_name())

reset(arg) {
  object waternymph;
  if (!arg) {
    set_light(1);
    short_desc = "brooklet";
    long_desc = "";
    dest_dir =  ({
       LAND + "forest7", "east"
    });
    items = ({
       "brooklet", "",
       "water", "If you have a bottle, you can scoop some of it"
    });
  }
  waternymph=CASTLE->add_monster("waternymph",this_object());
  if (environment(waternymph)!=this_object())
    transfer(waternymph,this_object());
}

init() {
  ::init();
  add_action("scoop", "scoop");
  add_action("scoop", "fill");
}

waternymph_died () {
  long_desc = "You stand on the banks of a small brooklet.\n"
            + "The water in the brooklet is bloody.\n";
  items[1] = "A small brooklet with bloody water";
  items[3] = "This Water is to bloody to use it";
}

waternymph_born() {
  long_desc = "You stand on the banks of a small brooklet.\n"
            + "The water in the brooklet is very clean.\n";
  items[1] = "A small brooklet with very clean water";
  items[3] = "If you have a bottle, you can scoop some of it";
}

scoop(str) {
object bottle,waternymph;
if (( !str ) || 
    (( str != "water" ) && ( str != "water from bottle" )) ) return 1;
  
  if (!bottle = present ("bottle",this_player())) {
    write ("You have no bottle for the water!\n");
    say(CN + " scoops water but have no bottle!\n");
    return 1;
  }

  if (!waternymph = CASTLE->query_monster("waternymph")) {
    write("This water is to bloody to drink it.");
    say(CN + " wants to scoop water but its to bloody!\n");
    return 1;
  } else if (!present("ruby",waternymph)) {
    transfer (bottle,waternymph);
    write("As you wants to scoop water the waternymph steal your bottle\n"
         +"and says: If you want back your bottle you must\n"
         +"give me the ruby, which the snake has stolen.\n");
    say(CN +" wants to scoop water but the waternymph steals the bottle.\n");
    return 1;
  }

  if (bottle) {
    write("The bottle is now full with water.\n");
    say(CN + " fills a bottle with water.\n");
        
    destruct (bottle);
    bottle=clone_object(FOOD_DRINK+"waterbottle");
   
    if (transfer(bottle,this_player()))
      transfer(bottle,this_object());
  }
  return 1;
}
