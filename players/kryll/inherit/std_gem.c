inherit "/std/object";

#include <material.h>

nomask status query_door_payment() {
  return 1;
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_weight(1);
  set_material(GEMSTONE);
  set_size(1);
  set_can_get(1);
}
