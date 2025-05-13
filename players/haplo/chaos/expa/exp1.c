inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Deep in blue leaf forest";
    long_desc = "Many large animal tracks can be seen here. Seems like\n"+
                "several animals lay under the bushes just off the path.\n"+
                "The thickness of the trees allows only travel on the path.\n";
    dest_dir = ({
                 "/players/kbl/expa/exp2","west",
                 "/players/kbl/big_forest3","south",
                });
    items = ({
              "animal tracks","Large claw tracks criss-crossing the path",
              "tracks","Large claw tracks criss-crossing the path",
              "bushes","Large and thorny",
              "path","Its under your feet",
              "trees","Many trees VERY close together",
             });
     smell = "Sweet smell of the forest greets your senses";
     property = "no_fire";
  }
}

init()
{
  ::init();
}
