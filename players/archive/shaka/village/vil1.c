inherit "room/room";
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The entrance to the village";
  long_desc="You're standing in the entrance to this village,\n"+
            "to the south runs the main village road. A small sign\n"+
            "points east to a small house. Far north you can see \n"+
            "the mountains.\n";
  items=({"entrance","the village entrance",
          "house","a small house",
          "mountains","the mountains far north",
         "village","the hobbit village",
         "sign","a small sign, maybe read it?",
         "road","a narrow sandy road running through the village"});
  dest_dir=({"players/shaka/village/road2","north",
             "players/shaka/village/vil2","south",
             "players/shaka/village/house","east",});
}
