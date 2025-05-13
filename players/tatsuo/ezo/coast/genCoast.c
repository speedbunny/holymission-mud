#define PPATH  "/players/tatsuo/ezo/coast"
#define MONST  ("/players/tatsuo/coastMonst/coastMonst")
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";
int    tekagiHere, tekagiExists;
object monster;
reset(arg) {
   if ( (!monster || !present(monster, this_object())) && random(100) < 60 ) {
      monster = clone_object( MONST->rnd_monster() );
      if ( transfer( monster, this_object() ) )
         destruct( monster );
   }
   if ( tekagiExists )
      tekagiHere = 1;
   if(arg) return;
   set_light(1);
   short_desc = "At the coast";
   long_desc=
	"You are standing on the coast of the island of Ezo. The ground\n"+
	"here is sandy and, far, far away you can see the horizon. The\n"+
	"waves are rolling in onto the coast. You feel very peaceful.\n";
   items=({
	"coast", long_desc,
        "ground", "@@l_ground@@",
        "sand", "@@l_sand@@",
        "sands", "@@l_sand@@",
        "sky", "The sky is blue with a few clouds in it",
	"clouds","The clouds have a dirty white color",
        "volcano", "The volcano is very high and looks extremely steep",
        "sea", "Water, as far as your eye can see",
        "nihonese sea", "Water, as far as your eye can see",
        "water", "It is salt water. The waves are rolling into the island",
        "wave", "This wave is a very big one",
        "waves", "The waves are rolling onto the island",
        "horizon", "It is really far away",
   });
   smell = "You smell the odor of salt and sea.";              
}

init() {
   ::init( );
   add_action( "search", "search" );
   add_action( "get_it", "get" );
   add_action( "get_it", "take" );
   add_action( "drink_it", "drink" );
   add_action( "swim_it", "swim" );
   add_action( "enter_it", "enter" );
}

search(arg) {
   object tekagi;
   if(!arg) return;
   if(arg == "sand" || arg == "ground" ) {
      if(tekagiHere) {
         write("You found a pair of tekagi in the sand.\n");
         tekagiHere=0;
         tekagi=clone_object("/players/tatsuo/guild/narmour/tekagi");
         if(tekagi)
         transfer(tekagi, this_object());
         return 1;
      }
   }
   write("You search and search, but find nothing.\n");
   say(this_player()->query_name()+" looks around aimlessly.\n");
   return 1;
}

/*
get_it(arg) {
  object tekagi;
      if ( tekagiHere ) {
         write( "You found a pair of tekagi !!!\n" );
         tekagiHere = 0;
         tekagi = clone_object( "/players/tatsuo/guild/narmour/tekagi" );
         if ( tekagi )
            transfer( tekagi, this_object() );
         return( 1 );
      }
   
   write("You search and search, but find nothing special.\n");
   say(this_player()->query_name()+" searches around.\n");
   return( 1 );
}
*/

get_it(arg) {
   object tekagi;
   if(!arg) return;
   if ( arg == "sand" || arg == "sands" ) {
      write( "You try very hard to get the sand, but it always slips through your fingers.\n" );
      return( 1 );
   }
   else if ( tekagiHere && (arg == "tekagi" || arg == "pair of tekagi") &&
             !present( "tekagi", this_object() ) )
   {
      tekagi = clone_object( "/players/tatsuo/guild/narmour/tekagi" );
      if ( tekagi ) {
         if ( transfer( tekagi, TP ) ) {
            write( "Sorry, but you can't take anymore.\n" );
            destruct( tekagi );
            return( 1 );
         }
         else
            write( "Ok.\n" );
      }
      tekagiHere = 0;
      return( 1 );
   }
   return( 0 );
}

climb_it(arg) {
   if(!arg) return;
   if ( arg == "rock face" || arg == "volcano" ) {
      write( "Go to the volcano and then try it again.\n" );
      return( 1 );
   }
   return( 0 );
}

drink_it(arg) {
   if(!arg) return;
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

enter_it(arg) {
   if(!arg) return;
   if ( arg == "water" || arg == "sea" || arg == "nihonese sea" )
      return( swim_it() );
   return( 0 );
}

swim_it(arg) {
   if ( !arg || arg == "water" || arg == "around" || arg == "sea" ) {
      write( "You jump into the water and swim around for a while.\n" );
      say( TPN + " jumps into the water and swims around for a while.\n" );
      return( 1 );
   }
   return( 0 );
}

set_tekagi() {
   tekagiExists = 1;
}

query_tekagi() {
   return( tekagiExists );
}

l_ground() {
   if ( tekagiHere )
      return( "The ground consists of sand. But there is something strange with it" );
   else
      return( "The ground consists of sand" );
}

l_sand() {
   if ( tekagiHere )
      return( "The sand is light yellow and you can see a pair of tekagi almost covered with sand" );
   else
      return( "The sand is light yellow" );
}
