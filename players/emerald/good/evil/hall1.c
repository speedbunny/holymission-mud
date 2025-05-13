inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="Evil cat world";
  long_desc="This short hall leads north into darkness.  A strong feline "+
            "scent greets your nostrils from the north.  The feeling of "+
            "evil is strong in this place.  From beyond the darkness, an "+
            "evil presence seems to be watching you.\n";

  dest_dir=({"/players/emerald/good/evil/evil9","north",
             "/players/emerald/good/evil/enterhall","south",
           });

  smell="Definitely feline.";


  items=({"hall","The end is shrouded in darkness",
          "darkness","Thick, unknown darkness",
          "place","A stronghold of evil",
        });

  ::reset();
  replace_program("/room/room");

}
