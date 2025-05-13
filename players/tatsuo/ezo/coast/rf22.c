#define PPATH  "/players/tatsuo/ezo/coast/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";

string rockFaceDirs, coastDirs;

reset( arg )
{
   if ( arg )
      return;
   
   set_rf_dirs( "northeast, east, southeast and south" );
   set_coast_dirs( "southwest, west and northeast" );
   
   set_light(1);
   short_desc = "At a slope";
   long_desc = build_long_desc( );
   items = ({ "slope", long_desc,
              "ground", "The ground consists of lava and mist rises from it",
              "lava", "It is dark black lava, already cooled",
              "vegetation", "You can see some tiny, crippled plants",
              "plants", "They are tiny and crippled. Some of them are nearly rotten",
              "plant", "This is a tiny, crippled, nearly rotten plant",
              "rock face", "You think that the rock face rises up to eternity",
              "eternity", "You cannot escape from it",
              "sky", "The sky is blue with a few clouds on it",
              "clouds", "The coulds have a dirty white color",
              "mist", "It is dirty white mist which comes out of the ground",
              "volcano", "The volcano is very high and looks extremely steep",
              "sea", "@@l_sea@@",
              "nihonese sea", "@@l_sea@@",
              "water", "@@l_water@@",
              "wave", "@@l_wave@@",
              "waves", "@@l_wave@@",
              "tree", "It is very huge but nearly carbonized tree",
              });
   
   dest_dir = ({ PPATH + "rf20",  "north",
              });

   smell = "You smell the odor of smoke and destruction.";              
}


init( )
{
   ::init( );
   
   add_action( "search", "search" );
   add_action( "get_it", "get" );
   add_action( "get_it", "take" );
   add_action( "get_it", "pick" );
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

get_it( arg )
{
   if ( !arg )
      return;
      
   if ( arg == "plant" || arg == "plants" || arg == "vegetations" ) {
      write( "As you try to get one of the plants, it suddenly rots in your hand.\n" );
      return( 1 );
   }
   
   return( 0 );
}

climb_it( arg )
{
   if ( !arg )
      return;
      
   if ( arg == "rock face" || arg == "volcano" ) {
      write( "The rock face is much too steep for climbing.\n" );
      say( TPN + " tries to climb the rock face, but fails.\n" );
      return( 1 );
   }
   else if ( arg == "tree" ) {
      if ( check_tekagi() ) {
         write( "You manage it to climb up with your tekagi.\n" );
         this_player()->move_player( "up the tree#players/tatsuo/ezo/coast/inTree" );
      }
      else {
         write( "You can't find a hold on the carbonized tree.\n" +
                "Maybe you need something which helps you climbing !?\n" );
         say( TPN + " tries to climb up the tree but fails.\n" );
      }
   
      return( 1 );
   }
   else if ( arg == "up" ) {
      write( "What do you want to climb ?\n" );
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
      if ( query_coast_dirs() ) {
         write( "You jump into the water and swim around for a while.\n" );
         say( TPN + " jumps into the water and swims around for a while.\n" );
      }
      else
         write( "Do you see a sea or a lake here ?/n" );
         
      return( 1 );
   }
   
   return( 0 );
}

build_long_desc( )
{
   string s;

   s = "You are standing on a slope of the island of Ezo. The ground consists of\n" +
       "lava and there is very sparse vegetation here. Mist rises from the ground.\n" +
       "A very old and extremely CARBONIZED TREE stands at the the southern rock face.\n";
   
   if ( query_rf_dirs() )
      s += "To your " + query_rf_dirs() + " is the rock face of the volcano";
   
   if ( query_coast_dirs() )
      s += "\nand to your " + query_coast_dirs() + " is the nihonese sea";
      
   s += ".\n";

   return( s );
}

query_rf_dirs( arg )
{
   return( rockFaceDirs );
}

set_rf_dirs( s )
{
   rockFaceDirs = s;
}

query_coast_dirs( )
{
   return( coastDirs );
}

set_coast_dirs( s )
{
   coastDirs = s;
}

l_sea( )
{
   if ( query_coast_dirs() )
      return( "Water as far as the eye can see" );
   else
      return( "You can't see the sea from here" );
}

l_water( )
{
   if ( query_coast_dirs() )
      return( "It is salt water. The waves are rolling onto the island" );
   else
      return( "You can't see the sea from here" );
}

l_wave( )
{
   if ( query_coast_dirs() )
      return( "The waves are rolling onto the island" );
   else
      return( "You can't see the sea from here" );
}

check_tekagi( )
{
   int    i;

   for ( i = 0; i < sizeof(TP->query_armour()); i++ ) {
      if ( (TP->query_armour())[i] && (TP->query_armour())[i]->id( "tekagi" ) )
         return( 1 );
   }

   return( 0 );
}
