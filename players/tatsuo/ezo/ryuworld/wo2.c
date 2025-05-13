inherit "room/room";

#define PPATH "/players/tatsuo/ezo/ryuworld/"

reset( arg )
{
   ::reset( arg );

   if ( !present( "shark", this_object() ) )
      move_object( clone_object( "/players/tatsuo/seaMonst/kshark" ),
                   this_object() );

   if ( arg )
      return;

   short_desc = "Diving in the sea";
   long_desc = 
        "You are diving in the Nihonese sea. Looking up, you can see the\n"+
        "sunlight and looking down the sea gets colder and darker.\n" +
        "Some weeds are growing at the side of the vulcano.\n";

   items = ({ "volcano", "Some weeds grow at its side",
              "weeds", "Could this be a cave hidden behind them ?",
              "weed", "Could this be a cave hidden behind the weeds ?"
           });

   dest_dir = ({ PPATH + "wo1", "up" });
}

init()
{
   ::init();

   add_action( "enter_cave", "enter" );
}

do_ser( arg )
{
   if ( arg == "weeds" || arg == "weed" )
      long(arg);
}

enter_cave( arg )
{
   if ( arg == "cave" ) {
      this_player()->move_player( 
                    "into the weeds#/players/tatsuo/ezo/ryuworld/w1" );
      return( 1 );
   }
}

query_water()
{
   return( 1 );
}
