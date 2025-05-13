inherit "room/room";
object ob;
int i;

reset(arg) {

  if (!ob) {
     for (i=0;i<6;i++) {
        ob=clone_object("players/silas/monster/gguard");
        move_object(ob,this_object());
        }
     }

    if (arg) return;
    set_light(1);
    short_desc = "Grotto Ledge";
    no_castle_flag = 0;
    long_desc = 
        "You are standing on a ledge overlooking a huge grotto. Water trickles down\n"
        + "from the stalactites in the ceiling and falls into a large pool below.\n"
        + "Two structures which remind you of guard shacks are standing here and from\n"
        + "from the looks of them they still look used.\n";
    items = ({
         "shack","It looks very decrepit and uninteresting",
         "stalactites","They have formed for thousands of years",
         "pool","It looks quite deep, maybe you could jump into it",
           });
    smell = "The gnomes have obviously used this ledge as a toilet...\n";

    dest_dir = 
        ({
        "/players/silas/caves/gtunnel2", "east",
        });
}
init() {
  ::init();
  add_action("jump","jump");
}

jump(str) {
  if (str=="into pool") {
     write("You take a daring leap and jump into the pool.\n");
     this_player()->move_player("jumps into the pool#players/silas/caves/pool1");
     return 1;
     }
}


