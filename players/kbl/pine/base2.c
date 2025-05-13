/* East side base of giant pine */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "East base of giant pine";
    long_desc = "Brush and thick bushes with thorns block your passage\n"+
                "to the east and north east. North is dominated by the\n"+
                "extremely large trunk of this giant pine. A slim stair\n"+
                "way gently spirals up the side of the tree going out\n"+
                "of sight. No lower branches or vine can be seen at this\n"+
                "point.\n";
    dest_dir = ({"players/kbl/pine/base1","west",
                 "players/kbl/pine/lvl1s","up"});
    smell = "A acid smell catchs you nose an turns your head towards the\n"+
            "thorn bush blocking the south through east radius. The thorns\n"+ 
            "are poisoned tipped.";
    items = ({"brush","Scraggly bushes growing in intertwined patterns",
              "patterns","They look like clover patterns",
              "bushes","Thick bushes with deadly thorns",
              "thorns","Dripping with a thick pastywhite liquid from their\n"+
                       "tips",
              "trunk","The trunk of the giant pine tree. The color of the\n"+
                      "bark reminds you of purple sunsets",
              "giant pine","So huge that a village could live in its branches\n"+
                           "easily. The color of crimson needles makes you\n"+
                           "do a double take. The patterns of the needles\n"+
                           "seem to remind you of something",
              "needles","Crimson pine needles",
              "stairway","A wooden and vine stairway forming a slow sprial\n"+
                         "up the trunk of this giant pine"});
    property = "no_hide";
  }
}

init()
{
  ::init();
}
