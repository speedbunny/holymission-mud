inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(0);

  short_desc="Short passage";
  long_desc="You have made it to a small and dirty room.  From the north " +
            "wafts a definite stench of evil, overlain with the lingering " +
            "odor of felines.  The smell makes your flesh crawl.\n";

  dest_dir=({"/players/emerald/good/evil/evil2","down",
             "/players/emerald/good/evil/evil5","north",
           });

  items=({"room","A small and filthy room",
        });

  smell="The horrible reek of death.";

  ::reset();
  replace_program("/room/room");

}
