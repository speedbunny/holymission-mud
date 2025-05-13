inherit "/players/patience/GenObj/storeroom";

reset( arg )
{
   ::reset( arg );
   
   if ( !arg ) {
      set_trader( "Franz" );
      set_info( "Item" );
   }
}

check_allow( ob )
{
   if ( ob )
      return( !(ob->query_weapon() || ob->query_armour()) );
      
   return( 0 );
}
