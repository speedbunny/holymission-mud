#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define TO     (this_object())
#define MONST_PATH "/players/tatsuo/eastMonst/"

inherit "room/room";
int    caltropsChance, monstChance;
string monster_str;
object monster;
   object caltrops;
   int i;
reset(arg) {
   ::reset( arg );
   if(!random(3) && !present("cave fungus",this_object())) {
       move_object(clone_object("/players/tatsuo/npc/fungus"),
       this_object());
   }
   if ( caltropsChance > random( 300 ) ) {
      if ( !present( "caltrops", TO ) ) {
         caltrops = clone_object( "/players/tatsuo/guild/nweap/caltrops" );
            if (objectp(caltrops) )
             move_object(caltrops,TO);
            destruct( caltrops );
      }
   }
   if ( !random(4) && !present( "_antidodes_herb_", this_object() ) ) {
      move_object(clone_object("/players/tatsuo/guild/nother/antidodes_herb"),
                   this_object() );
   }
   if ( !monster ) {
      for ( i = 0; i < 5; i++ ) {
          if (monstChance > random(100) && stringp(monster_str) ) {
            monster = clone_object( MONST_PATH + monster_str );
            if (objectp(monster))
                move_object( monster,TO);
         }
      }
   }
   if(arg) return;
   set_light(0);
   short_desc = "In the volcano";
   long_desc=
	"You are in a cave inside the volcano of the island of Ezo. The\n"+
	"walls in here are dark black and opressing. It is very hot.\n"+
	"Devilish laughter seems to be coming from everywhere and nowhere at\n"+
	"the same time you can feel creatures staring at you with dead\n"+
	"eyes and little hands tearing at your clothes.  You quickly turn\n"+
	"around but still you can't see anything.\n";
   items=({
	"cave", long_desc,
        "floor", "The floor is deep black and consists of dried lava",
        "walls", "The walls are deep black and consist of dried lava",
        "wall", "The wall is deep black and consists of dried lava",
        "lava", "It is melted stone and deep black",
        "creatures", "You quickly turn around but you only see darkness",
        "creature", "You quickly turn around but you only see darkness",
	"darkness","You can hardly see your hand before your eyes..",
   });
   smell="The air in here is foul, you can detect the faint smell of a ryu.";
}

init() {
   object caltrops;
   ::init( );
   add_action( "listen", "listen" );
   caltrops = present( "caltrops", TO );
   if ( caltrops ) {
      if ( TP->query_guild() == 8 ) {
         write( "As you enter the cave you recognize that some caltrops are lying on the\n" +
                "ground. So you place your steps cautiously to avoid stepping onto one.\n" );
      }
      else {
         write( "As you enter the cave, you step into some caltrops and hurt yourself badly.\n" );
         if ( TP->query_armour()[TP->query_arm_types("boot")] ) {
            TP->hit_player( TP->query_weight() );
            write( "But your boots can avoid the damage a little bit.\n" );
         }
         else
            TP->hit_player( TP->query_weight() * 2 );
         destruct( caltrops );
      }
   }
}

listen(arg) {
   write( "You listen carefully but can only hear the devilish laughter.\n" );
   say( TPN + " frowns.\n" );
   return( 1 );
}

set_caltrops_chance(c) {
   caltropsChance = c;
}

query_caltrops_chance(c) {
   return( caltropsChance );
}

set_monster(p,m) {
   monstChance = p;
   monster_str = m;
}
