inherit "/obj/std_shadow";
int query_stats(int x)
{
   if(environment(me)->stat_room()) return me->query_stats(x);
      return me->query_stats(x);
}

int query_wis()
{ if(environment(me)->stat_room()) return me->query_wis();
    return me->query_wis()+5;
}

int wis_shad()
{ return 1;
}
