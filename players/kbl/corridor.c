/* Main entrance corridor */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "A beautiful red marble corridor";
    long_desc = "This corridor has tapestries lining both sides. A velvet\n"+
                "rug is underfoot and feels very spongy. Light is provided\n"+
                "buy long thin candles high above. The wax that has dripped\n"+
                "down has created long spires that hang down but not close\n"+
                "enough to touch. You see a large door way to the north and\n"+
                "to the south.\n";
    dest_dir = ({"players/kbl/kblroom","north",
                 "players/kbl/grounds/gro1","south"});
    smell = "A strong waxy odor lingers here";
    property = "no_hide";
    items = ({"corridor","This 50 meter long hallway has a ancient feel to\n"+
                         "it. The way the purple velvet rug contrasts with\n"+
                         "the red marble flooring under it gives one the\n"+
                         "thought that someone in the past loved vampires\n"+
                         "and ninjas. The tapestries speak of this",
              "spires","Long frozen drippings of wax from the candles",
              "drippings","Long frozen spires of wax from the candles",
              "tapestries","The east wall tapestry shows many Ninjas in\n"+
                           "battle with humans over rights to ancient\n"+
                           "weapon storage areas. The caverns seem to give\n"+
                           "a advantage to the attacking humans, until you\n"+
                           "look at the west walls tapestries and see the\n"+
                           "vampires coming to the aid of the ninjas. The\n"+
                           "battle consumes the world in flames for a\n"+
                           "long period of time. At the end of this time\n"+
                            "the elfs appeared and took over this castle.\n"+
                            "No one could figure out where the ninjas and\n"+
                            "vampires had gone. Rumors have it that they\n"+
                            "all died in the flames, but rumblings amoung\n"+
                            "the GODs have seen many vampires running\n"+
                            "loose over the world and the ninjas are said\n"+
                            "to be creating a guild!",
              "candles","Long thin candles in holders, 15 meters above",
              "holders","Round brass holders covered with white wax",
              "wax","Has dripped down to within 5 meters of the floor",
              "floor","Has a beautiful purple velvet rug, but not a trace\n"+
                      "of wax on it",
              "rug","Stretches the length of the hall way but is only half\n"+
                    "as wide and laided in the middle"});
  }
}

init()
{
  ::init();
}
