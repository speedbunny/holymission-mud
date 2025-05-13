/* North of Orc valley on a pathway going up a mountain */

inherit "room/room";
object nork,mone;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Pathway going north to mountains, south into Orc valley";
    long_desc = "The trees thin out looking north and you see tall\n"+
                "mountains in the distance. They have very little snow\n"+
                "on them. South you see the forest gets more dense.\n"+
                "Bushes and shrubs are thick looking east and west.\n"+
                "The forest is alive with all kinds of creatures and\n"+
                "birds especially.\n";
    dest_dir = ({"players/kbl/grounds/gro2","north",
                 "/players/herp/orc/v0","southwest",
                });
    smell = "Many odors here, plant and animal type mostly. The air is still";
    nork = clone_object("players/kbl/objs/norker");
    mone = clone_object("obj/money");
    mone->set_money(random(200)+100);
    transfer(mone,nork);
    transfer(nork,this_object());
    items = ({"trees","Most are pine but some leaf bearers can be seen\n"+
                      "scattered between the evergreen trees. Most look\n"+
                      "healthy",
              "mountains","About 10k meters from from here. You see they\n"+
                          "are peaked and have steep slopes. A gray\n"+
                          "object catches your eye near the peak of the\n"+
                          "mountains",
              "gray object","Looks like a building, your to far away to\n"+
                            "to get any more detail",
              "forest","Has many trees",
              "bushes","Many thick leafed bushes, none of any use to you",
              "shrubs","Many scraggly shrubs. Looks as if the animals use\n"+
                       "these shrubs for relief stations",
              "birds","Many different types of birds. Chickadees, Sparrows\n"+
                      "Blue Jays and Starlings",
              "chickadees","Dark wings on a white body with a black capped\n"+
                           "head",
              "sparrows","Mostly all are brown with white ticks. Some have\n"+
                         "yellow around their eyes and on there chests",
              "blue jays","Mostly blue with some white. Larger than the\n"+
                          "chickadee or sparrow at 25 centimeters from\n"+
                          "head to tail",
              "creatures","Many different types but to fast for you to tell\n"+
                          "what they are. These creatures dart in and out\n"+
                          "of the shadows",
              "shadows","Many irregular shadows caused by the forest",
              "starlings","Black and ticked white, they make whistling\n"+
                          "and clicking noises"});
  }
}

init()
{
  ::init();
  wind();
}

wind()
{
  if("/players/kbl/grounds/gro1"->query_wind_set())
   smell = "players/kbl/grounds/gro1"->query_wind_smell();
  else
   smell = "Many odors here, plant and animal type mostly. The air is still";
}
