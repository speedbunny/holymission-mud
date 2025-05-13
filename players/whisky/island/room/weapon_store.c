inherit "/players/patience/GenObj/storeroom";

reset( arg )
{
   ::reset( arg );
   
   if ( !arg ) {
      set_trader( "Hilde" );
      set_info( "Weapon" );
   }
}

check_allow( ob )
{
   if ( ob )
      return( ob->query_weapon() );
      
   return( 0 );
}
