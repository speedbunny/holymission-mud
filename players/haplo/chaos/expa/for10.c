inherit "/players/kbl/objs/gfor";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_tree_exit("/players/kbl/pine/toplimb3");
    dest_dir = ({
                 "/players/kbl/expa/for8","north",
                });
  }
}
