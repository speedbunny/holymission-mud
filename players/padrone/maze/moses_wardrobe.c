
// put to room/room whisky

inherit "/room/room";

void reset(int tick)
{
      ::reset(tick);
      if (!tick)
      {
          set_light(1);
          dest_dir =
          ({
             "players/padrone/maze/moses_office", "west",
          });
	  short_desc ="Moses Schoenfinkel's wardrobe";
          long_desc =
	  "You are in a small wardrobe in Moses Schoenfinkel's office.\n";
      }
}

