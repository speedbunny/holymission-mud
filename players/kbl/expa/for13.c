inherit "/players/kbl/objs/gfor";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    dest_dir = ({
                 "/players/kbl/expa/for14","north",
                 "/players/kbl/expa/for12","south",
                });
  }
}

init()
{
  ::init();
}
