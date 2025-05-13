inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);

  short_desc="Tower";
  long_desc="You are in the tall dark tower, a ladder leads down into a " +
            "dimly lit area below, while a shimmering, gleaming spiral " +
            "staircase leads up into the light.\n";

  dest_dir=({"/players/emerald/forest/tower_entry", "west",
             "/players/emerald/forest/tower_1", "up",
             "/players/emerald/forest/tower_b", "down",
           });
  items=({"ladder", "It's a ladder.  Duh",
          "staircase", "A beautiful spiral staircase",
          "tower","It has a rather creepy feel to it",
          "light","It lets you see what's coming at you",
        });

  ::reset();
  replace_program("/room/room");

}
