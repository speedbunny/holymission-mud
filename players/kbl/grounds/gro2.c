/* Path leading up to Kbls castle */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(2);
    short_desc = "Mountain pathway just below Kbl's castle";
    long_desc = "This rocky pathway leads northway to a gray castle near\n"+
                "the top of these mountains. All around are scrub bushes\n"+
                "and patchy growths of grass. The clouds hit you in the\n"+
                "face here. The air is thin but still breathable. The\n"+
                "mountains run east and west as far as you can see and\n"+
                "south the pathway leads down to the valley.\n";
    dest_dir = ({"players/kbl/grounds/gro1","north",
                 "players/kbl/grounds/gro4","south"});
    smell = "The air is cool and fresh";
    property = "no_hide";
    items = ({"pathway","Alot of small rocks and packed dirt make up this\n"+
                        "ancient pathway. Ancient because the larger rocks\n"+
                        "on the pathway are worn smooth by feet and wagon\n"+
                        "wheels",
              "castle","This gray castle stands against a snow capped\n"+
                       "mountain range. Seems very mysterious and possibly\n"+
                       "very evil, but that seems unlikely",
              "bushes","Little green leaves seem frozen in time on these\n"+
                       "bushes. Even when the winds whips around, the leaves\n"+
                       "do not move",
              "mountains","Young peaky mountains the run east to west",
              "valley","Looks very green and stretches from east to west\n"+
                       "as far as you can see. To the west can be seen a\n"+
                       "open plane where all the trees either have been\n"+
                       "cut down or just do not grow",
              "plane","No much to see from this distance",
              "rocks","Small to large, all seem to have a large amount of\n"+
                      "quartz crystal in them",
              "grass","Long thin blades of grass sway with the breezes",
              "dirt","A brown earthy dirt. Looks very rich for being so far\n"+
                     "up on a mountain"});
  }
}

init()
{
  ::init();
  add_action("block","north");
  wind();
}

wind()
{
  if(call_other("/players/kbl/grounds/gro1","query_wind_set"))
  {
    smell = call_other("/players/kbl/grounds/gro1","query_wind_smell");
  }
  else
    smell = "The air is cool and fresh";
}

block()
{
  if(this_player()->query_npc())
   return 1;
}
