inherit "/obj/std_shadow";
int query_stats(int x)
{
   if(environment(me)->stat_room()) return me->query_stats(x);
   switch(x)
   {
     case 3 : return me->query_stats(x)+5; break;
     default : return me->query_stats(x);
   }
}

int query_int()
{ if(environment(me)->stat_room()) return me->query_int();
    return me->query_int()+5;
}

int int_shad()
{ return 1;
}
