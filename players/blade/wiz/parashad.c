// paralyze shadow
// shadows the attack makes input impossible
// id: paralyze
// attr-msg: none
// shadows the attack
// non-multipe

inherit "/obj/std_shadow";

object paralyzer;
int    old_wimpy;

start_shadow( who, time )
{
   who->lock_input( time, "You are paralyzed !!!  Do not even think you "+
                       "can do something !" );
   old_wimpy = who->query_wimpy();
   who->set_wimpy( -1 );
   return( ::start_shadow( who, time, "paralyze", 0 ) );
}

end_shadow( o )
{
   tell_object( me, "You are able to move again !\n" );
   say( apply(call,me,"query_name")+" is able to move again !\n" );
   me->unlock_input( );
   me->set_wimpy( old_wimpy );
   if ( !apply(call,me,"query_player") )
      me->attacked_by( paralyzer );
   ::end_shadow( o );
}

varargs int attack( object ob, int hand  )
{
   say( apply(call,me,"query_name")+" is unable to move !\n" );
   write( "You are unable to move !!!\n" );
   return( 1 );
}

void set_paralyzer( object p )
{
   paralyzer = p;
}
