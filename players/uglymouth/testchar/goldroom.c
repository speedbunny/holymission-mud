inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Goldwolf's Cabin";
  long_desc = "This is Goldwolf's Cabin.\n"
    + "It's a small but cosy wooden hut, decorated with style.\n"
    + "Goldwolf likes to rest here when Uglymouth has worn him\n"
    + "out too much once again.\n";
  no_obvious_msg = "The Cabin has got no doors. It's a quiet place.\n";
}

void init() {
  ::init();
  if(this_player()->query_real_name() != "goldwolf") return;
  add_action("get_pin", "pin");
}

int get_pin() {
  if(this_player()->query_real_name() == "goldwolf"
      && !present("goldtool", this_player())) {
    transfer(clone_object("/players/uglymouth/testchar/goldtool"),
      this_player());
    write("A gold pin appears out of nowhere.\n");
    return 1;
  }
}

