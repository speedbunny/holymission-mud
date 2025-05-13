inherit "/obj/weapon";

#include <properties.h>

int critical_hit_factor;
int parry_class;
int can_throw;
string owner;

void set_parry_class(int arg)
{
    parry_class = arg;
}

nomask void set_owner(string str)
{
    owner = str;
}

nomask string query_owner()
{
    return owner;
}

void long()
{
    ::long();
    if(owner)
	tell_object(this_player(),
		    "This " + query_name(1) + "belongs to " +
		    capitalize(owner) + ".\n");
}

int query_can_throw()
{
    return can_throw;
}

void set_can_throw()
{
    can_throw = 1;
}

void reset(int arg)
{
    ::reset(arg);
    can_throw = 0;

    if(!arg)
    {
	set_parry_class(0);
	add_property("ninja_weapon",1);
	set_hit_func(this_object());
    }
}

nomask int query_parry_class()
{
    if (query_wielded())
    {
	return parry_class;
    }
    else
    {
	return 0;
    }
}

void set_critical_hit_factor(int arg)
{
    critical_hit_factor = arg;
}

int query_critical_hit_factor()
{
    return critical_hit_factor;
}

int wield(string arg)
{
    if ((!arg) || (!present(arg, this_player())))
	return 0;

    if (owner && (owner != "") &&
	(owner != this_player() -> query_real_name()))
    {
	tell_object(this_player(),
		    "The "+ query_name() + " refuses to be wielded by you!\n");
	return 1;
    }
    
    return ::wield(arg);
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
		    * critical_hit_factor * class_of_weapon / 250);
	}
    }
    // No special effect for non ninja or if random call failed
    return 0;
    
}



