inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(0);

  short_desc="The bottom of the ladder";
  long_desc="The ladder is resting here against the wall. This small and "+
            "damp room smells like rotting eggs. Off to the south you " +
            "hear a faint cackling and you see odd flashes of light " +
            "from that direction.\n";

  dest_dir=({"/players/emerald/good/evil/evil2","up",
             "/players/emerald/good/evil/evil6","south",
           });

  items=({"ladder","It leans against the wall",
          "room","It is quite tiny and rather wet",
          "wall","There is a ladder against the wall",
          "flashes","Bursts of light",
          "light","It attracts your attention",
        });

  smell="Definitely sulfurous.";

  ::reset();
  replace_program("/room/room");

}
