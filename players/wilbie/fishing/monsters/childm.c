inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("little boy");
set_alias("boy");
set_al(800);
set_alt_name("fisher");
set_level(2);
set_gender(1);
set_aggressive(0);
set_short("A little boy");
set_long("A little boy is out making mischief.\n");
set_wc(1);
set_ac(1);
load_chat(40,({
"The little boy plays in the snow.\n",
"The little boy picks his nose.\n",
}));
load_a_chat(60,({
"The little boy screams!\n",
"The little boy yells for help!\n",
}));
return; }
