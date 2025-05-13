inherit "obj/soft_drink";

#include "/players/skeeve/area.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("water");
    set_alt_name("container");
    set_alias("clean water");
    set_short("A bottle of water");
    set_long("The water in this bottle is clean.\n");
    set_value(12);
    set_strength(1);
    set_drinking_mess(" drinks some clean water.\n");
    set_drinker_mess("What do you expect?\n");
    set_empty_container("bottle");
  }
}

init () {
  ::init();
  add_action ("pour","pour");
  add_action ("pour","fill");
}

pour (str){
string what,where;
object kettle;
if (!str) return 0;
  if (sscanf(str,"%s in %s",what,where) != 2) return 0;
  if (!what || !id(what)) return 0;
  if (!kettle = present(where,environment(this_player()))) {
    write("There is no "+ where +"!\n");
    say (capitalize(this_player()->query_name())
     + "attempts to pour the water from a bottle into a "+where+", but there is no "+where+"!\n");
    return 1;
  }
  full = 0;
  food = 0;

  move_object(clone_object(FOOD_DRINK+"water"),kettle);;
  tell_room(environment(this_player()),"gluck, gluck, gluck,...\n");
  return 1;
}
