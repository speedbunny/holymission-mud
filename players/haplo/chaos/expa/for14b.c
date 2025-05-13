inherit "/players/kbl/objs/gfor";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_level(3);
    set_tree_down("/players/kbl/expa/for14a");
    long_desc = "Top of a large maple tree. You can see many other trees\n"+
                "all around you.\n";
    items += ({
               "maple tree","You are standing near the top of it",
               "tree","You are standing near the top of it",
               "trees","Many other maple trees of the surrounding forest",
               "forest","Filled with maple trees",
               "maples trees","They are all around you",
              });
    set_sound_dest("/players/kbl/cloud/city1");
  }
}

