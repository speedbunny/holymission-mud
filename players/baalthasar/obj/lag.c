inherit "obj/treasure";
#include "/players/baalthasar/shadows/path.h"

object plyr;

reset(arg) {
if(arg) return;
  set_id("Lag");
  set_short("A bunch of lag");
  set_alias("lag");
  set_long("You feel an overwhelming sense of dispair as you realize you have lag. \n");
  set_value(1);
  set_weight(4);

  }
drop() {
write("You try your best, but you just can't seem to lose the lag. \n");
say(this_player()->query_name()+" tries to escape the lag, but fails! \n");
return 1;
 }
