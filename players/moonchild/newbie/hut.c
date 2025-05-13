inherit "room/room";

#define TP this_player()

void reset(int arg) {

  set_light(1);

  short_desc="Newbie help room";

  long_desc="You have entered a small sheltered hut, standing away " +
            "from the hustle and bustle of the main street. A small " +
            "desk stands here; a note has been left on it for you " +
            "to read. In a rack at the corner of the room, there " +
            "are some small swords, while you can see some leather " +
            "jackets hanging in the corner. A staircase stand in the " +
            "corner that you can go up.\n";

  items=({ "desk", "A small desk with a note left on it",
        "note", "A note - you should probably read it",
        "rack", "There are swords sitting in the rack",
        "swords", "There are a lot of swords in the rack",
        "jackets", "There are a lot of leather jackets hanging " +
                   "in the corner",
        "leather jackets", "There are a lot of leather jackets " +
                           "hanging in the corner" });

  dest_dir=({
              "room/vill_green", "north",
              "players/moonchild/misc/hut", "south",
              "players/mangla/rooms/newbie_map_room", "up",
           });
}

init() {

  ::init();

  add_action("read", "read");
  add_action("request", "take");
  add_action("request", "get");
  if(!present("addendum", this_player())) {
    write("Cloning a soul addendum to you. Type \"help addendum\" for help.\n");
    move_object(clone_object("players/moonchild/misc/addendum"), this_player());
  }
}

int read(string str) {

  if(str!="note") {
    notify_fail("Read what ?\n");
    return 0;
  }
  write("If you need a sword or jacket, just type \"get sword\" or " +
        "\"get jacket\".\n");
  return 1;
}

int request(string str) {

  object ob;

  if(str!="sword" && str!="jacket") return 0;

  if(TP->query_level()>4) {
    write("You do not need help here. Leave it for someone who does.\n");
    return 1;
  }
  if(present(str,TP)) {
    write("You already have a " + str + ".\n");
    return 1;
  }
  ob=clone_object("players/moonchild/newbie/" + str);
  if(transfer(ob,TP)) {
    write("You are carrying too much.\n");
    destruct(ob);
    return 1;
  }
  write("You get your " + str + ".\n");
  say(TP->query_name() + " gets a " + str + ".\n");
  return 1;
}
