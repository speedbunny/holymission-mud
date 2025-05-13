inherit "/players/kryll/tmp/weapon";

#include <material.h>
#include <objects.h>

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("test longsword");
  set_alias_list(({ "longsword", "sword" }));
  set_short("A test longsword");
  set_long("This is a longsword used to test the new "+
           "weapon.c. It is not for any other purpose.\n");
  set_material(METAL);
  set_size(3);
  set_weight(4);
  set_value(4000);
  set_type(SLASH);
  set_class(15);
  set_magic(4);
}
