/* In the bowl of the pyramid */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(2);
    short_desc = "On a rise near a ancient pyramid";
    long_desc = "You stand on the down side of a bowl surrounding a tall\n"+
                "thin pyramid made of dark crystal. Below and east are\n"+
                "wooded huts of various shapes. Most are small tho. A few\n"+
                "animals can be seen scurrying about between the huts but\n"+
                "you see no other activity except for the smoke coming from\n"+
                "the center of this small village. The path leads directly\n"+
                "towards the village east and it goes west up the rise.\n"+
                "Looking south you can see the east/west mountains but they\n"+
                "are partically blocked by the bowl your down in and the\n"+
                "pyramid to the east. Off to the northeast you can see the\n"+
                "foothills of another mountain range that stretch off to\n"+
                "the northeast horizon.\n";
    dest_dir = ({"players/kbl/pyramid1","east",
                 "players/kbl/plane2","west"});
    items = ({"bowl","Bowl formed by the pyramids possible sinking into the\n"+
                     "plane here or maybe the pyramid was dropped here",
              "pyramid","Must be 100 meters tall but only 50 meters across\n"+
                        "the base approximately. The dark crystal surface\n"+
                        "of the pyramid shines in the sunlight",
              "huts","Most are made from wood. A couple have flickers of\n"+
                     "light in them",
              "dark crystal","Shiny black surface almost like glass",
              "wooded huts","Seven or eight can be seen on this side of the\n"+
                            "pyramid. One large hut can be seen towards the\n"+
                            "west edge of the village",
              "village","Made up of wooded huts",
              "mountains","Only the most highest parts of the mountains can\n"+
                          "be seen from here. Not much to see really",
              "rise","Rise seems to be a effect of this bowl somehow. Your\n"+
                     "don't know why tho",
              "mountain range","Another chain of mountains going northeast\n"+
                               "quite a distance away",
              "smoke","Coming from the center of the village. The smoke seems\n"+
                      "to disappear into the air at about the height of the\n"+
                      "pyramid",
              "foothills","Foothills of a mountain range going northeast"});
    smell = "Burnt flesh odor lingers in the air here";
    property = "no_hide","no_sneak";
  }
}

init()
{
  ::init();
  add_action("eas_b","east");
}

eas_b()
{
  write("A voice says to you: This region under construction. To be open\n"+
        "as part of a quest. Send your ideas to Kbl on what you like\n"+
        "and dislike so far. :-)\n");
  say(this_player()->query_name()+" stops from going east.\n");
  return 1;
}
