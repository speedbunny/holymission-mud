

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "plateau";
    no_castle_flag = 0;
    long_desc =
	"This is incredible! You see a mixture of fantastic landscapes, white\n"
      + "sand beaches, hidden bays and cliffs dropping into turbulent seas.\n"
      + "You finally realize that you are on an Carribean island.\n";
    dest_dir =
	({
	"players/rasta/room/surrey", "north",
	"players/rasta/room/ridges", "east",
        });
}

query_light() {
    return 1;
}

