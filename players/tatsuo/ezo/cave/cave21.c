#define PPATH "/players/tatsuo/ezo/cave/"
#define TP  this_player()
#define TPN TP->query_name()
#define TO     (this_object())

inherit "room/room";
int    caltropsChance;
reset(arg) {
   object caltrops;
   set_caltrops_chance( 100 );
   ::reset( arg );
   if ( caltropsChance > random( 100 ) ) {
      if ( !present( "caltrops", TO ) ) {
         caltrops = clone_object( "/players/tatsuo/guild/nweap/caltrops" );
         if ( transfer( caltrops, TO ) )
            destruct( caltrops );
      }
   }
   if(arg) return;
   set_light(1);
   short_desc = "At a opening";
   long_desc=
	"You are in a cave inside the volcano of the island of Ezo. The\n"+
	"walls in here are black and very dark. But to the north you can\n"+
	"see an opening. Looking through the opening you see the nihonese\n"+
	"sea and a wide sandy coast. In front of the opening, is a large\n"+
	"carbonized tree.\n";
   items=({
	"cave", long_desc,
        "floor", "The floor is deep black and consits of lava",
        "walls", "The walls are deep black and consit of lava",
        "wall", "The wall is deep black and consits of lava",
        "lava", "It is melted stone and deep black",
        "volcano", "You fail to look at things, from which you are a part",
        "opening", "It is a the opening is large enough for you",
        "sea", "Water, as far as your eye can see",
        "nihonese sea", "Water, as far as your eye can see",
        "water", "It is salt-water. The waves are rolling onto the island",
        "wave", "The waves are rolling onto the island",
        "waves", "The waves are rolling onto the island",
        "vegetation", "You can see some tiny, crippled plants",
        "plants", "They are tiny and crippled. Some of them are nearly rotten",
        "plant", "This is a tiny, crippled, nearly rotten plant",
	"rock face","You think that the rock face extends almost to eternity",
        "eternity", "You cannot escape from it",
        "sky", "The sky is blue with a few clouds on it",
	"clouds","The clouds have a dirty white color",
        "mist", "It is dirty white mist, which comes out of the ground",
        "hole","It is a narrow opening but you think it's large enough for you",
        "tree", "It is a large, carbonized tree",
   });

   dest_dir=({
	PPATH + "cave22","east",
	PPATH + "cave26","south",
   });
   smell = "You smell the odor of death and destruction.";

}

init() {
   object caltrops;
   ::init( );
   add_action( "listen", "listen" );
   add_action( "north",  "north"  );
   add_action( "jump_it","jump"   );
   caltrops = present( "caltrops", TO );
   if ( caltrops ) {
      if ( TP->query_guild() == 8 ) {
         write( "As you enter the cave, you see some caltrops lying on the ground.\n" +
                "So you place your steps cautiosly to avoid to step onto one.\n" );
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

north(arg) {
   write( "You make a big step out of the hole but the tree is much too far away.\n" +
          "So you fall down the rock face. OUCH !!\n" );
   TP->hit_player( 15 );
   TP->move_player( "down#players/tatsuo/ezo/coast/rf22" );
   return( 1 );
}

jump_it(arg) {
   if(!arg) return;
   if ( arg == "tree" || arg == "at tree" || arg == "onto tree" || arg == "in tree" ||
	arg == "to tree" || arg == "into tree" ) {
      write( "You concentrate yourself and summon all your forces. Then you make a big\n" +
             "jump and jump into the tree.\n" );
      TP->move_player( "into the tree#players/tatsuo/ezo/coast/inTree" );
      return( 1 );
   }
   return( 0 );
}

listen(arg) {
   write("You listen carefully but you can only hear someones devilish laughter");
   say( TPN + " frowns.\n" );
   return( 1 );
}

set_caltrops_chance(c) {
   caltropsChance = c;
}

query_caltrops_chance(c) {
   return( caltropsChance );
}
