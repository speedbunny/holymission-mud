inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="Ladder";
  long_desc="A ladder is resting up against the east wall here. You cannot " +
            "see in either direction up or down because it is too dark.  " +
            "You sense a strong force of evil up the ladder. You feel a " +
            "little afraid.  You notice on the east wall the part of a " +
            "word '.imes'.\n";

  dest_dir=({"/players/emerald/good/evil/evil4","up",
             "/players/emerald/good/evil/evil3","down",
             "/players/emerald/good/evil/evil20","west",
           });


  items=({"ladder","A ladder resting against the east wall",
          "wall","There is a ladder against the east wall",
        });

  ::reset();
  replace_program("/room/room");

}
