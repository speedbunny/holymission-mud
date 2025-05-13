inherit "/obj/armour";
#include "/spells/spell.h"
reset(arg){
::reset(arg);

set_name("Temperal Helm");
set_alias("helm");
set_short("Temperal Helm");
set_long("This is a temperal helm worn by the Vagabonds to keep there\n"+
         "minds safe as they move through time. The helm doe not look\n"+
         "like it would offer much protection.\n");
set_weight(2);
set_value(10000);
set_ac(2);
set_type("helmet");
modify_resistance(MINDEFFECTIVE, 10);
}
