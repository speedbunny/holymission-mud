inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A side street";

  long_desc="You have entered a peaceful side street.  People are passing " +
            "through with jugs and buckets.  Those heading west have empty " +
            "containers, the ones going east have ones filled with water.  " +
            "There appears to be some sort of a shop to the north of you, " +
            "but you can't figure out what it sells from the street.\n";
            "the building to the north.\n";

  dest_dir=({"/players/emerald/town/candle","north",
             "/players/emerald/town/t11","east",
             "/players/emerald/town/well","west",
           });

  items=({"street","A pleasant street with lots of activity",
          "shop","A business of some sort",
          "people","The citizenry of the town",
          "jugs","Containers for holding water",
          "buckets","Containers for carrying water",
  });

  ::reset(arg);
   replace_program("/room/room");

}
