inherit "/players/kbl/objs/gfor";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_tree_exit("/players/kbl/expa/for14a");
    dest_dir = ({
                 "/players/kbl/expa/for13","south",
                 "/players/kbl/expa/for15","west",
                });
  }
}

