inherit "obj/thing";
#include "/players/redsexy/defs.h"

drop(arg) {
  if(!arg) {
    write("The sand trickles through your fingers!\n");
    say("Some sand blows into your face. \n");

  }
  destruct(TO);
  return 1;
}


reset(arg) {
  ::reset(arg);
  if(!arg) {

    set_name("sand");
    set_alias("sand");
    set_short("Sand");
    set_long("Some Sand.\n");
    set_can_get(1);
     }
}


