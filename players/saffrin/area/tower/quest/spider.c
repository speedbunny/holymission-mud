/* Coded by Llort */
/* Spruced up by Saffrin */

inherit "obj/monster";
#include "/players/saffrin/area/tower/quest/cellar.h"

reset(arg) {
    ::reset(arg);
    if(!arg) {

	set_name("black spider");

	set_alias("spider");

	set_short("A big black spider");

	set_long("A big blakc spider with eight long, thin legs.  Its rounded\n"+
	  "and glassy eyes are watching you intently.\n");

	set_race("insect");

	set_level(1);

	set_size(1);

	set_al(-100);

	set_aggressive(1);
    }
}
