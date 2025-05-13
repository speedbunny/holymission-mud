#define PPATH  "/players/tatsuo/ezo/coast/"
#define FPATH  "/players/tatsuo/ezo/forest/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";

reset( arg )
{
   if ( arg )
      return;
      
   set_light(1);
   short_desc = "At a shore";
   long_desc = build_long_desc( );
   items = ({ "shore", long_desc,
              "ground", "The ground is sandy",
              "sand", "It is a light yellow sand",
              "sky", "The sky is blue with a few clouds on it",
              "clouds", "The coulds have a dirty-white color",
              "sea", "Water, as far as your eye can see",
              "nihonese sea", "Water, as far as your eye can see",
              "water", "It is salt-water. The waves are rolling onto the island",
              "wave", "This wave is a very big one",
              "waves", "The waves are rolling onto the island",
              "horizon", "It is really far away",
              "eternity", "You are prisoned in it",
              "rock-face", "@@l_rockface@@",
              "cliff", "@@l_rockface@@",
           });
           
   dest_dir = ({ PPATH + "sh13",  "north",
                 FPATH + "f24",   "northeast",
                 FPATH + "f29",   "east",
              });
  
   smell = "The air smells salty here.";              
}


init( )
{
   ::init( );
   
   add_action( "search", "search" );
   add_action( "climb_it", "climb" );
   add_action( "drink_it", "drink" );
   add_action( "swim_it", "swim" );
   add_action( "enter_it", "enter" );
}

search( arg )
{
   if ( !arg )
      return;
         
   write("You search and search, but find nothing special.\n");
   say(this_player()->query_name()+" searches around.\n");
   
   return( 1 );
}

climb_it( arg )
{
   if ( !arg )
      return;
      
   if ( arg == "rock-face" || arg == "cliff" ) {
      write( "There are too much loose stones, so you cannot find a halt and fail.\n" );
      say( TPN + " tries to climb the cliff, but fails.\n" );
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

enter_it( arg )
{
   if ( !arg )
      return;
      
   if ( arg == "water" || arg == "sea" || arg == "nihonese sea" )
      return( swim_it() );
      
   return( 0 );
}

swim_it( arg )
{
   if ( !arg || arg == "water" || arg == "around" || arg == "sea" ) {
       write( "You jump into the water and swim around for a while.\n" );
       say( TPN + " jumps into the water and swims around for a while.\n" );
         
      return( 1 );
   }
   
   return( 0 );
}

build_long_desc( )
{
   string s;

   s = "You are standing at the shore of the island of Ezo. The ground here is sandy\n" +
       "and you can see waves rolling in. Far, far away can you see the horizon.\n" +
       "The shore continues to the north and to the southeast is a high cliff.\n";
     
   return( s );
}

l_rockface( )
{
   return( "You think, that the cliff almost zoom up to eternity" );
}
