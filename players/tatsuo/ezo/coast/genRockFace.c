#define PPATH  "/players/tatsuo/ezo/coast"
#define MONST  ("/players/tatsuo/smallMonst/smallMonst")
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";
string rockFaceDirs, coastDirs;
object monster;
reset(arg) {;
   if(!random(3) && !present("gigantic eagle",this_object())) {
         move_object(clone_object("/players/tatsuo/npc/roc"),
         this_object());
      }
   if ( (!monster || !present(monster, this_object())) && random(100) < 40 ) {
      monster = clone_object( MONST->rnd_monster() );
      if ( transfer( monster, this_object() ) )
         destruct( monster );
   }
   if(arg) return;
   set_light(1);
   short_desc = "At a slope";
   long_desc = build_long_desc()+"\n";
   items=({
	"slope", long_desc,
        "ground", "The ground consists of lava and mist rises from it",
        "lava", "It is dark black lava rock, already cooled",
        "vegetation", "You can see some tiny, crippled plants",
        "plants", "They are tiny and crippled. Some of them are nearly rotten",
        "plant", "This is a tiny, crippled, nearly rotten plant",
        "rock face", "You almost think that the rock face rises up to eternity",
        "eternity", "You cannot escape from it",
        "sky", "The sky is blue with a few clouds on it",
        "clouds", "The clouds have a dirty white color",
        "mist", "It is dirty white mist, which comes out of the ground",
        "volcano", "The volcano is very high and looks extremely steep",
        "sea", "@@l_sea@@",
        "nihonese sea", "@@l_sea@@",
        "water", "@@l_water@@",
        "wave", "@@l_wave@@",
        "waves", "@@l_wave@@",
   });
   smell = "You smell the odor of smoke and destruction.";              
}

init() {
   ::init( );
   add_action( "get_it", "get" );
   add_action( "get_it", "take" );
   add_action( "get_it", "pick" );
   add_action( "climb_it", "climb" );
   add_action( "drink_it", "drink" );
   add_action( "swim_it", "swim" );
   add_action( "enter_it", "enter" );
}

   
get_it(arg) {
   if(!arg) return;
   if ( arg == "plant" || arg == "plants" || arg == "vegetations" ) {
       write("As you try to collect one of the plants, it degrades in your hand.\n");
      return( 1 );
   }
   return( 0 );
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
      write("As you drink some of the salty water, It burns your throat\n");
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
   s =  "You are standing on a slope of the island of Ezo. The ground\n"+
	"consists of dried lava and there is very sparse vegetation here.\n"+
	"Mist slowly rises up from the ground.\n";
   if ( query_rf_dirs() )
      s += "To your " + query_rf_dirs() + " is the rock face of the volcano";
   if ( query_coast_dirs() )
    s += "\nand to your "+query_coast_dirs()+" is the nihonese sea.\n";
   return( s );
}

query_rf_dirs(arg) {
   return( rockFaceDirs );
}

set_rf_dirs(s) {
   rockFaceDirs = s;
}

query_coast_dirs() {
   return( coastDirs );
}

set_coast_dirs(s) {
   coastDirs = s;
}

l_sea() {
   if ( query_coast_dirs() )
      return( "Water as far as the eye can see" );
   else
      return( "You can't see the sea from here" );
}

l_water() {
   if ( query_coast_dirs() )
      return( "It is salt water. The waves are rolling onto the island" );
   else
      return( "You can't see the sea from here" );
}

l_wave() {
   if ( query_coast_dirs() )
      return( "The waves are rolling into the island" );
   else
      return( "You can't see the sea from here" );
}
