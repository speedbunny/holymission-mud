inherit "/players/kbl/objs/gfor";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    dest_dir = ({
                 "/players/kbl/expa/for2","east",
                 "/players/kbl/expa/for6","south",
                 "/players/kbl/expa/for4","west",
                });
  }
}

init()
{
  ::init();
}
