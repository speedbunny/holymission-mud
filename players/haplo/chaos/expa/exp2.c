inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Deep in the Blue leaf forest";
    long_desc = "Light here filters through the trees above. The way\n"+
                "west looks very forboding. It might be wise to turn around.\n";
    dest_dir = ({
                 "/players/kbl/expa/exp1","east",
                 "/players/kbl/expa/exp3","west",
                });
    items = ({
              "trees","The branches and leaves are very thick",
              "branches","Hard to see",
              "leaves","Impossible to see clearly",
              });
     smell = "A musty smell seems to be coming from the west";
     property = "no_fire";
  }
}

init()
{
  ::init();
}
