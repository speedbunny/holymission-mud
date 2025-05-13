inherit "/obj/monster";
#include "walker.h"

object chest;
int gas_form;

void reset(int flag) {
    object money;

    ::reset(flag);
    if(!flag) {
	gas_form = 0;
	set_name("chaosdemon");
	set_alt_name("demon");
	set_race("demon");
	set_level(30);
	set_gender(0);
	set_al(-3000);
	set_short("An invulnerable chaosdemon");
	set_no_steal();
	set_long(
	  "This is a demon of chaos. It is not evil, not good, not neutral.\n" +
	  "It is -- chaotic. It shimmers and wavers like a cloud of poison\n" +
	  "gas, but you can still make out some features, like the gleaming\n" +
	  "teeth, the dangerously glowing eyes, and the industrial-strength\n" +
	  "muscles in what should probably be called arms.\n" +
	  "This creature looks invulnerable, and clearly a very special weapon\n"+
	  "is needed if you want to hurt it.\n");
	set_aggressive(1);
	/* when the player is invis */
	load_chat(60,({
	    "Now, the Chaosdemon look demonic.\n",
	    "Now, the Chaosdemon look evil.\n",
	    "Now, the Chaosdemon look neutral.\n",
	    "Now, the Chaosdemon looks nice.\n",
	  }));
	set_spell_mess1(
	  "The Chaosdemon casts a SEVERE INTERNAL DAMAGE AND PAIN spell.");
	set_spell_mess2(
	  "The Chaosdemon casts a SEVERE INTERNAL DAMAGE AND PAIN spell at you.");
	set_chance(50);
	set_spell_dam(random(120));
    }
} 

/* poison */
int attack()
{
    int i, sz;
    object *inv;

    if (::attack() && !gas_form &&  !random(4) && 
      query_hp() < (query_max_hp()-200) && objectp(attacker_ob)
      && !present("lawbringer",attacker_ob))
    {
	tell_room(environment(),
	  "The Chaosdemon shimmers and wavers like a poisonous cloud.\n");
	gas_form = 1;
	call_out("normal_form",20);
	this_object()->heal_self(2000);
	inv = all_inventory(environment());

	for (sz = sizeof(inv), i = 0; i < sz; i++)
	{
	    if (living(inv[i]) && inv[i]!=this_object())
	    {
		command("puke",inv[i]);
		inv[i]->add_poison(20+random(20));
	    }
	}
	return 1;
    }
    return 0;
}

mixed hit_player(int dam,int kind,mixed elem)
{
    if (gas_form && !present("lawbringer",previous_object()))
    {
	tell_object(this_player(),"You are trying to hit the poisonous gas.\n");
	this_player()->add_poison(random(20));
	return 0;
    }
    return ::hit_player(dam,kind,elem);
}        

void normal_form()
{
    tell_room(environment(),
      "The Chaosdemon transforms to it's former shape.\n");
    gas_form = 0;
}

mixed add_poison(int p)
{   
    if (this_player()!=this_object())
    {
	tell_room(environment(),"The Chaosdemon laughs horrible !\n");
	this_object()->heal_self(p);
	return 0;
    }
    return ::add_poison(p);
}

int query_no_summon()
{
    return 1;
}
