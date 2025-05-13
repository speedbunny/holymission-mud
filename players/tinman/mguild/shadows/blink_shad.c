
/* blink_shad */

#define DIRS ({"east","west","north","south"})

inherit "/obj/std_shadow";

int rounds;

varargs mixed hit_player(int dam,int kind,mixed ele)
{
   string where;

// blink makes it possible to dodge normal hits, special hits and 
// magic hits. Area spells shouldnt be dodgable, but since there
// is no general function, I have no better choice. 

   if (me==this_player() || (kind!=0 && kind!=7 && kind!=5) )
       return funcall(call,me,"hit_player",dam,kind,ele);

   if (!rounds)
      rounds = 1;
   else if (rounds == 1)
      rounds = 2;
   else 
      rounds = 0;

// dexroll and random roll
// dexroll and random roll : first hit ever success :*)

    if (rounds==2 && environment(me)==environment(this_player()))
    {
        where = DIRS[random(4)];
        tell_object(me,"You do a quick, high jump, and a salto to the "+
                    where+".\n");
        say(apply(call,me,"query_name")+" does a quick, high jump, and"+
            " a salto to the "+where+".\n",me);
        say(apply(call,this_player(),"query_name")+" does a wild attack.\n",
            this_player());

// dexcheck and skillcheck
        if (random(4 + apply(call,me,"query_dex")/8) && random(4))
        {
            tell_object(this_player(),"You are confused.\n");
            return funcall(call,me,"hit_player",0,kind,ele);
        }
   }
   return funcall(call,me,"hit_player",dam,kind,ele);
} 
       
void end_shadow(object ob)
{
    tell_object(me,"You stop vibrating !\n");
    say(apply(call,me,"query_name")+" stops vibrating.\n");
    ::end_shadow(ob);
}      

string look_info(int flag)
{
   if (apply(call,me,"query_attack"))
       return (" (blinking)");
   return apply(call,me,"look_info",flag);
}
    
// simple a blinking person cant be held guess how ??
varargs mixed hold(mixed whom,mixed time)
{
     return funcall(call,me,"hold",whom,0);
}
