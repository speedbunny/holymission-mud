
/* dex shad */

inherit "/players/whisky/obj/std_shadow";

int ring_shad()
{
    return 1;
}

object ring_object()
{
     return this_object();
}

/*
int query_dex()
{
    if(environment(me)->stat_room()) return me->query_dex();
    return me->query_dex()+10;
}

int query_stats(int x)
{
   if(environment(me)->stat_room()) return me->query_stats(x);
   switch(x)
   {
     case 4:
       return me->query_stats(x)+10;
     default:
       return me->query_stats(x);
    }
}
*/

attack()
{
  if (!me->haste_shad())
  {
    me->attack();
  }
    me->attack();
    return me->attack();
}

int haste_shad()
{
	return 1;
}

