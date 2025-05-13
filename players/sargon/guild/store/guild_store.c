#include "/players/sargon/define.h"
#define GOBJ "/players/sargon/guild/store/"
inherit "/players/sargon/guild/rooms/storeroom";

reset(arg) {
   int i;
   ::reset( arg );
   
   if ( !present("black scroll",TO) )
      for( i = 0; i < 2; i++ )
       TR(CO("/players/whisky/obj/pois_scroll"), (TO));

   if (!present("bag of holding",TO) )
      for(i = 0; i < 1; i++)
       TR(CO(PG+"guild/obj/bag"), (TO));


   if ( !arg ) {
      set_trader( "Xena" );
      set_info( "Item" );
   }
}

check_allow( ob ) {
   if ( ob )
      return( !(ob->query_weapon() || ob->query_armour()) );
      
   return( 0 );
}
