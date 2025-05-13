

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Ledge";
    no_castle_flag = 0;
    long_desc = 
        "As you stand at the end of the ledge you feel a bit queasy. After all,\n"
        + "it is about 1000 meters to the bottom of the chasm. The wind howls around you\n"
        + "and it feels quite cold here. A small cabin sits at the end of the path,\n"
        + "arousing your curiosity.\n";
    items = ({
         "cabin","It's shaped like a phone booth, maybe you should investigate",
         "chasm","Don't even think about jumping down..",
        });
    dest_dir = 
        ({
        "/players/silas/fghant/uppath", "south",
        });
    smell = "You sniff the cabin and decide that it's not an outhouse.\n";
}
init() {
  ::init();
  add_action("jump","jump");
  add_action("enter","enter");
}

jump(str) {
  if (str=="chasm" || "into chasm") {
     write("Are you NUTS? You will die!\n");
     say(this_player()->query_name()+" tries to jump into the chasm...what a shmuck!\n");
     return 1;
  }
}

enter(str) {
  if (str=="cabin") {
     write("You enter the cabin.\n");
     this_player()->move_player("enters#players/silas/fghant/cabin");
     return 1;
  }
  else {
   write("What do you want to enter?\n");
   return 1;
   }
}


