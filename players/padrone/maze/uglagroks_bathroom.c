
// put to room/room whisky

inherit "/room/room";

void reset(int tick)
{
     ::reset(tick);
     if (!tick)
     {
        dest_dir =
        ({
            "players/padrone/maze/uglagroks_room", "south",
        });
	short_desc = "Uglagroks bathroom";
        long_desc = break_text(
	 "This is a bathroom. There are no windows here, "+
         "but quite a lot of mirrors.\n",60);
     }
}

