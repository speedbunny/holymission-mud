
/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Crit_shadow =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

inherit "/obj/std_shadow";
int count;

int stat_dam(object weap)
{
    object vic;

    if (!count)
	count = 1;
    else if (count < 3)
	count ++;
    else
	count = 0;

    if (!count && (vic = me->query_attack()) && 
      random(50) < (5+me->query_dex()/2))
    {
	tell_object(me,"You slip between "+vic->query_name()+"'s defenses.\n");
	say(me->query_name()+" slips between his opponent's defenses.\n",me);
	return (9 * me->stat_dam(weap));
    }
    return me->stat_dam(weap);
}

int crit_shadow()
{
    return 1;
}

object crit_object()
{
    return this_object();
}        

