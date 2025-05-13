inherit "room/room";
object ob;

reset(arg) {
  if (!ob || !living(ob)) {
  ob = clone_object("players/silas/monster/kguard");
  move_object(ob,this_object());
  }
    if (arg) return;

    set_light(1);
    short_desc = "Village Road";
    no_castle_flag = 0;
    long_desc = 
        "You are now inside the village of Keidall. Private homes line the street and\n"
        + "a feeling of security overcomes you as you see a member of the village guard\n"
        + "casting his watchful eyes over the village. You can see larger and obviously\n"
        + "commercial buildings ahead to the west and the road leaves Keidall to the east.\n";
    items = ({
         "homes","They are inhabited by the villagers of Keidall"
            });
    dest_dir = 
        ({
        "/players/silas/fghant/keidall1", "east",
        "/players/silas/fghant/keidall3", "west",
        });
    smell = "Smoke and cow manure give off a pungent odor.\n";
}


