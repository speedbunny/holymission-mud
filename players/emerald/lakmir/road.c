inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="The road next to the bay";
  long_desc="You are on the road which runs along the shoreline.  " +
            "East lies a shallow bay with sparkling blue water.  A blooming " +
            "meadow is to the west.  The road continues to the north and " +
            "south.\n";

  smell="The air smells salty here";

  dest_dir=({"/players/emerald/lakmir/bifurcation","north",
             "/players/emerald/lakmir/shore2","east",
             "/players/emerald/lakmir/southgate","south",
             "/players/emerald/lakmir/meadow2","west"
           });

  items=({"road","A gravel road between the meadow and the bay",
          "shoreline","The meeting of water and land",
          "bay","There are probably lots of fish in it",
          "water","The sunlight is reflected off the water",
          "meadow","A riotous profusion of flowers bloom there",
        });

  ::reset();
  replace_program("/room/room");

}
