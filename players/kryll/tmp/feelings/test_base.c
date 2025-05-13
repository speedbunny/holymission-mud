inherit "/players/kryll/tmp/base";

#include <material.h>

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("test object");
  set_alias_list(({"object", "test ob"}));
  set_material(METAL);
  set_size(2);
  set_weight(3);
  set_value(200);
  set_short("A test object");
  set_long("This is a test object to test out base.c. "+
           "Just making sure it works well.\n");
  set_read("You found the famous TEST OBJECT!!!!\n");
  set_info("The test object is nothing special.\n");
}
