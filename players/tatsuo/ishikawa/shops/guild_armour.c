#define TO (this_object())

inherit "/players/patience/GenObj/storeroom";

reset( arg )
{
   ::reset( arg );
   
   if ( !arg ) {
      set_trader("Kiko Sunami");
      set_info( "Armour" );
   }
}

check_allow( ob )
{
   if ( ob )
      return( ob->query_armour() );
      
   return( 0 );
}
