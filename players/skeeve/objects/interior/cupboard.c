inherit "/obj/container";

#include "/players/skeeve/area.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("cupboard");
    set_alias("bag");
    set_max_weight(12);
    set_short("A cupboard");
    set_long("A brown wooden cupboard for the cooking tools.\n");
    set_value(0);
    set_weight(1);
    set_can_get(0);
  }
  if (!present("spoon"))
    move_object(clone_object(WEAPONS+"spoon"),this_object());    
  if (!present("bottle"))
    move_object(clone_object(FOOD_DRINK+"bottle"),this_object());
  CASTLE->add_interior("book",this_object());   
}
