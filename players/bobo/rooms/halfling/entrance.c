inherit "room/room";
#define TP this_player()
reset (arg) {
    clone_list=({
      1, 2, "Guard","/players/bobo/monsters/halflingg", 0,
    });
    ::reset (arg);
    set_light(1);
    short_desc="In a halfling hole.";
    long_desc=
    "This is the entrance of the hobbit warren. There is a small ladder\n"+
    "leading up to a trap door. The warren is very dirty and set up with\n"+
    "some wood beams for structure, but little else. The floor and walls\n"+
    "are dirt and there are two spots where it looks like halfling guards\n"+
    "stand day and night in the torch light.\n";
    dest_dir=({
      "/players/bobo/rooms/halfling/corridor.c","north",
      "/players/misticalla/area/rooms/forest17.c","up",
    });
    items=({
      "beams","Thick wooden beams running up the sides and accross the top of the tunnel",
      "ladder","A small wooden ladder leading up to the trap door",
      "spots","Two areas of dirt that seem more packed down than the rest of the ground",
      "trap door","A normal looking trapdoor, if there is such a thing",
      "warren","Though this is only the entrance, hopefully it won't all look like this",
    });
}

void init() {
    ::init();
    add_action("_north","north");
}

_north() {
    object guard;

    guard = present( "halfling guard", this_object() );
    if( !guard )
	return 0;
    if( this_player()->query_immortal() )
	return( 0 );
    return ( 0 );
    printf( "The halfling says: You may not enter the warren\n" );
    return 1;
}
