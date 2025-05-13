/* East of Ole man on High Cliff */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(2);
    short_desc = "East/west path on top of High Cliff";
    long_desc = "The pathway looks very used. The endless plane stretches\n"+
                "north and northeast of here. South you can see a chain of\n"+
                "mountains rugged and what looks to be snow capped peaks.\n"+
                "East you see a pryamid rising up from the plane. Its base\n"+
                "is out of sight east of here because the pryamid is below\n"+
                "a rise in the plane. West you can see a sea of what looks\n"+
                "like blue trees from here. Only brownish green grass can\n"+
                "seen around your immediate area.\n";
    dest_dir = ({"players/kbl/plane2","east",
                 "players/kbl/clifftop","west"});
    smell = "Air is full of the odor of sage grass";
    items = ({"pathway","Very well used pathway going east/west. Many\n"+
                        "footprints can be seen on the pathway",
              "footprints","They have a bearfoot look to them. Only four toes",
              "mountains","Rugged mountains with what looks to be snow\n"+
                          "capped peaks. The mountains stretch from east to\n"+
                          "west and look very impassible",
              "pyramid","It seems to be a little ways away. Its black\n"+
                        "appearance makes you feel a little uneasy",
              "sea","Not much detail to be seen from here",
               "snow capped peaks","Looks like snow, but you are too far away",
               "peaks","Looks like snow on them, but you are too far away",
              "blue trees","Not much detail to be seen from here",
              "grass","Its brownish green and looks very dry",
              "brownish green grass","Looks very dry but it is alive",
              "green grass","There is not green grass. There's brownish green",
              "plane","Seemingly endless plane stretching to the northern\n"+
                      "horizon. You don't feel like leaving the path for\n"+
                      "fear of getting lost out on the plane"});
    property = "no_hide","no_sneak";
  }
}

init()
{
  ::init();
}
