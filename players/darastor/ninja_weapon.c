inherit "/obj/weapon";

#include <properties.h>

void reset(int arg)
{
    ::reset(arg);

    if(!arg)
    {
	add_property("ninja_weapon",1);
	set_hit_func(this_object());
    }
}

int weapon_hit(object attacker)
{
    int critical_factor;

    // Possible critical hit for ninja
    if (wielded_by && wielded_by -> query_guild()== 8)
    {
	critical_factor = 100 / (wielded_by -> query_dex()
				 + wielded_by -> query_wis()
				 - attacker -> query_dex());
	if (critical_factor < 1)
	    critical_factor = 150;
	
	if (!random(critical_factor))
	{
	    // This is a critical hit: do additional damage
	    // and stick up a critical hit message
	    tell_object(wielded_by, "CRITICAL HIT on " +
			attacker -> query_name(1) + ".\n");
	    tell_object(attacker, wielded_by -> query_name(1) +
			" scores a CRITICAL hit on you.\n");
	    return ((20 * (wielded_by -> query_level()) +
		     10 * (wielded_by -> query_legend_level()) +
		     20 * (wielded_by -> query_str()))
		    * class_of_weapon / 50);
	}
    }
    // No special effect for non ninja or if random call failed
    return 0;
    
}



