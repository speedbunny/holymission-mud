inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("rat");
set_alias("man");
set_alt_name("fisher");
set_level(1);
set_hp(10);
set_gender(1);
set_aggressive(0);
set_short("A rat");
set_long("A rat scuttles around quickly.\n");
set_wc(1);
set_ac(1);
load_chat(30,({
"The rat squeaks.\n",
}));
return; }
