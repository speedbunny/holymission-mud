#define PPATH "/players/tatsuo/ezo/"
#define TP  this_player()
#define TPN TP->query_name()

inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "At the entrance";
   long_desc=
	"This is the entrance of the residence of Matsumae Yoshihiro, the\n"+
	"evil Shogun of the island of Ezo. The ground here is consists\n"+
	"of grass. To the south you can see the inner-yard and north is\n"+
	"a large grassy plain. To the east and west are strong walls.\n";
   items=({
	"entrance", long_desc,
        "ground", "The ground is grassy",
        "grass", "It is almosted stamped down but it has a fresh green color",
        "inner-yard", "It is the inner-yard of the residence",
        "yard", "It is the inner-yard of the residence",
        "walls", "The walls are made of wood and there are tiny holes in them",
        "wall", "The wall is made of wood and there are tiny holes in it",
        "wood", "You recognize, that this is a kind of wood, you don't know",
        "holes", "The holes are very tiny",
        "hole", "The hole is very tiny",
   });
   dest_dir=({
	PPATH + "meadow1","north",
        PPATH + "inner-yard", "south",
   });
}

init() {
   ::init( );
   if ( TP ) {
      if ( TP->query_guild() == 8 )
         write( "As you enter the entrance, suddenly four tiny poison darts shooting\n" +
                "out of the wall, but you duck quickly and parry the attack !!!\n" );
      else {
         write( "As you enter the entrance, suddenly four tiny poison darts shooting\n" +
                "out of the wall and hit your hard !!!\n" );
         TP->hit_player( random((TP->query_max_hp())/2) );
         TP->add_poison( TP->query_level() );
      }
   }
}
