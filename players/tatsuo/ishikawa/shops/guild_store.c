#define TO (this_object())

inherit "/players/patience/GenObj/storeroom";

reset( arg )
{
   ::reset( arg );
   
   if (!sizeof(all_inventory(TO)) )
   {
      transfer( clone_object( "/players/tatsuo/ishikawa/obj/pouch"), TO );
      transfer( clone_object( "/players/tatsuo/ishikawa/obj/pouch"), TO );
      transfer( clone_object( "/players/tatsuo/ishikawa/obj/rope"), TO );
      transfer( clone_object( "/players/tatsuo/ishikawa/obj/rope"), TO );
      transfer( clone_object( "/players/tatsuo/ishikawa/obj/rope"), TO );
      transfer( clone_object( "/players/tatsuo/ishikawa/obj/lantern"), TO );
      transfer( clone_object( "/players/tatsuo/ishikawa/obj/lantern"), TO );
      transfer( clone_object( "/players/tatsuo/ishikawa/obj/lantern"), TO );
      transfer( clone_object( "/players/tatsuo/ishikawa/obj/lantern"), TO );
      transfer( clone_object( "/players/tatsuo/ishikawa/obj/pouch"), TO );
   }
   if ( !arg ) {
      set_trader("Shingo Tanaka");
      set_info( "Item" );
   }
}

check_allow( ob )
{
   if ( ob )
      return( !(ob->query_weapon() || ob->query_armour()) );
      
   return( 0 );
}
