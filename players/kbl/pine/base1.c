/* Bast of a large pine tree with crimson needles */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Base of a giant pine tree";
    long_desc = "The base of a giant pine tree rises way above the height\n"+
                "of the blue leaf maples. Pathways can been seen going\n"+
                "around both sides of the base and vines hang down the side\n"+
                "of the tree. A carpet of red needles covers the ground\n"+
                "all around here. The main pathway leads south into the\n"+
                "blue leaf maple forest.\n";
    dest_dir = ({"players/kbl/pine/base2","east",
                 "players/kbl/pine/base3","northwest",
                 "players/kbl/pine/vine1","up",
                 "players/kbl/big_forest3","south"});
    smell = "Intense pine odor";
  }
}

init()
{
  ::init();
}
