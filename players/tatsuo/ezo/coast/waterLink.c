#define PPATH  "/players/tatsuo/ezo/coast/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define TO     (this_object())

inherit "room/room";

reset( arg )
{
   if ( arg )
      return;
      
   set_light(1);
   short_desc = "In the nihonese see";
   long_desc = "You are swimming in the nihonese sea. To your north can you see a\n" +
               "slope of the northern part of Ezo and to your south is the shore\n" +
               "of the southern part of Ezo and to your west is the volcano.\n"+
               "Looking down, you can see a huge, moving shadow !!!\n";
 
   items = ({ "sea", "Water, as far as your eye can see",
              "nihonese sea", "Water, as far as your eye can see",
              "water", "It is salt-water. The waves are rolling onto the island",
              "wave", "This wave is a very big one",
              "waves", "The waves are rolling onto the island",
              "horizon", "It is really far away",
              "vulcano", "The vulcano looks very steep",
              "shadow", "The shadow is moving and you fear it",
              });
   
   smell = "You smell the odor of salt and sea.";              
}

init( )
{
   ::init( );
   
   add_action( "search",   "search" );
   add_action( "drink_it", "drink" );
   add_action( "swim_it", "swim" );
   add_action( "dive_it", "dive" );
   add_action( "north",   "north" );
   add_action( "south",   "south" );
}

search( arg )
{
   write("Searching in the sea ???\n");
   
   return( 1 );
}

dive_it( arg )
{
   if ( !arg || arg == "down" ) {
      this_player()->move_player("diving down#"+
                                 "/players/tatsuo/ezo/ryuworld/wo1" );
      return( 1 );
   }
   
   return( 0 );
}

drink_it( arg )
{
   if ( !arg )
      return;
   
   if ( arg == "water" || arg == "water from sea" || arg == "water from nihonese sea" ||
        arg == "salt-water" || arg == "salt water" || arg == "saltwater" )
   {
      write( "As you drink some salty water from the sea, you get a bad feeling.\n" );
      say( TPN + " drinks some water.\n" );
      TP->add_poison( 3 );
      return( 1 );
   }
   
   return( 0 );
}

swim_it( arg )
{
   if ( !arg ) {
      write( "Please give a direction.\n" );
      return( 1 );
   }
   else if ( arg == "north" || arg == "to coast" ) {
      TP->move_player( "north#players/tatsuo/ezo/coast/rf21" );
      return( 1 );
   }
   else if ( arg == "south" || arg == "to shore" ) {
      TP->move_player( "south#players/tatsuo/ezo/coast/sh1" );
      return( 1 );
   }
   
   return( 0 );
}

north( )
{
   return( swim_it( "north" ) );
}

south( )
{
   return( swim_it( "south" ) );
}
