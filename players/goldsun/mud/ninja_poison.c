int    poison;
object who;

reset( arg )
{
   if ( arg )
      return;
   
   poison = 0;
}

id( str )
{
   return( str == "_ninja_poison_" );
}

query_weight()
{
   return( 0 );
}

start_poisoning( w, v )
{
   poison = v;
   who = w;
   poison_hit();
}

poison_hit( )
{
   if ( poison > 0 ) {
      if ( poison > 20 ) {
         who->reduce_hit_point( 20 );
         tell_room( environment( this_player() ),
               who->query_name() + " screams in agony of being poisoned !!!\n" );
         poison -= 20;
         call_out( "poison_hit", 3 );
      }
      else {
         who->reduce_hit_point( 20 );
         tell_room( environment( this_player() ),
               who->query_name() + " screams in agony of being poisoned !!!\n" );
         destruct( this_object() );
      }
   }
   else
      destruct( this_object() );
}
