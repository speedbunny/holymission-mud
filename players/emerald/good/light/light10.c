inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  long_desc="You have entered a cheerfull looking forest. Birds are " +
            "singing and squirrels are running through the trees.  You " +
            "have a sense of total tranquility here.\n";

  short_desc="Cheerful forest";

  dest_dir=({"/players/emerald/good/light/light19","west",
             "/players/emerald/good/light/light3","east"
           });

  items=({"squirrels","Many small squirrels run around here",
          "trees","The trees are all oak trees, and HUGE ones at that",
          "birds","Birds of all kinds are singing happily in the trees",
          "forest","An area of tall woody vegetation",
        });

  ::reset();
  replace_program("/room/room");

}
