inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A side street";

  long_desc="You are wandering through a residential section of the town.  " +
            "The houses have fresh coats of paint and there are no gaps in " +
            "the paving cobbles in the street.  However, you are startled " +
            "by the small explosions you hear coming from one of the " +
            "houses.  Black smoke seeps out a few windows.  The people " +
            "on the street seem to be used to the noise, as they are " +
            "ignoring it entirely.\n";

  dest_dir=({"/players/emerald/town/house1","north",
             "/players/emerald/quest/lroom","south",
             "/players/emerald/town/t9","east",
             "/players/emerald/town/t7","west",
           });

  items=({"smoke","A thin stream of black smoke curling out a window",
          "windows","Smoke is emanating from them",
          "houses","The homes of the inhabitants of this street",
          "cobbles","They form the paving material of the street",
          "people","Human beings, for the most part",
  });

  ::reset(arg);
   replace_program("/room/room");

}
