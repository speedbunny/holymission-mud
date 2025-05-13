inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Lake's shore";
  long_desc="You're standing on sandy beach, north of you \n"+
            "lies the lake. A small sign points south. To \n"+
            "the west and east the lake's shore continues.\n";
  dest_dir=({"players/shaka/lake/shore1","west",
             "players/shaka/lake/shore3","east",
             "players/shaka/village/road1","south",});
  items =({"sand","normal simple sand",
           "beach","a small beach",
           "lake","a blue lake",
           "sign","This way to the hobbit land",
           "shore","the shore of the lake"});
}
