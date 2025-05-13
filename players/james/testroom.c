inherit "players/james/room";

reset(arg) {
  set_light(1);
  short_desc = "James workroom";
  long_desc  = "The workroom of James the Great\n\n" +
               "As you look around, you wonder where all\n"+
               "the impressive gadgets and doo-dads are...\n";
  dest_dir = ({ "room/church", "church",
  "players/james/workroom", "work",
                "room/main_shop", "shop" });
  items = ({ "desk", "The desk is old and decayed" });
  clone_list = ({ 1, 2, "rat", "obj/monster", ({"set_name", "rat",
                                                "set_level", 3 }),
                 -1, 1, "bag", "obj/bag", 0 });
  ::reset();
  replace_program("players/james/room");
}
