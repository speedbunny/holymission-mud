inherit "/players/kbl/objs/gfor";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_tree_down("/players/kbl/expa/for14");
    set_tree_exit("/players/kbl/expa/for14b");
    set_level(2);
    long_desc = "On a limb of a large maple tree. The limb can support\n"+
                "almost any weight.\n";
    items += ({
               "limb","Rather large and worn limb. Looks used",
              });
  }
}

