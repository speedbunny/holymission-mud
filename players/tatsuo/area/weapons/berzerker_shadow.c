// paralyze shadow
// shadows the attack makes input impossible
// id: paralyze
// attr-msg: none
// shadows the attack
// non-multipe

// Completely stolen by Blade
// from the spells system that
// never was.
//  I coded nothing of this 

inherit "/obj/std_shadow";

object bsword, current_victim;
int    old_wimpy;

start_shadow( who, time ){
  who->lock_input(time,"You are caught in a snare!  You struggle to get "+
                  "out, but you can do nothing.\n" );
  old_wimpy = who->query_wimpy();
  who->set_wimpy( -1 );
  return( ::start_shadow( who, time, "paralyze", 0 ) );
}

end_shadow( o ){
   tell_object( me, "You break out of the snare!\n" );
   say( apply(call,me,"query_name")+" breaks out of the snare!\n" );
   me->unlock_input( );
   me->set_wimpy( old_wimpy );
   //   if ( !apply(call,me,"query_player") )
     //      me->attacked_by( paralyzer );
   ::end_shadow( o );
}

void set_bsword( object p ){  bsword = p;  }
// void set_cur_victim( object v ){  current_victim = v;  }

/*
stop_fight(){
  tell_object(environment(bsword),"test\n");
  //  me->stop_fight();
  bsword->berzerk();
  return;
}
*/

/* void recognize_fight(){
  if(current_victim) 
    return me->recognize_fight();
  else
    bsword->berzerk();
  return;
} */


// varargs int attack( object theWeapon, int nrOfHand )

/*
varargs int attack( object ob, int hand  )
{
   say( apply(call,me,"query_name")+" is caught in a snare!\n" );
   write( "You are trapped in a snare!\n" );
   return( 1 );
}
*/

/*
void set_paralyzer( object p )
{
   paralyzer = p;
}
*/



