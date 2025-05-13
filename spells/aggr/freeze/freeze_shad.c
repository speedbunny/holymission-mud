// freeze shadow
// shadows the attack makes input impossible
// id: freeze
// attr-msg: none
// shadows the attack
// non-multipe

inherit "/obj/std_shadow";

int old_wimpy;

start_shadow( who, time )
{
   who->lock_input(-1,"You are a statue of ice, unable to do anything !!!\n");
   old_wimpy = who->query_wimpy();
   who->set_wimpy( -1 );
   return( ::start_shadow( who, 0, "freeze", 0 ) );
}

end_shadow( o )
{
   tell_object( me, "You break out of the ice !\n" );
   say( apply(call,me,"query_name")+" BREAKS OUT of the ice !\n" );
   me->unlock_input( );
   me->set_wimpy( old_wimpy );
   ::end_shadow( o );
}

void chk_all_shadows()
{
   if ( random(75) < me->query_str() ) {
      me->chk_all_shadows();
      end_shadow();
   }
   else {
      ::chk_all_shadows();
      tell_object( me, "You try to break out of the ice, but fail !!!\n" );
      say( me->query_name()+" tries to break out of the ice, but fails !\n",me);
      if ( me != this_player() )
       write(me->query_name()+" tries to break out of the ice, but fails !\n" );
   }
}

varargs int attack( object ob, int hand  )
{
   tell_object( me, "You are frozen and cannot move !\n" );
   say( me->query_name() + " is frozen and cannot move !\n", me );
   if ( me != this_player() )
      write( me->query_name()+" is frozen and cannot move !\n" );

   return( 1 );
}
