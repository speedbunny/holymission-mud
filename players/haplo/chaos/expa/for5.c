inherit "/players/kbl/objs/gfor";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    dest_dir = ({
                 "/players/kbl/expa/for6","west",
                });
  }
}

init()
{
  ::init();
}
