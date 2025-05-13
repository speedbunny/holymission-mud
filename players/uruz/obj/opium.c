
inherit "/obj/std_potion";
#include "/players/trout/defs.h"
#define MAX 0
#define SHADOW "/players/trout/psi/shadows/s_shad"


void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
	add_name(({"vial", "vial of opium"}));
	set_shadow(SHADOW, MAX);
	set_long("This is a vial of pure opium. It's a very powerful drug!"+
		" \n");
	set_value(1200);
	drink_msg= "You feel a rush as the opium takes effect. You seem to "+
	"be moving faster! \n";
     }
}

   

