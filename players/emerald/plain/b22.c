inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="A rocky coastline";
  long_desc="The coastline is quite jagged, with outcroppings of rock " +
            "jutting into the foaming sea below.  To the west, the high " +
            "sheer cliffs of the mountain range make you feel dwarfed and " +
            "insignificant.  The roar of the surf as it crashes against " +
            "the rocks send chills down your spine, and the spray from " +
            "the breaking waves drenches you as you clamber among the " +
            "rocks.\n";

  dest_dir=({"/players/emerald/plain/b23","north",
             "/players/emerald/plain/b21","south",
           });

  items=({"coastline","The meeting of mountains and sea",
          "outcroppings","Large rocks jutting into the sea",
          "sea","The dark blue, foamy sea",
          "rock","It is black and wet",
          "mountain","A high, silent, grey mountain",
          "range","A range of tall mountains running north and south",
          "surf","The foamy water of the sea",
          "rocks","They are black and wet",
          "spray","A fine mist of water droplets",
          "waves","They break against the jagged rocks",
        });

  ::reset();
  replace_program("/room/room");

}
