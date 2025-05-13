inherit "room/room";

int move(string arg) {
  if(query_verb()=="east" && this_player()->query_level()>10 && !this_player()->query_immortal()) {
  write("This area is designed for those under level 10. Sorry.\n");
  return 1;
  }
  return ::move(arg);
}

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Dirt Path";
  long_desc =
"The forest ends here and you stand at another fork in the road. To the \
west the road meanders off through rolling countryside. To the east the \
path continues through the hills for a few hundred yards then disappears \
into another stand of trees. You can hear faint, high-pitched singing from \
that direction too!\n";

 dest_dir = ({
  "/players/figleaf/smurf/smurf1","east",
  "/players/figleaf/smurf/path1","south",
  "/players/emerald/country/entry", "west",
            });

 items = ({
"forest", "A dense growth of trees",
"fork", "A splitting of the path",
"road", "A road heading off to the west",
"trees", "Very old deciduous trees by the looks of it",
         });

  clone_list = ({
    1, 1, "peasant", "players/figleaf/smurf/beasties/peasant", 0
               });

  property = ({
              "no_sneak"
            });

::reset(arg);
}
