#define PPATH  "/players/tatsuo/ezo/forest/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";

reset( arg )
{
   if ( arg )
      return;
      
   set_light( 1 );
      
   short_desc = "At a clearing";
   long_desc = "You are standing on a clearing in the dark forest. The ground here\n" +
               "is grassy and you can see beautiful forestflowers here. In the\n" +
               "middle of the clearing is an old buddhistic temple.\n";
   items = ({ "clearing", long_desc,
              "ground", "The ground is grassy and you can see flowers here",
              "trees", "The trees are very old and very big",
              "tree", "The tree is very old and very big",
              "grass", "The grass has a fresh green color",
              "forestflowers", "The flowers are very beautiful to look at",
              "forestflower", "This flower is very pretty and you don't want stop looking at it",
              "sky", "You are under a blue sky",
              "temple", "The temple is open to all sides and invites you to enter",
              });

   dest_dir = ({ PPATH + "f21",  "north",
                 PPATH + "f22",  "northeast",
                 PPATH + "f27",  "east",
                 PPATH + "f32",  "southeast",
                 PPATH + "f31",  "south",
                 PPATH + "f30",  "southwest",
                 PPATH + "f25",  "west",
                 PPATH + "f20",  "northwest",
              });
   
   smell = "You smell the odor of religious items.";              
}


init( )
{
   ::init( );
   
   add_action( "search", "search" );
   add_action( "climb_it", "climb" );
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
   if ( !arg || arg == "up" ) {
      write( "Climb what ?\n" );
      return( 1 );
   }
      
   if ( arg == "temple" ) {
      write( "You remember, that the priests don't like this at all, so you stop.\n" );
      return( 1 );
   }
   else if ( arg == "tree" )
   {
      write( "Go into the forest and try it again.\n" );   
      return( 1 );
   }
   
   return( 0 );
}

enter_it( arg )
{
   if ( !arg )
      return;
      
   if ( arg == "temple" ) {
      TP->move_player( "into the temple#players/tatsuo/ezo/forest/forestTemple" );
      return( 1 );
   }
}
