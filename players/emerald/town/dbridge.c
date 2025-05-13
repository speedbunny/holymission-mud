inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="On the drawbridge";

  long_desc="Your feet are gripping the ancient wooden planks of the " +
            "drawbridge of the castle.  Below you is a dry " +
            "moat.  Sharp steel stakes are set at intervals in the moat, " +
            "creating a most unpleasant ending for anyone unfortunate " +
            "enough to fall in.  North of you, the castle proper looms " +
            "domineeringly, giving you some doubt as to whether or not " +
            "you should procede.\n";

  dest_dir=({"/players/emerald/castle/rooms/entry","north",
             "/players/emerald/town/t21","south",
           });

  items=({"stakes","Nice, sharp, pointy spikes set in the moat",
          "planks","Sturdy wooden planks",
          "drawbridge","It can be raised to seal off the castle",
          "moat","It is dry, but quite lethal",
          "castle","The pinnacle of communal labour",
        });

  ::reset(arg);
   replace_program("/room/room");

}
