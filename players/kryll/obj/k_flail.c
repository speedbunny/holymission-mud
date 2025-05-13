inherit "/obj/weapon";

#include <material.h>
#include <objects.h>

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("kobold flail");
  set_alias_list(({ "flail" });
  set_weight(2);
  set_value(100);
  set_class(10);
  set_type(BLUDGEON);
  set_size(2);
  set_material(METAL);
  set_short("A kobold's flail");
  set_long("A kobold's flail. It looks like it was made\n" +
           "by kobolds and should be incinerated\n");
}

