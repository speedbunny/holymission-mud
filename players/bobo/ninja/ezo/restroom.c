#define PPATH "/players/tatsuo/ezo/"
#define TP  this_player()
#define TPN TP->query_name()

inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "In the restroom";
   long_desc=
	"This is the restroom of the residence of Matsumae Yoshihiro, the\n"+
	"evil Shogun of the island of Ezo. On the floor is a soft carpet and\n"+
	"a mat. The nihonese came in here, when they want to rest or want\n"+
	"to meet the beautiful geisha of Yoshihiro-san. But Matsumae\n"+
	"mad at her at the moment, so he has sent her to the southern\n"+
	"region of Ezo.\n";
   items=({
	"chamber", long_desc,
        "restroom",long_desc,
        "floor", "The floor is made of wood. A carpet is on the floor.",
        "carpet", "The carpet is white with green ornaments",
        "ornaments", "The ornaments show beautiful geishas",
        "ornament", "The ornament shows a very pretty geisha",
        "wood", "It is teak",
        "walls", "The walls are made of wood",
        "wall", "The wall is made of wood",
        "mat", "The mat is made of bambus-leaves. It looks comfortable",
   });
   smell = "You smell the odor of massage-oil.";
   dest_dir=({
	PPATH + "store","north",
	PPATH + "atShogun","east",
   });
}

init() {
   ::init( );
   add_action( "get_it", "get" );
   add_action( "get_it", "move" );
   add_action( "get_it", "take" );
   add_action( "get_it", "push" );
   add_action( "lay_down", "lay" );
}

do_rest(arg) {
   return( lay_down( "down" ) );
}

lay_down(arg) {
   if(!arg) return;
   if ( arg == "down" || arg == "down on mat" || arg == "on mat" ) {
      write( "You make yourself comfortable at one of the bambus-mat.\n" );
      say( TPN + " lays down on the bambus-mat.\n" );
   }
   return( 1 );
}

get_it(arg) {
   if(!arg) return;
   if ( arg == "mat" ) {
      write( "As you try to get the mat, you think that you could hurt the feelings\n" +
             "of the geisha and so you stop your attempt.\n" );
      return 1;
   }
}
