inherit "room/room";

#define PPATH  "/players/tatsuo/ezo/"

reset( arg )
{
   ::reset( arg );

   if ( !present( "barracuda", this_object() ) )
      move_object( clone_object( "/players/tatsuo/seaMonst/barracuda" ),
                   this_object() );

   if ( arg )
      return;

   short_desc = "Diving in the sea";
   long_desc = 
        "You are diving in the Nihonese sea. Looking up, you can see the\n"+
        "sunlight and looking down the sea gets colder and darker.\n";

   dest_dir = ({ PPATH + "coast/waterLink", "up",
                 PPATH + "ryuworld/wo2", "down"
              });
}

init()
{
   object *diver;

   ::init();

   if ( this_player()->query_npc() )
      return;

   diver = present( "diver", this_player() );

   if ( !diver ) {
      diver = clone_object( PPATH + "ryuworld/diver" );
      move_object( diver, this_player() );
      diver->start_dive(this_player());
   }
   else
      diver->start_dive(this_player());
}

query_water()
{
   return( 1 );
}
