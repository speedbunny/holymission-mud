inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="Underground river";
  long_desc="A small underground river is flowing from underneath a " +
            "cavern wall here. The river is dark and forboding. It looks " +
            "like more than one person has drowned here, as there are " +
            "bones lying around on the banks.\n";
  
  dest_dir=({"/players/emerald/good/evil/evil6","west",
           });

  items=({"river","The river is dark and it does not look too friendly",
          "bones","The bones of many adventurers lay on the banks here",
          "cavern","A cave",
          "wall","It contains an opening through which the river flows",
        });

  ::reset();
  replace_program("/room/room");

}
