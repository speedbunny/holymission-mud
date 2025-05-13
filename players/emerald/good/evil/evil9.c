inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(0);

  short_desc="Scumfilled tunnel";
  long_desc="Viscous slime drapes the walls of the tunnel.  Brushing against "+
            "the walls leaves your arm covered in the stuff.  An "+
            "intermittent drip is heard as globs of slime fall to the "+
            "floor of the passage.  An ominous growl comes from the west.\n";

  dest_dir=({"/players/emerald/good/evil/evil11","west",
             "/players/emerald/good/evil/hall1","south",
        });

  items=({"tunnel","Small and slimy",
          "walls","They are covered in slime",
          "slime","Nasty icky stuff",
          "passage","A small slime-draped passage",
          "floor","The floor of the passage is slippery with slime",
          "globs","Small balls of slime",
          "arm","It's yours, and it's covered in gook",
  });

  ::reset();
  replace_program("/room/room");

}
