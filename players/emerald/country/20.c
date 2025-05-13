inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A road through the farmland";

  long_desc="You have arrived at the gates of the town.  You can hear " +
            "the sounds of daily life emanating from within.  The gates " +
            "are open, and the yawning guard standing at the corner " +
            "doesn't look like he will hinder your passage inside.  There is "+
            "a small sign next to the gate.\n";

  dest_dir=({"/players/emerald/town/t1","north",
             "/players/emerald/country/19","south",
           });

  items=({"gates","Thick wooden gates to protect the inhabitants from attack",
          "sign","It appears to contain some writing, which you could read",
          "town","It contains people, houses, and shops",
          "corner","The corner formed by the gates and the wall",
        });


  clone_list=({
    1,1,"guard","obj/monster", ({
      "set_name","guard",
      "set_race","human",
      "set_level",25,
      "set_long","A yawning, bored-looking guard.\n",
      "set_ac",13,
      "set_wc",14,
      "set_gender",1,
      "add_money",500,
    }),
    -1,1,"sword","players/emerald/castle/weapons/bsword",0,
  });

  ::reset(arg);

}
void init() {
  ::init();
  add_action("_read","read");
}

status _read(string str){
  if(str =="sign") {
    write("The sign reads:  Welcome to Addegue.\n\n" +
          "Then, in smaller letters at the bottom, it reads:\n" +
          "All donations of gold readily accepted.\n" +
                             "The King.\n");
    say(this_player()->query_name() + " reads the sign.\n");
    return 1;
  }
  notify_fail("Read what?\n");
  return 0;
}
