
/* thor shad */

inherit "/players/whisky/obj/std_shadow";

int thor_shad()
{
    return 1;
}

object thor_object()
{
     return this_object();
}

int query_ac()
{
    return me->query_ac()+2;
}

int query_str()
{
    if(environment(me)->stat_room()) return me->query_str();
    return me->query_str()+3;
}

int query_stats(int x)
{
   if(environment(me)->stat_room()) return me->query_stats(x);
   switch(x)
   {
     case 0:
       return me->query_stats(x)+3;
     default:
       return me->query_stats(x);
    }
}

mixed restore_spell_points(int sp)
{
  int f;    

   f = sp * 2 / 3;

   if (f < 0)
       return me->restore_spell_points(f);
   return me->restore_spell_points(sp);
}

