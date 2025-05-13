inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);

  short_desc="Moonchild's workroom";
  long_desc="This is Moonchild's workroom.  It's a fairly barely decorated " +
            "room, with a few cupboards and things of that kind around.  " +
            "Otherwise, there's nothing much to look at.\n";

  dest_dir=({"/players/emerald/forest/tower_3", "up",
             "/players/emerald/forest/tower_1", "down",
           });

  items=({"cupboards", "They appear to have some rather fine china in them.\n"
        + "I wouldn't think about stealing from them, though",
          "workroom","The wizard dreams up strange things here",
          "room","Yes, that's what it is",
        });

  ::reset();
  replace_program("room/room");
}
