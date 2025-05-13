#define PPATH  "/players/tatsuo/ezo/coast/"
#define MONST  "/players/tatsuo/coastMonst/coastMonst"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";
string rockFaceDirs, shoreDirs;
object monster;
reset(arg) {
   if(!random(9) && !present("sandworm",this_object())) {
       move_object(clone_object("/players/tatsuo/npc/worm"),
       this_object());
    }
   if ( (!monster || !present(monster, this_object())) && random(100) < 60 ) {
      monster = clone_object( MONST->rnd_monster() );
      if ( transfer( monster, this_object() ) )
         destruct( monster );
   }
   if(arg) return;
   set_light(1);
   short_desc = "At a shore";
   long_desc = build_long_desc( );
   items=({
	"shore", long_desc,
        "ground", "The ground is sandy",
        "sand", "It is a light yellow sand",
        "sky", "The sky is blue with a few clouds on it",
        "clouds", "The clouds have a dirty white color",
        "sea", "Water as far as the eye can see",
        "nihonese sea", "Water as far as the eye can see",
        "water", "It is salt water. The waves are rolling onto the island",
        "wave", "This wave is a very big one",
        "waves", "The waves are rolling into the island",
         "horizon", "It is really far away",
        "volcano", "@@l_volcano@@",
        "rock face", "@@l_rockface@@",
	"dock","An old fishing dock.  If you wait long enough, a boat may come",
   });
   smell = "The air smells salty here.";              
}

init() {
   ::init( );
   add_action( "climb_it", "climb" );
   add_action( "drink_it", "drink" );
   add_action( "swim_it", "swim" );
   add_action( "enter_it", "enter" );
}

climb_it(arg) {
   if(!arg) return;
   if ( arg == "rock face" || arg == "volcano" ) {
      write( "The rock face is much too steep for climbing.\n" );
      say( TPN + " tries to climb the rock face, but fails.\n" );
      return( 1 );
   }
   return( 0 );
}

drink_it(arg) {
   if(!arg) return;
   if ( arg == "water" || arg == "water from sea" || arg == "water from nihonese sea" ||
        arg == "salt water" ) {
      write( "As you drink some salty water from the sea, you get a bad feeling.\n" );
      say( TPN + " drinks some water.\n" );
      TP->add_poison( 3 );
      return( 1 );
   }
   return( 0 );
}

enter_it(arg) {
   if(!arg) return;
   if ( arg == "water" || arg == "sea" || arg == "nihonese sea" )
      return( swim_it() );
   return( 0 );
}

swim_it(arg) {
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

build_long_desc() {
   string s;
   s =  "You are standing on the shore of the island of Ezo. The ground\n"+
	"here is sandy and you can see waves rolling in from the ocean.\n"+
	"Far away over the sea you see the horizon.\n";
   s += "The shore continues " + query_shore_dirs();
   
   if ( query_rf_dirs() && strlen( query_rf_dirs() ) )
      s += "and to your "+query_rf_dirs()+"\nis the rock face of the volcano";
   s += ".\n";
   return( s );
}

query_rf_dirs() {
   return( rockFaceDirs );
}

set_rf_dirs(s) {
   rockFaceDirs = s;
}

query_shore_dirs() {
   return( shoreDirs );
}

set_shore_dirs(s) {
   shoreDirs = s;
}

l_volcano() {
   if ( query_rf_dirs( ) )
      return( "The volcano is very high and looks extremely steep" );
   else
      return( "You cannot see the volcano from here" );
}

l_rockface() {
   if ( query_rf_dirs( ) )
      return( "You almost think that the rock face rises up to eternity" );
   else
      return( "You cannot see the rock face from here" );
}
