
/* rose_shad.c */

inherit "/obj/std_shadow";

int rose_shad()
{
    return 1;
}

object rose_object()
{
     return this_object();
}

int query_chr()
{
    if(environment(me)->stat_room()) return me->query_chr();
    return me->query_chr()+2;
}

int query_stats(int x)
{
   if(environment(me)->stat_room()) return me->query_stats(x);
   switch(x)
   {
     case 5:
       return me->query_stats(x)+2;
     default:
       return me->query_stats(x);
    }
}


