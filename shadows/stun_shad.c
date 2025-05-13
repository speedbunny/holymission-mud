// stun shadow
// shadows the attack makes input impossible
// id: stun
// attr-msg: none
// non-multipe
// somebody, who is stunned, is unable to input something, unable to fight
// and unable to wimp

inherit "/obj/std_shadow";

object stunner;
int    old_wimpy;

start_shadow( who, time )
{
   who->lock_input( time, "You are stunned, you cannot do anything !" );
   old_wimpy = who->query_wimpy();
   who->set_wimpy( -1 );
   return( ::start_shadow( who, time, "stun", 0 ) );
}

end_shadow( o )
{
   tell_object( me, "You recover of the stun !\n" );
   say( apply(call,me,"query_name")+" recovers of the stun !\n" );
   me->unlock_input( );
   me->set_wimpy( old_wimpy );
   if ( !apply(call,me,"query_player") )
      me->attacked_by( stunner );
   ::end_shadow( o );
}

void set_stunner( object p )
{
   stunner = p;
}

varargs int attack( object ob, int hand  )
{
   tell_object( me, "You are stunned, unable to move !\n" );
   say( me->query_name() + " is stunned, unable to move !\n", me );
   if ( me != this_player() )
      write( me->query_name()+" is stunned, unable to move !\n" );

   return( 1 );
}
