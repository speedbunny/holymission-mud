#define PPATH  "/players/tatsuo/ezo/"
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
   short_desc = "In the carbonized tree";
   long_desc = "You are sitting on a big branch in the carbonized tree. All around you\n" +
               "are weak looking branches. You can see the nihonese sea and the rock face\n" +
               "rising to eternity. But as you look at the southern rock face, you see\n" +
               "a dark hole.\n";
   items = ({ "tree", long_desc,
              "ground", "The ground consists of lava and mist rises from it",
              "lava", "It is dark black lava, already cooled",
              "vegetation", "You can see some tiny, crippled plants",
              "plants", "They are tiny and crippled. Some of them are nearly rotten",
              "plant", "This is a tiny, crippled, nearly rotten plant",
              "rock face", "You almost think that the rock face rises up to eternity",
              "eternity", "You cannot escape from it",
              "sky", "The sky is blue with a few clouds in it",
              "clouds", "The clouds have a dirty white color",
              "mist", "It is dirty white mist rising from the ground",
              "volcano", "The volcano is very high and looks extremely steep",
              "sea", "@@l_sea@@",
              "nihonese sea", "@@l_sea@@",
              "water", "@@l_water@@",
              "wave", "@@l_wave@@",
              "waves", "@@l_wave@@",
              "branches", "Except for the branch that you are sitting on, they look very weak",
              "hole", "The hole is very dark and you are afraid of it",
              });
   
   smell = "You smell the odor of coal and destruction.";
}


init( )
{
   ::init( );
   
   add_action( "search", "search" );
   add_action( "climb_it", "climb" );
   add_action( "climb_it", "down" );
   add_action( "enter_it", "enter" );
   add_action( "jump_it", "jump" );
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
   object tekagi;

   if ( !arg || arg == "down" )
   {
      if ( !check_tekagi() ) {
         write( "You don't get a hold on the tree and so you fall down. OUCH !!\n" );
         say( TPN + " can't get a hold on the tree and falls down.\n" );
         TP->hit_player( 10 );
      }
      TP->move_player( "down the tree#players/tatsuo/ezo/coast/rf22" );
      return( 1 );
   }
   
   write( "You only can climb down from here.\n" );
   return( 1 );
}

enter_it( arg )
{
   if ( !arg )
      return;
      
   if ( arg == "hole" || arg == "dark hole" ) {
      write( "You crawl into the hole.\n" );
      TP->move_player( "into the hole#players/tatsuo/ezo/cave/cave21" );

      return( 1 );
   }

   return( 0 );
}

jump_it( arg )
{
   if ( !arg )
      return;
      
   if ( arg == "hole" || arg == "at hole" || arg == "onto hole" || arg == "in hole" ||
        arg == "to hole" || arg == "into hole" )
   {
      write( "You concentrate and summon all your forces. Then you make a big\n" +
             "jump and jump into the hole.\n" );
      TP->move_player( "into the hole#players/tatsuo/ezo/cave/cave21" );
   
      return( 1 );
   }

   return( 0 );
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
