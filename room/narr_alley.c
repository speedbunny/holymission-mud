inherit "room/room";

void reset(int arg){

    ::reset(arg);

    if (arg) return;

    set_light(1);

    short_desc = "Narrow Alley";

    long_desc = 
               "A narrow alley. There is a well in the middle. " +
               "From the east drifts a variety of wonderful " +
               "scents. To the south is the 'post office' and to " +
               "the west is the 'Brokers Assoc'.\n";

    items = ({
              "well", "You look down the well but only see darkness.\n" +
                      "There are some iron handles on the inside",
            });

    smell = "You smell lots of beautiful scents coming from the east.";

    dest_dir = ({
                 "room/vill_road1", "north",
                 "room/post", "south",
                 "players/airborne/temple/perfume", "east",
                 "room/newbroker", "west",
               });
}

init() {

    ::init();

    add_action("go_down", "down");
    add_action("south", "south");
}

int go_down() {
    this_player()->move_player("down#room/well");
    return 1;
}

int south() {
    if(this_player()->query_npc()) return 1;
}
