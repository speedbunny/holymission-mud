inherit "room/room";

void reset(int arg) {
  ::reset(arg);
  
  short_desc="Clearing";

  long_desc="A small clearing. There are trees all around you.\n" +
            "However, the trees are sparse to the north.\n";

  set_light(1);

  smell="You smell the fresh air of the forest.";

  items=({
          "clearing","It is open and covered with grass",
          "trees","They look healthy and big",
        });

  dest_dir=({
             "room/forest1","east",
             "room/forest2","west",
             "room/plane1","north"
           });

  replace_program("room/room");
}
