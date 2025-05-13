#define PPATH "/players/tatsuo/ezo/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define TO     this_object()

inherit "room/room";
reset (arg) {
   if(arg) return;
   set_light(1);
   short_desc = "In the bar";
   long_desc=
	"This is the tearoom of the residence of Matsumae Yoshihiro,\n"+
	"the evil Shogun of the island of Ezo. On the floor is a soft\n"+
	"and in the middle of the chamber is a low table. Some cushions\n"+
	"are arranged around the table.  The nihonese come in here when\n"+
	"they perform their tea ceremonies or when they want to relax.\n"+
	"A strange looking map is hanging on the wall.\n";
    items=({
	"chamber", long_desc,
        "tearoom",long_desc,
        "floor", "The floor is made of wood. A carpet is on the floor.",
        "carpet", "The carpet is light blue and seems to be very soft",
        "wood", "It is teak",
        "walls", "The walls are made of wood",
        "wall", "The wall is made of wood",
        "table", "It is a low table. It was polished lately",
        "cushions", "They look very soft and invite you to sit down",
        "cushion", "It looks very soft and invites you to sit down",
   });
   smell = "You smell the odor of tea.";
   dest_dir=({
	"/players/tatsuo/guild/room","north",
	PPATH + "atShogun","west",
	"/players/dice/obj/wedding/chapel1","east",
   });
}

init() {
   ::init( );
   add_action( "get_it", "get" );
   add_action( "get_it", "move" );
   add_action( "get_it", "take" );
   add_action( "get_it", "push" );
   add_action( "_look", "look" );
   add_action( "_look", "l");
   add_action( "_look", "exa");
}

_look(arg) {
   if(!arg) return;
   if(arg == "at map") {
       if(file_size("/players/tatsuo/ezo/map.txt") > 0 ) {
         cat("/players/tatsuo/ezo/map.txt");
      }
      return 1;
   }
   return 0;
}

sit_dow(arg) {
   if(!arg) return;
   if ( arg == "down" || arg == "down at cushion" || arg == "at cushion" ) {
      write( "You make yourself comfortable on one of the soft cushions.\n" );
      say( TPN + " sits down on one of the cushions.\n" );
   }
   return( 1 );
}

get_it(arg) {
   if(!arg) return;
   if ( arg == "cushion" || arg == "cushions" || arg == "table" ) {
      write( "It is securely fixed at the floor, so you fail with your attempt.\n" );
      return( 1 );
   }
   return( 0 );
}
