inherit "/players/kbl/objs/gfor";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    dest_dir = ({
                 "/players/kbl/expa/for10","south",
                 "/players/kbl/expa/for7","east",
                 "/players/kbl/expa/for9","west",
                });
  }
}

init()
{
  ::init();
}
