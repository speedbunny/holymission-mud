inherit "/obj/weapon";
 
#include <objects.h>
#include <material.h>

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("kobold spear");
  set_alias_list(({ "spear", "javelin" }));
  set_weight(2);
  set_value(100);
  set_class(12);
  set_type(PIERCE);
  set_size(2);
  set_material(WOOD);
  set_short("A kobold's spear");
  set_long("A kobold's spear, which looks more like a javelin. "+
    "It isn't an incredibly large weapon, but it does get the "+
    "job done.\n");
}

