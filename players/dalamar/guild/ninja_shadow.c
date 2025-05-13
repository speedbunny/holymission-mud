// Ninja shadow: to allow ninja to parry attacks, as they used to
// Begun Darastor 250198

// Before we start, some notes on how I want it to work, for
// future reference.
// The chance of a successful parry (i.e. making contact with the incoming
// blow) should depend on ninja dex, attacker dex and ninja level (to reflect
// expertise)
// Minimum chance: ninja level / 5 (minimum 2%)
// I think there should be a chance of an outright parry which is successful
// otherwise damage should be reduced by a random percentage
// If < ninja level /10 (minimum 1%) then outright parry - complete success
// the max value of this percentage should be based on ninja str,
// and parry class of weapon (attacker str and weapon class have already
// been taken into account in determining this damage, so should not be
// factored in again)
// The overall parry factor for the player should be the highest parry factor
// of any weapons/armour they are carrying
// Parrying should be prevented if a player is too encumbered.

#define TP  this_player()
#define RM "race/master"
#define MAX_ST 30
#define MAX_PARRY_WEIGHT 100     /* weight * 100/strength max for dodge */

inherit "/obj/std_shadow";

status is_parry_item(object ob)
{
    return (ob -> query_parry_class() > 0);
}

varargs mixed hit_player(int dam,int kind,mixed elem)
{
    int parry_chance, enc, die_roll, invSize, maxParryClass, thisParryClass;
    int maxRednPC, wt, thisItem;
    object *parry_items, *inv;
    status may_parry;

    parry_chance = me-> query_dex() + ((me -> query_level())/4) -
	this_player() -> query_dex();
    if (parry_chance < (me -> query_level())/5)
	parry_chance = (me -> query_level())/5;
    if (parry_chance < 2)
	parry_chance = 2;

    wt = me -> query_weight();
    enc = wt * 100 / (me -> query_str());
        
    if (!kind || kind == 0)
	may_parry = 1;
    else
	may_parry = 0;

    if ((!may_parry) || (enc > MAX_PARRY_WEIGHT))
    {
	return me -> hit_player(dam, kind);
    }

    die_roll = random(100);
    if ((die_roll < (me -> query_level())/10) || (die_roll == 0))
    {
	// Check to see if any items worn/wielded which can be used
	// for parrying
	parry_items = filter_array(all_inventory(me),"is_parry_item",
				   this_object());
	if (sizeof(parry_items))
	{
	    // Outright parry
	    tell_object(TP,me -> query_name(1) +
			" neatly parries your attack.\n");
	    say(me -> query_name(1) +
		" deftly parries the attack of " +
		TP -> query_name(1) + ".\n",me);
	    tell_object(me, "You neatly parry the attack of " +
			TP -> query_name(1) + ".\n");
	    return 0;
	}
    }
    else if (die_roll < parry_chance)
    {
	// Partial parry - reduce damage accordingly
	inv = all_inventory(me);
	invSize = sizeof(inv);
	maxParryClass = 0;
	for (thisItem = 0; thisItem < invSize; thisItem ++ )
	{
	    if ((thisParryClass = inv[thisItem] -> query_parry_class())
		> maxParryClass)
		maxParryClass = thisParryClass;
	}
	if (maxParryClass)
	{
	    maxRednPC = me -> query_str() + maxParryClass;
	    dam = (100 - random(maxRednPC))/100;

	    tell_object(TP, me -> query_name(1) +
			" manages to partially block your attack.\n");
	    say(me -> query_name(1) + "partly blocks the attack of " +
		TP -> query_name(1) + ".\n", me);
	    tell_object(me, "You partially block the attack of " +
			TP -> query_name(1) + ".\n");
	}
	return me -> hit_player(dam, kind);
    }
    else
    {
	// Parry failed
	return me -> hit_player(dam, kind);
    }
}

int ninja_shadow()
{ 
  return 1; 
}

object ninja_object()
{
  return this_object();
}        

