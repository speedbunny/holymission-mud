/* 100 foot level */

short()
{
  return "Above the small tree level";
}

long()
{
  write(short()+".\n");
  write("You can see over most of the tree tops. But in the distance, to\n");
  write("the left you see trees 3 times taller. Great pines. Their deep\n");
  write("crimson needles are offset by the softblue of the leaves on\n");
  write("shorter trees. Looking right, the cliffs end in a impassable\n");
  write("mountain range.\n");
  write("Obvious exits are down and up\n");
}

init()
{
  set_light(1);
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("down","down");
  add_action("up","up");
}

up()
{
  write("You climb up more...\n");
  this_player()->move_player("up#players/kbl/cliff2");
  return 1;
}

down()
{
  write("You go down cliff to...\n");
  this_player()->move_player("down#players/kbl/falls1");
  return 1;
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at pine trees" || str == "pine trees")
  {
    say(this_player()->query_name()+" scans the distant pine trees.\n");
    write("The pine trees are so far distant, you cannot make out any\n");
    write("detail. They dwarf the other trees tho. So much so, that\n");
    write("the pine trees look unreal. Like they are not native.\n");
    return 1;
  }
  if(str == "at mountain range" || str == "mountain range")
  {
    say(this_player()->query_name()+" looks at mountain range.\n");
    write("The mountains are rugged and snow covered. The clouds above\n");
    write("you just scrape accross the tops.  The snow is bluewhite\n");
    write("and almost blinds you from this distance, approximately\n");
    write("20 miles.\n");
    return 1;
  }
  if(str == "at cliff" || str == "cliff")
  {
    say(this_player()->query_name()+" looks at the cliff.\n");
    write("The quartz crystal is ridged and provides excellent hand and\n");
    write("foot holds in this area. None of this quartz is breakable.\n");
    write("The glare off of the quartz makes you squint.\n");
    return 1;
  }
  if(str == "up")
  {
    say(this_player()->query_name()+" looks upward.\n");
    write("You see the cliff curves in and then farther up, it curves\n");
    write("back out. The wind flows south to north across the cliff\n");
    write("face and threatens to pull you off.\n");
    return 1;
  }
  if(str == "down")
  {
    say(this_player()->query_name()+" looks down.\n");
    write("You see water flowing out of a slit in the cliff below you.\n");
    write("The sound of the water barely makes it to your ears.\n");
    return 1;
  }
}
