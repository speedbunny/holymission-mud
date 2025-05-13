#define ETO     environment(this_object())
#define ROOM    environment(ETO)

int base;

reset( arg )
{
   if ( arg )
      return;

   base = 0;
}

id( str )
{
   return( str == "wkn" || str == "waskannom" );
}

drop()
{
   destruct( this_object() );
   return( 1 );
}

query_name()
{
   return( "waskannom" );
}

free_chance( b )
{
   base = b;

   remove_call_out( "free_myself" );
   if ( clonep( this_object() ) )
      call_out( "free_myself", 2 );
}

free_myself()
{
   if ( !(this_object() && ETO && living(ETO) ) ) {
      destruct( this_object() );
      return;
   }

   tell_room( ROOM,
              ETO->query_name() + " tries to get out of the ground,\n" ); 
   if ( ETO->query_str() > random( base ) ) {
      tell_room( ROOM, "...and succeeds !!!\n" );
      ETO->set_dex( ETO->query_dex()*2 );
      ETO->set_trapped(0); 
      destruct( this_object() );
   }
   else {
      tell_room( ROOM, "...but fails.\n" );
      call_out( "free_myself", 5 );
   }
}
