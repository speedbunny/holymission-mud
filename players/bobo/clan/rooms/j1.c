inherit "room/room";
#define MOVEP move_player
#define TP this_player()
reset (arg) {
    if (arg) return;
    ::reset (arg);
    set_light(1);
    short_desc="In a dense jungle.";
    long_desc=
    "You are near the dilapidated run down portion of the wall that\n"+
    "separates the jungle from the area of the island that is contrelled\n"+
    "by the dragon.  The jungle itself is so thick that you cannot see\n"+
    "the sun.  The jungle is foreboding and you know that it is your last\n"+
    "chance to turn around.\n";
    dest_dir=({
      "/players/bobo/clan/rooms/maze1/j2.c","north",
    });
    items=({
      "jungle","A dark jungle that eats up nearly all light.  You could get lost easily",
      "wall","The wall is thick with overgrowth and you could climb over it quickly",
    });
}


status move (string arg) {
string direction;
    if(!stringp(arg))
	arg = query_verb();
    if(arg!="north" && arg!="n")
	return ::move(arg);
    switch( random( 3 ) ) {
    case 0: direction = "maze1/j2"; break;
    case 1: direction = "maze2/J2"; break;
    case 2: direction = "maze3/j2"; break;
    }
    TP->MOVEP( "leaves north#players/bobo/clan/rooms/" + direction );
    return 1;
}

void init() {
   ::init();
   add_action("climb","climb");
}

climb(str) {
   if(str=="wall") {
      write("You climb over the wall.\n");
      TP->MOVEP("Climbs over the wall#players/bobo/rooms/island/yard11");
      return 1;
   }
}
