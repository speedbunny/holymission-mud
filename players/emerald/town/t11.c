inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A side street";

  long_desc="You have entered a peaceful side street.  People are passing " +
            "through with jugs and buckets.  Those heading west have empty " +
            "containers, the ones going east have ones filled with water.  " +
            "The wonderful aroma of fresh-baked bread is wafting out of " +
            "the building to the north.\n";

  dest_dir=({"/players/emerald/town/baker","north",
             "/players/emerald/town/t10","east",
             "/players/emerald/town/t12","west",
           });

  items=({"street","A pleasant street with lots of activity",
          "building","A bakery, perhaps",
          "people","The citizenry of the town",
          "jugs","Containers for holding water",
          "buckets","Containers for holding water",
  });

  ::reset(arg);
   replace_program("/room/room");

}
