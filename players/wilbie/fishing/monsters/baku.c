inherit "/obj/monster";
#include "/players/wilbie/def.h"
reset(arg){
::reset(arg);
if(arg)return;
set_name("baku");
set_alias("demon");
set_short("An Evil Kappo");
set_long("This evil demon looks like a large lobster, but with the face and "+
"limbs of a human!  It looks rather angry!\n");
set_level(10);
set_aggressive(1);
set_al(-555);
add_money(234);
return; }
