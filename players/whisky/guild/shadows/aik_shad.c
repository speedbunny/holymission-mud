
inherit "/obj/std_shadow";

mixed hit_player(int dam,int kind,mixed elem)
{
   int res;

// what means aikido works only on normal against choke 

   if (kind <= 4 && dam > 1)
       res = dam / 3 * 2; 
   else
       res = dam;

   return funcall(call,me,"hit_player", res, kind, elem);
}

mixed end_shadow(object ob)
{
    tell_object(me,"You turn back to your normal state !\n");
    return ::end_shadow(ob);
}
