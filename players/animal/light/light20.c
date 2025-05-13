inherit "room/room";
 
#define me this_player()->query_name()
 
reset(arg) {
    if (arg) return;
#if 0 
    ::reset(arg);
    set_outdoors(4);
#endif
    set_light(1);
    short_desc = "Wooded area";
    no_castle_flag = 0;
    long_desc =
        "Wooded area\n"
        + "\n"
        + "     This is a bright and open area surrounded by woods.\n"
        + "     The woods look like aspen trees and are in their full\n"
        + "     beauty. This area looks like many animals have come and\n"
        + "     gone here, as there are many tracks in this area!\n\n";
       items = ({
        "tracks","The tracks lead north into the woods",
        "trees","The trees are small, young aspen trees ",
	});
    dest_dir =
        ({
        "players/animal/light/light12", "west",
        });
}
 
query_long() {
    return long_desc;
}
query_outdoorness() {
    return 4;
}
query_light() {
    return 1;
}
 
init() {
     ::init();
     add_action("north","north");
}
 
north() {
     write("You find a path through the woods to the north.\n");
     say(me +" finds a path north and follows it.\n");
     tell_room("players/animal/light/light21",me+ " arrives.\n");
     move_object(this_player(),"players/animal/light/light21");
     call_other(this_player(),"look");
     return 1;
}
