inherit "/players/kbl/objs/gfor";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    dest_dir = ({
                 "/players/kbl/expa/exp3","east",
                 "/players/kbl/expa/for3","west",
                });
  }
}

init()
{
  ::init();
}
