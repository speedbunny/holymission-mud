/* Top of the mountains near KBLs castle */

inherit "room/room";
object elf;

reset(arg)
{

  ::reset(arg);
  if(!arg)
  {
    set_light(2);
    short_desc = "Top of the mountains near Kbl's castle";
    long_desc = "Very windy here and cold. Not much snow here due\n"+
                "the way the wind carries here. You are barely able\n"+
                "to keep from being swept away by the continuous\n"+
                "wind. No rocks, no snow, no plants. Looking north\n"+
                "you see a large plane stretching to the horizon.\n"+
                "Below you and a fair way out onto the plane sits a\n"+
                "pyramid. Its black crystaline finish sort of sparkles\n"+
                "in the sunlight. East you see another mountain range\n"+
                "going towards the northeast. Looking west you think\n"+
                "you see a ocean! South is a valley of trees, best\n"+
                "that can be seen through the clouds. The valley to the\n"+
                "south is alot deeper than the plane to the north. That\n"+
                "means the mountains are holding back a ocean? Hmmmm\n";
    transfer(clone_object("players/kbl/objs/vultur"),this_object());
    dest_dir = ({"players/kbl/grounds/gro32","down"});
    smell = "Extremely fresh air";
    property = "no_hide","no_steal";
    items = ({"plane","A brownish green plane that stretches as far north\n"+
                      "as you can see",
              "pyramid","Black color of the pyramid is in sharp contrast\n"+
                        "to the brownish green color of the plane and the\n"+
                        "blue ocean looking area to the west",
              "ocean","Looks like a ocean, but you see brown streaks that\n"+
                      "that do not look like anything you ever seen in a\n"+
                      "ocean. To the northwest you see a red hump near the\n"+
                      "edge of the brownish green plane and the blue ocean",
              "valley","Valley is almost impossible from this distance, but\n"+
                       "you can tell many trees are there",
              "mountains","These mountains run east to west. Pathways lead\n"+
                          "both east and west across the peaks but you\n"+
                          "think the pathways are too dangerous"});
    if(!elf || !living(elf))
    {
      elf = clone_object("players/kbl/objs/elf");
      transfer(elf,this_object());
      transfer(clone_object("players/kbl/objs/short_sword"),elf);
      command("wield sword",elf);
    }
  }
}

init()
{
  ::init();
  add_action("wes","west");
  add_action("eas","east");
  add_action("nor","north");
}

eas()
{
  write("You think twice before setting foot on that narrow pathway.\n"+
        "The wind blows so hard, the very thought almost makes you fall!\n");
  say(this_player()->query_name()+" edges eastward then moves back.\n");
  return 1;
}

wes()
{
  write("West the path is narrower than the east pathway. You feel as if\n"+
        "you might fall if you went this way!\n");
  say(this_player()->query_name()+" thinks twice about going west.\n");
  return 1;
}

nor()
{
  write("You mountain is too steep here. You would need to have alot\n"+
        "of rope!\n");
  say(this_player()->query_name()+" thinks about flying northward but\n"+
      "realizes, no wings, no fly.\n");
  return 1;
}
