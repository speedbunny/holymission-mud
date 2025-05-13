inherit "room/room";
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Workroom of Shaka";
  long_desc="This is the workroom of Shaka, the allmighty warrior\n"+
            "Upholder and ruler of his realms behind the mountains\n"+
            "It seems Shaka doesn't have the time to clean up his workroom\n"+
            "it's full of mess and his desk is very dusty.\n";
  dest_dir=({"players/shaka/castle","area",
             "room/church","church",
             "room/adv_guild","guild",
             "players/shaka/testroom","testroom",});
  items = ({"workroom","it's real messy",
            "floor","ghee! doesn't shaka do any housework?",
            "desk","it's full of dust, could use some glassex"});
}

