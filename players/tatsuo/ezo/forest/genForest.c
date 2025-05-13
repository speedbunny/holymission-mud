#define PPATH  "/players/tatsuo/ezo/coast"
#define FMONST "/players/tatsuo/forestMonst/forestMonst"
#define EMPATH "/players/tatsuo/eastMonst/"

#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

#define MOSS   "/players/tatsuo/guild/nother/ref_moss"

inherit "room/room";

string rockFaceDirs, upDir;
object monster;
object tree;
int    mossLevel;

reset( arg )
{
   if (!random(8) && !present("strange tree",this_object()))
   {
       move_object(clone_object("/players/tatsuo/npc/tree"),
       this_object());
   }
   
   if ( (!monster || !present(monster, this_object())) && random(100) < 50 ) {
      if ( random(10) < 3 )
         monster = clone_object( EMPATH + "gaki" );
      else
         monster = clone_object( FMONST->rnd_monster() );
      if ( transfer( monster, this_object() ) )
         destruct( monster );
   }
   mossLevel = 3;
   
   if ( arg )
      return;
      
   set_light( 0 );
      
   short_desc = "In a dark forest";
   long_desc = build_long_desc( );
   items = ({ "forest", long_desc,
              "ground", "It is that kind of ground you normally find in a forest",
              "rock-face", "@@l_rockface@@",
              "eternity", "You cannot escape from it",
              "sky", "You cannot see the sky from here",
              "vulcano", "@@l_vulcano@@",
              "tree", "This one is a birch-tree. Maybe you can tear some bark off ?",
              "trees", "There are very different kinds of trees here.\n" +
                       "Some of them are birch-trees.",
              "moss", "@@check_moss@@",
              });
   
   smell = "Typical smell of a forest.";              
}


init( )
{
   ::init( );
   
   add_action( "search", "search" );
   add_action( "climb_it", "climb" );
   add_action( "tear_off", "tear" );
   add_action( "scratch_off", "scratch" );
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
      
   if ( arg == "rock-face" || arg == "vulcano" ) {
      write( "The rock-face is much too steep for climbing.\n" );
      say( TPN + " tries to climb the rock-face, but fails.\n" );
      return( 1 );
   }
   else if ( (arg == "tree") &&
             (query_up_dir() && strlen(query_up_dir()) ) )
   {
      if ( check_tekagi() ) {
         write( "You manage it to climb up with your tekagi.\n" );
         TP->move_player( "up the tree", query_up_dir() );
      }
      else {
         write( "You can't find a halt at the tree.\n" +
                "Maybe you need something which helps you climbing !?\n" );
         say( TPN + " tries to climb up the tree but fails.\n" );
      }
   
      return( 1 );
   }
   
   return( 0 );
}

tear_off( arg )
{
   if ( !arg )
      return;

   if ( arg == "bark" || arg == "off bark" || arg == "off some bark" ) {
      write( "The bark is much too massive in the lower regions of the tree,\n" +
             "so your attempt fails.\n" );
      say( this_player()->query_name() + " tries to tear off some bark, but fails.\n" );
      return( 1 );
   }
}

scratch_off( arg )
{
   object moss;

   if ( !arg )
      return;
      
   if ( arg == "off some moss" || arg == "some moss off" || arg == "off moss" ||
        arg == "moss off" )
   {
      if ( mossLevel > 0 ) {
         moss = clone_object( MOSS );
         if ( transfer( moss, this_player() ) ) {
            write( "Sorry, but you cannot take more.\n" );
            destruct( moss );
         }
         else {
            write( "You scratch off some moss.\n" );
            mossLevel--;
         }
      }
      else
         write( "Sorry, but there is no moss here.\n" );
   }
   else
      write( "What do you want to scratch off ?\n" );
      
   return( 1 );
}

build_long_desc( )
{
   string s;

   s = "You are in a really dark forest at the island of Ezo. You hardly can see\n" +
       "any further than to your nose. The trees here are all very big and very old";
   
   if ( mossLevel > 0 )
      s += "\nand covered with moss near the ground.\n";
   else
      s += ".\n";
   
   if ( query_rf_dirs() )
      s += "To your " + query_rf_dirs() + " is the rock-face of the vulcano.\n";

   return( s );
}

query_rf_dirs( )
{
   if ( rockFaceDirs && strlen( rockFaceDirs ) )
      return( rockFaceDirs );
}

set_rf_dirs( s )
{
   rockFaceDirs = s;
}

query_up_dir( )
{
   return( upDir );
}

set_up_dir( s )
{
   upDir = s;
}

l_rockface( )
{
   if ( query_rf_dirs() )
      return( "You cannot escape from it" );
   else
      return( "There is no rock-face here" );
}

l_vulcano( )
{
   if ( query_rf_dirs() )
      return( "The vulcano is very high and looks extremely steep" );
   else
      return( "There is no vulcano here" );
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

check_moss()
{
   if ( mossLevel > 0 )
      return( "The moss is dark green and is a little bit fluorescent.\n" +
              "Maybe you can scratch some off" );
   else
      return( "There is no moss here" );
}
