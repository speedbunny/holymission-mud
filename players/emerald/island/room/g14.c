inherit "/room/inherit/std_pub";

void reset(int arg) {
  if(arg) return;

  set_light(1);

  short_desc="In a cavern";

  long_desc="You are inside one of the warmer caverns in the volcano.  "+
            "It's quite hot, but the place has a friendly feel to it.  "+
            "Torches are attached to the walls, and there are lots of "+
            "little footprints leading east.  There is a sign on the wall.\n";

  items=({"cavern","It's really warm in here",
          "volcano","You are inside a pub inside the volcano",
          "place","The cavern pub",
          "torches","Their flames flicker in an unseen draft",
          "walls","The walls are composed of black stone",
          "footprints","They were made by gnomes",
          "sign","You could read it",
          "walls","There is a sign on the wall",
       });

  dest_dir=({"/players/emerald/island/room/g15","east"
           });

  set_waiter("Gnosh");
  set_header("The Gnome pub");

  add_item("cider", 8, 2, "alco", 5, "An apple cider");
  add_item("brandy", 80, 10, "alco", 8, "A plum brandy");
  add_item("apple", 5, 2, "food", 2, "A red apple");
  add_item("plum", 50, 10, "food", 5, "A blue plum");

  ::reset(arg);
  replace_program("room/inherit/std_pub");

}
