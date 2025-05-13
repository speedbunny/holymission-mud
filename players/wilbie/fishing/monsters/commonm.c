inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("commoner");
set_alias("man");
set_al(700);
add_money(500);
set_alt_name("fisher");
set_level(5);
set_hp(70);
set_gender(1);
set_aggressive(0);
set_short("A commoner");
set_long("A commoner walks around quickly.\n");
set_wc(1);
set_ac(1);
load_chat(30,({
"The man looks at you and waves.\n",
"The man looks for some work to do.\n",
}));
return; }
