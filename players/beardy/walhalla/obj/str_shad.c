inherit "/obj/std_shadow";
int query_stats(int x)
{
   if(environment(me)->stat_room()) return me->query_stats(x);
   switch(x)
   {
     case 0 : return me->query_stats(x)+5; break;
     default : return me->query_stats(x);
   }
}

int query_str()
{ if(environment(me)->stat_room()) return me->query_str();
    return me->query_str()+5;
}

int str_shad()
{ return 1;
}
