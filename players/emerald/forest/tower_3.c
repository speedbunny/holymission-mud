inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);

  short_desc="Moonchild's private room";
  long_desc="This is Moonchild's private room.  It's furninshed with a " +
            "bed, some chairs, a table and a few other things.  Actually, " +
            "it looks rather boring, to be honest.\n";

  dest_dir=({"/players/emerald/forest/tower_4", "up",
             "/players/emerald/forest/tower_2", "down",
           });
  items=({"bed","A bed. A bed. Just an ordinary bed",
          "chairs","Do you really expect to find something interesting there?",
          "things","Miscellaneous oddments",
          "room","Moonchild's room.  Do I have to say it slowly?",
          "table","A table, covered in whips, chains, and other equipment",
        });

  ::reset();
}

void init() {
  add_action("_enter", "enter");
  add_action("_sit", "sit");
  ::init();
}

int _enter(string str) {
  if(str=="bed") {
    write("You want to go into Moonchild's bed????\n");
    return 1;
  }
  return 0;
}

int _sit(string str) {
  if(id(str)) {
    write("You sit on the " + str + ".\n");
    say((string)this_player()->query_name() + " sits on the " + str + ".\n");
    return 1;
  }
  return 0;
}
