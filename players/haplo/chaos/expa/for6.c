inherit "/players/kbl/objs/gfor";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    dest_dir = ({
                 "/players/kbl/expa/for3","north",
                 "/players/kbl/expa/for7","south",
                 "/players/kbl/expa/for5","east",
                });
  }
}
