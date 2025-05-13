inherit"room/room";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Ground floor of Walhalla",
    long_desc="This is the ground floor of Walhalla. You see a strange\n" +
              "blue light shining from the ceiling. This room seems to\n"
              "be a special one. Perhaps you can do things in here you \n"
              "aren't able at another place.\n";

    items=({"light","What a nice light..."});
   property=({"teleport"});

    dest_dir =({"/players/beardy/walhalla/room/floor3","south",
                "/players/beardy/walhalla/room/floor12","west"});

    smell = "You smell a trap to the west";

  }
}
