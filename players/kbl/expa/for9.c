inherit "/players/kbl/objs/gfor";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    dest_dir = ({
                 "/players/kbl/expa/for11","south",
                 "/players/kbl/expa/for8","east",
                });
  }
}

init()
{
  ::init();
}
