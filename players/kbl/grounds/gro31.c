/* Bottom of 150 meter cliff near southeast corner of KBL's castle */

inherit "room/room";
object cav;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(2);
    short_desc = "Bottom of cliff near KBL's castle";
    long_desc = "Large spire of rock rises high overhead to your immediate\n"+
                "north and west a cliff that looks climbable. South you see\n"+
                "tiny path leading to the main pathway going north/south.\n"+
                "To your east is another path. You can see it goes east for\n"+
                "a small stretch then curves north up the mountian. You see\n"+
                "only a small portion of a valley off to your southeast.\n"+
                "This area is full of broken rocks, no plant life here.\n";
    dest_dir = ({"players/kbl/grounds/gro32","east",
                 "players/kbl/grounds/gro3","up"});
    smell = "Very fresh air here";
    items = ({"spire","The spire rises approximately 150 meters overhead.\n"+
                      "Its massive form casts a shadow of enormous size.\n"+
                      "At the base of the spire, where the rocks are very\n"+
                      "fragmented, you can see dead blades of grass stuck\n"+
                      "between the rocks. Most are standing up straight and\n"+
                      "move by some unfelt wind. Reason its unfelt, there's\n"+
                      "no wind here at all",
              "spire of rock","Just look at spire!",
              "broken rocks","Fragments remaining from the uprooting of the\n"+
                             "spire",
              "rock","What rock? Spire of rock or broken rocks?",
              "cliff","Looks like it was formed from the uprooting of the\n"+
                      "spire of rock",
              "grass","Dead grass probably blown in by a wind storm",
              "valley","Not much to see from here. The little you do see looks\n"+
                       "like a plane, devoid of trees",
              "base of the spire","Fragmented rocks and many shadows. Maybe\n"+
                                  "you should search here"});
  }
}

init()
{
  ::init();
  add_action("search","search");
  add_action("enter","enter");
}

search(str)
{
  int i,j;
  if(!str)
   return;
  if(str == "spire" || str == "base of spire")
  {
    say(this_player()->query_name()+" searchs base of spire.\n");
    write("You find that cool air is coming out of the ground here! Hmmm!\n"+
          "There might be a entrance to a cavern here...\n");
    j = (random(10)+6)-(this_player()->query_dex()/5);
    for(i=0;i<j;i++)
     write("You search the rocks...\n");
    if(this_player()->query_dex() > 14)
    {
      say(this_player()->query_name()+" found a cavern entrance!\n");
      write("You found a cavern entrance!\n");
      cav = this_player();
      return 1;
    }
    say(this_player()->query_name()+" doesn't find anything.\n");
    write("You don't seem to find anything.\n");
    return 1;
  }
}

enter(str)
{
  if(!str)
   return;
  if(str == "cavern")
  {
    if(this_player() == cav)
    {
      say(this_player()->query_name()+" enters cavern. Some rocks move\n"+
          "as "+this_player()->query_name()+" goes down into cavern.\n"); 
      write("You enter the cavern!\n");
      this_player()->move_player("down into cavern#players/kbl/dungeon/dun10");
      cav = 0;
      return 1;
    }
    write("What cavern??\n");
    return 1;
  }
}
