
/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Dodge Shadow =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

#define RM      "race/master"
#define MAX_ST  30
#define W_DODGE 100		      /* weight * 100/strength max for dodge */

inherit "/obj/std_shadow";

/* USERDOC:
This shadows the living function, hit_player().
It allows full and partial 'dodging' of certain types of attacks: dexterity and
charisma based (0,2,6,7), and normal.
*/

hit_player(dam, kind)
{
    string          name, pname;
    int             dex, dk, enc, i, max, wt;

    dex = me->query_dex() - this_player()->query_dex();/* delta dexterity */
    wt = me->query_weight();	                     /* what we are carrying */
    enc = wt * 100 / me->query_str();
    name = me->query_name();
    pname = this_player()->query_name();

    if (!kind || kind == 0 || kind == 2 || kind == 5 || kind == 7)
	dk = 0;
    if (dk || dex < 1 || enc > W_DODGE) {
	return me->hit_player(dam, kind);	          /* original route */
    }

    if (! (max = RM->query_max_stat(me->query_race(), 1)) )
	max = MAX_ST;

    /* First we check if a complete dodge of the attack is possible */

    i = dex * (W_DODGE - enc) / max;      /* % possibility reduced by weight */
    if (random(100) < i) {	                      /* We dodge completely */
	write(name + " dodges your attack.\n");
	say(name + " swiftly dodges the attack of " + pname + ".\n", me);
	tell_object(me, "You swiftly dodge the attack of " + pname + ".\n");
	return 0;
    }

    /* It isn't possible to dodge. But maybe we can reduce the damage ? */

    i = random(100 - i) / 2 + 50;	            /* Minimum: 50 % damage */
    dam = dam * i / 100;
    i = me->hit_player(dam, kind);
    write(me->query_name() +" tried to dodge your attack.\n");
    if (i)
	say(me->query_name() +" tried to dodge the attack of "+ pname +".\n");
    tell_object(me, "You tried to dodge the attack of "+ pname +".\n");
    return i;

}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Look Shadow =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

static string it;

// Kasgaroth 2-29-95 Full shadow of look so thieves can examine their marks unobserved

#include <levels.h>
#define MAX_LIST 20
#define CName    (this_player()->query_name())
#define TName    (this_player()->query_name_true())
#define TP       this_player()

look(str) 
{
    object ob, ob_tmp, *all, *inv;
    string item,short_str,msg,position;
    int max,i,sz;

/*    if (this_player()->test_dark())
    {
	write("It's too dark.\n");
	return 1;
    }
*/   /* Thieves can see in darkness. */
    if (!str) 
	return this_player()->mylook(0);
    if (sscanf(str, "at %s", item) == 1 || sscanf(str, "in %s", item) == 1) 
    {
	int weight;
	item = lower_case(item);
	ob = present(item, this_player());
	if (!ob && call_other(environment(this_player()), "id", item))
	    ob = environment(this_player());
	if (!ob)
	    ob = present(item, environment(this_player()));
	if (!ob) 
	{
	    notify_fail("You see nothing of interest.\n");
	    return 0;
	}
	it = item;
	call_other(ob, "long", item);
	weight = ob->query_weight();
	if (ob->can_put_and_get(item)<1)   /* <1 for container */
	    return 1;
	if (living(ob)) {
	    object special;
	    special = first_inventory(ob);
	    while(special) {
		string extra_str;
		extra_str = call_other(special, "extra_look");
		if (extra_str)
		    write(extra_str + ".\n");
		special = next_inventory(special);
	    }
	}
	ob_tmp = first_inventory(ob);
	while(ob_tmp && call_other(ob_tmp, "short") == 0)
	    ob_tmp = next_inventory(ob_tmp);
	if (ob_tmp) {
	    if (living(ob)) {
		write("\t" + capitalize(item) + " is carrying:\n");
	    } else
		write("\t" + capitalize(item) + " contains:\n");
	}

	// only thiefes and wizards see the full inventory of a player

	max = MAX_LIST;
	msg = "";
	ob = first_inventory(ob);

	while(ob && max > 0) 
	{
	    if (short_str=ob->short())
		msg += capitalize(short_str) + ".\n";
	    ob = next_inventory(ob);
	    max -= 1;
	}
	if (ob && !max) msg+="\n";
	write(msg);
    return 1;
}
write("Look AT something, or what ?\n");
return 1;
}

#if 0
look(str)
{

  /*    if (this_player()->test_dark())           Thieves can see in darkness.
	return notify_fail("It is too dark.\n"); */
    if (!str) 
	return this_player()->mylook(0);
    else
	return this_player()->look(str);
}
#endif

int dodge_shadow()
{
    return 1;
}

object dodge_object()
{
    return this_object();
}

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/




