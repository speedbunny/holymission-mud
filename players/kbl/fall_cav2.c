/* Dead end of One Falls cave, but someday, it may expand down! */

inherit "room/room";
object drag;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Back end of One falls cave";
    long_desc = "The cave is covered in a thick moss. It is cold and damp\n"+
                "as a cool wind swirls moisture all around you.\n";
    dest_dir = ({
                 "players/kbl/falls_cav1","west",
                });
    items = ({"moss", "Thick green moss covering the whole cave here",
              "cave", "Cave is made from dark stone of a unknown type",
             });
    smell = "Very damp and musty here";
    property = "no_steal";
  if(!drag)
  {
  drag = clone_object("players/kbl/objs/black_drag");
  transfer(drag,this_object());
  }
  }
}

init()
{
  ::init();
}
