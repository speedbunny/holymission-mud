inherit "/obj/monster";
#include "../meadow.h"

  reset(arg) {
  ::reset(arg);
  if (!arg) {
 
   set_name("butterfly");
   set_level(1);
   set_size(1);
   load_chat(4,({"F l a p p ....\n"}));
   set_short("A butterfly");
   set_long("A nice little butterfly.\n");
   set_race("insect");
   set_whimpy();
}
}
