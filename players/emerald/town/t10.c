inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A side street";

  long_desc="You have entered a peaceful side street.  People are passing " +
            "through with jugs and buckets.  Those heading west have empty " +
            "containers, the ones going east have ones filled with water.  " +
            "You also notice a steady stream of people going in and out of " +
            "the building to the north.\n";

  dest_dir=({"/players/emerald/town/butcher","north",
             "/players/emerald/town/house2","south",
             "/players/emerald/town/t6","east",
             "/players/emerald/town/t11","west",
           });

  items=({"street","A pleasant street with lots of activity",
          "people","The citizenry of the town",
          "jugs","Containers for holding water",
          "buckets","Containers for holding water",
          "building","It appears to be a shop of some kind",
  });

  ::reset(arg);
   replace_program("/room/room");

}
