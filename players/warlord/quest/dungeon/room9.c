inherit"players/warlord/NEWSTUFF/room";
reset (arg) {
  ::reset(arg);
  if (arg) return 1;
  set_light(1);
  short_desc= "A very dense forest path";
  long_desc= "The forest is very dense here. It is also a lot\n"
        +"darker here because the trees seem to block the sun from \n"
        +"showing.\n";
  items= ({
          "trees","The trees are a greenish brown color.",
    "sun","The sun is hard to see but it still looks red.",
      });
  dest_dir= ({
         "/players/warlord/quest/dungeon/room4","south",
          "/players/warlord/quest/dungeon/for1","north",
         });
}
