inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("hooker");
set_alias("woman");
add_money(300+random(300));
set_al(700);
set_alt_name("fisher");
set_level(1);
set_hp(70);
set_gender(1);
set_aggressive(0);
set_short("A hooker");
set_long("A hooker struts around quickly.\n");
set_wc(1);
set_ac(1);
return; }
