#define RM "race/master"
#define MAX_ST 30
#define W_DODGE 100     /* weight * 100/strength max for dodge */

inherit "/obj/std_shadow";
int count;

int stat_dam(object weap) {
    object vic;

    if (!count)
	count = 1;
    else if (count < 5)
	count ++;
    else
	count = 0;

    if (!count && (vic = me->query_attack()) && 
      random(50) < (5+me->query_dex()/2))
    {
	tell_object(me,"You slip between "+vic->query_name()+"'s defenses.\n");
	say(me->query_name()+" slips between his opponent's defenses.\n",me);
	return (5 * me->stat_dam(weap));
    }
    return me->stat_dam(weap);
}

varargs mixed hit_player(int dam,int kind,mixed elem) {
  string          name, pname;
  int             dex, dk, enc, i, max, wt;

  dex = me->query_dex() - this_player()->query_dex();/* delta dexterity */
  wt = me->query_weight();	    /* what we are carrying */
  enc = wt * 100 / me->query_str();
  name = me->query_name();
  pname = this_player()->query_name();

  if (!kind || kind == 0 || kind==1 || kind == 2 || kind == 6 || kind == 7)
    dk = 0;
  if (dk || dex < 1 || enc > W_DODGE) {
    return me->hit_player(dam, kind);	       /* original route */
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
  i = me->hit_player(dam, kind, elem);
  write(me->query_name() +" tried to dodge your attack.\n");
  if (i)
    say(me->query_name() +" tried to dodge the attack of "+ pname +".\n");
  tell_object(me, "You tried to dodge the attack of "+ pname +".\n");
  return i;
}

look(str) {

/*    if (this_player()->test_dark())
	return notify_fail("It is too dark.\n"); */ /*thieves can see in dark*/
    if (!str) 
	return this_player()->mylook(0);
    else
	return this_player()->look(str);
}

int thief_shadow() {
    return 1;
}

object thief_object() {
    return this_object();
}        

