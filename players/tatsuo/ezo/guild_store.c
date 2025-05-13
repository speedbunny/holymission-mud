#define TO (this_object())
inherit "/players/tatsuo/GenObj/storeroom";
reset(arg) {
   int i;
   ::reset( arg );
   if ( !present("'egg'", this_object() ) )
     for( i = 0; i < 12; i++)
         transfer( clone_object( "/players/tatsuo/guild/nweap/egg"), TO );
   if ( !present("white pepper", this_object() ) )
     for( i = 0; i < 12; i++)
       transfer(clone_object("/players/tatsuo/guild/nother/white_pepper"),TO);
  if( !present("smoke bomb"), this_object() ) 
     for( i = 0; i < 25; i++)
     transfer(clone_object("/players/tatsuo/guild/nother/smoke_bomb"),TO);
   if ( !arg ) {
      set_trader( "Miyamoto Makimura" );
      set_info( "Item" );
   }
}

check_allow(ob) {
   if ( ob )
      return( !(ob->query_weapon() || ob->query_armour()) );
      
   return( 0 );
}
