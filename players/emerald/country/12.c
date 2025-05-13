inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A path in the woods";

  long_desc="This is the top of the hill.  To your north you can see the " +
            "road winding down into the valley.  Far to the north you can " +
            "make out the walls of a town.  To the east you see a broad, " +
            "slow river winding down the valley, flanked by fields of " +
            "grain.  To the south is you see the shore of a body of water, " +
            "and a small stream flowing from it to the river.\n";

  dest_dir=({"/players/emerald/country/11","north",
             "/players/emerald/quest/pond","south",
           });

  items=({"road","A thin path winding through the fields",
          "valley","A fertile valley with many fields of grain",
          "river","It appears calm and peaceful",
          "walls","The walls surrounding a town",
          "stream","It runs from the pond to the river",
          "hill","A high point in the local geography",
          "fields","They are filled with standing grain",
        });

  ::reset(arg);
   replace_program("/room/room");

}
