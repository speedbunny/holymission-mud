inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("guard");
set_alias("man");
set_al(700);
add_money(700);
set_alt_name("fisher");
set_level(10);
set_gender(1);
set_aggressive(0);
set_short("A guard");
set_long("A member of the Fuzhao village militia.  He is keeping an eye out "+
"for troublemakers like you.\n");
set_wc(2);
set_ac(1);
set_spell_mess1("The guard throws a hard elbow!");
set_spell_mess2("You are hit in the face with an elbow!");
set_chance(30);
set_spell_dam(10);

load_chat(30,({
"The guard eyes you with caution.\n",
"The guard looks around for trouble.\n",
}));
load_a_chat(60,({
"The guard glares at you.\n",
"The guard calls for backup!\n",
"The guard eyes you angrily.\n",
}));
return; }
