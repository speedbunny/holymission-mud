
/* protection from evil 

   Effect: reduces the hit and raises the ac by fights against badies 
   Attr-msg: protection from evil 
   Special: only one shadow in time 
                                                      */

inherit "/obj/std_shadow";

int chk_al;


varargs int start_shadow(object who,int time)
{
    set_effect_msg("protection from evil");
    return ::start_shadow(who,time,"protection_from_evil",0);
}

varargs int hit_player(int dam,int kind,mixed ele) 
{
   if (dam > 0)
   {
      if ( chk_al = (apply(call,this_player(),"query_alignment") < 0) )
	 return apply(call,me,"hit_player",0,kind,ele);
   }
   return apply(call,me,"hit_player",dam,kind,ele);
}

int query_ac()
{
    int ac;
    
    ac = apply(call,me,"query_ac");
    return(chk_al ? (ac + 3) : ac); 
}

      
void end_shadow(object ob)
{
     tell_object(me,"Your protection against evil wears off !\n");
     ::end_shadow(ob);
}

