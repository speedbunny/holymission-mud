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
	"You are in cave inside the volcano of the island of Ezo. The walls\n"+
        "in here are black and very dark. But to east can you see a narrow\n" +
	"opening. Looking through the opening you see a large fortress,\n"+
	"built in nihoneses styling, surrounded by a very beautiful meadow.\n"+
	"You recognize that this is the crater of the volcano. The valley\n"+
	"is enclosed by a high rock face.\n";
   items=({
	"cave", long_desc,
        "floor", "The floor is deep black and consits of lava",
        "walls", "The walls are deep black and consit of lava",
        "wall", "The wall is deep black and consits of lava",
        "lava", "It is melted stone and deep black",
        "fortress", "It is a large fortress, built in nihonese styling",
        "meadow", "The meadow is very pretty and there are some flowers on it",
	"flowers","You can't tell from here what kind of flowers they are",
        "crater", "It is the crater of the volcano",
	"rock face","You think that the rock face extends almost to eternity",
        "eternity", "You cannot escape from it",
        "volcano", "You fail to look at things, from which you are a part",
        "opening","It is a narrow opening. But you think it's large enough for you",
        "hole","It is a narrow opening. But you think it's large enough for you",
   });
   dest_dir=({
	"players/tatsuo/ezo/meadow29","east",
	PPATH + "cave19","south",
   });
   smell = "You smell the odor of orchids.";
}

init() {
   object caltrops;
   ::init( );
   add_action( "listen", "listen" );
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

listen(arg) {
   write("You listen carefully but the only thing you can hear is someone's devilish\nlaughter.\n");
   say( TPN + " frowns.\n" );
   return( 1 );
}

set_caltrops_chance(c) {
   caltropsChance = c;
}

query_caltrops_chance(c) {
   return( caltropsChance );
}
