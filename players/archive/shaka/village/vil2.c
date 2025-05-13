inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The village road";
  long_desc="You're moving along the main street of the village,north \n"+
            "is the gate the entrance of the village, to the south the \n"+
            "road splits, to the east is a small bakery.\n";
  items=({"street","the main street",
          "village","the hobbit village",
          "road","the very road you're standing on",
          "Bakery","a small bakery, maybe you should take a look?"});
  dest_dir=({"players/shaka/village/vil1","north",
             "players/shaka/village/vil3","south",
             "players/shaka/village/bakery","east",});
}
