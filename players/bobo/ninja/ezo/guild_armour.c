#define TO (this_object())

inherit "/players/tatsuo/GenObj/storeroom";

reset( arg )
{
   ::reset( arg );
   
   if ( !arg ) {
      set_trader( "Gidayu Nitta" );
      set_info( "Armour" );
   }
}

check_allow( ob )
{
   if ( ob )
      return( ob->query_armour() );
      
   return( 0 );
}
