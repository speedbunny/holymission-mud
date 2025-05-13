inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="The madam's bedchamber";

  long_desc="This bedroom radiates elegance.  The lacy curtains are drawn " +
            "against the sun.  A huge canopied bed lies along one wall, and " +
            "fire is flickering in the grate.  Judging from the finery " +
            "on the dresser and the magnificent gowns in the closet, this " +
            "must be where the madam entertains her guests.\n";

  dest_dir=({"/players/emerald/town/bu4","south",
           });

  items=({"bed","If only the bed could talk..",
          "curtains","Long, and crafted of beautiful lace",
          "dresser","It is quite elegantly carved",
          "gowns","They each required several weeks to make",
          "fire","It burns merrily in the grate",
          "closet","It's huge, and filled with gowns",
          "grate","An iron grate in the fireplace",
        });

  clone_list=({
    1,1,"madam","obj/monster", ({
      "set_name","madam",
      "set_race","human",
      "set_short","The madam of the house",
      "set_long","A gorgeous woman with cunning eyes.\n",
      "set_level",65,
      "set_wc",18,
      "set_ac",20,
      "set_gender",2,
      "add_money",5000,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
