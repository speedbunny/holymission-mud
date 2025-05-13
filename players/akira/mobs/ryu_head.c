object *owner;

id( str )
{
   return( str == "head" || str == "head of ryu" || str == "_ryu_head_" );
}

init( )
{
   add_action( "dd", "head_dump" );
}
head_dump()
{
if ( !owner )
   write ( "no owner" );
else
   write( owner->query_name() );
}

query_name( )
{
   return( "head of ryu" );
}

short()
{
   return( "The head of the ryu" );
}

long()
{
   write( "This is the head of the ryu. It is drained with blood.\n" );
}

get( )
{
   return( 1 );
}

query_owner()
{
   return( owner );
}

set_owner( o )
{
   if ( !owner && !(this_player()->query_npc()) && interactive(this_player()) )
      owner = o;
}
