inherit "room/room";
object b1,b2,b3;
int i;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Back end of a rough looking cave";
    long_desc = "The cave is covered in a thick moss. It is cold and damp\n"+
                "and has a musty smell to it.\n";
    dest_dir = ({
                 "players/kbl/expa/exp4","south",
                });
    items = ({"moss", "Thick green moss covering the whole cave here",
              "cave", "Cave is made from dark stone of a unknown type",
             });
  }
  if(!b1 && !b2 && !b3)
  {
    b1 = clone_object("players/kbl/objs/bear");
    b2 = clone_object("players/kbl/objs/bear");
    b3 = clone_object("players/kbl/objs/bear");
    transfer(b1,this_object());
    transfer(b2,this_object());
    transfer(b3,this_object());
  }
}

init()
{
  ::init();
}
