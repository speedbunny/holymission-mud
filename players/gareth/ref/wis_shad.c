
/* wis shad */

inherit "/players/whisky/obj/std_shadow";

int wis_shad()
{
    return 1;
}

object wis_object()
{
     return this_object();
}

int query_wis()
{
    if(environment(me)->stat_room()) return me->query_wis();
    return me->query_wis()+3;
}

int query_stats(int x)
{
   if(environment(me)->stat_room()) return me->query_stats(x);
   switch(x)
   {
     case 4:
       return me->query_stats(x)+3;
     default:
       return me->query_stats(x);
    }
}


