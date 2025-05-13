inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("little girl");
set_alias("girl");
set_al(800);
set_alt_name("fisher");
set_level(2);
set_gender(2);
set_aggressive(0);
set_short("A little girl");
set_long("A small girl who looks rather lost.\n");
set_wc(1);
set_ac(1);
load_chat(40,({
"The little girl smiles at you.\n",
"The little girl waves.\n",
}));
load_a_chat(70,({
"The little girl cries loudly!\n",
"The little girl looks terrified!\n",
}));
return; }
