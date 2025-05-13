

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "You have entered the guard barracks of the castle. You can \n" +
        "hardly stand the smell here, and you can hear some guards\n" +
        "nearby.\n\n";
    dest_dir = 
        ({
        "/players/alian/room/upper_level/barracks1", "north",
        "/players/alian/guard_u", "down"
        });
    items = ({"barracks", "You are standing inside the barracks. They\n"+
                          "are very plain and boring",
            });
}

query_light() {
    return 1;
}
query_room_maker() {
    return 101;
}

long() {
  ::long();
  if("players/alian/room/upper_level/barracks1"->query_guard())
      write("There is a guard standing to the north.\n");
}
init() {
::init();
add_action("smell"); add_verb("smell");
add_action("listen"); add_verb("listen");
}

smell() {
  write("Ugh....it smells like there are pools of sweat here!\n");
  return 1;
}

listen() {
   write("You hear swearing and crashing..like someone \n"+
         "is wrestling.\n");
   return 1;
}

