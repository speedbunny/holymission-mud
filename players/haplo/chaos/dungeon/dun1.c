/* Under secret door to KBLroom */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Stone drain";
    long_desc = "The room is 6' x 6' square. The stone work reminds you\n"+
                "of a mill somewhere. But looking north you see a faint\n"+
                "glow of green coming from a natural opening lined with\n"+
                "well placed rocks. You notice chains hanging from the\n"+
                "east wall.\n";
    dest_dir = ({"players/kbl/dungeon/dun3","north",
                 "players/kbl/kblroom","up"});
    smell = "The air is tasteless";
    property = "no_steal";
    items = ({"stone work","Very well placed stones line this room",
              "stones","Irregular shaped but very well fitted together",
              "rocks","Irregular shaped but very well fitted together",
              "chains","Bolted onto the wall for some holding purpose",
              "natural opening","Is lined with rocks, seems to lead somewhere",
              "opening","Is lined with rocks, seems to lead somewhere"});
  }
}

init()
{
  ::init();
}
