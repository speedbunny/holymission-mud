inherit "/room/room";

  reset(arg)
  {
    ::reset(arg);
    long_desc = "THE STORE OF THE NTTINGHAM HERB-SHOP\n";
    set_light(1);
    dest_dir=({"/players/goldsun/nottingham/room/herb_shop","down"});
  }
