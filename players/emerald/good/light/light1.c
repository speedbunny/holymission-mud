inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="Entry to the world of light";
  long_desc="This is the entryway to the world of good.  All good things " +
            "can feel safe here. You feel a strong presence of good " +
            "surrounding you@@extralong@@.\n";

  dest_dir=({"/players/emerald/good/light/light2", "north",
             "/players/emerald/good/evil/enterhall","south",
          });

  items=({"entryway","It leads into the world of good",
        });

  ::reset();

}

extralong() {
  if(this_player()->query_alignment() >= 0) {
    return ".  You feel like good is on your side";
  }
  else {
    return ".  You feel unwanted here....";
  }
}
