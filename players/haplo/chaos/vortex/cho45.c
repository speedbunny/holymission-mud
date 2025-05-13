/* Alcove down inside the hole */


inherit "room/room";
int num_c;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Alcove down inside hole";
    long_desc = "This area has alot of dark crystals sticking out from the\n"+
                "wall. The crystal looks like frozen spires of ice. Black\n"+
                "ice.\n";
    dest_dir = ({"players/kbl/chaos/cho43","up"});
    property = "no_steal","no_hide";
    smell = "The air is fresh here";
  }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("break_it","break");
  add_action("jump","jump");
}



jump()
{
  write("You jump down into hole to...\n");
  this_player()->move_player("by jumping into hole!#players/kbl/chaos/cvoid");
  return 1;
}


break_it(str)
{
  object tal;


  if(!str)
   return;
  if(str == "crystal off wall" || str == "off crystal from wall")
  {
   if(num_c == 1)
   {
    write("You break crystal off wall.\n");
     say(this_player()->query_name()+" breaks crystal off wall.\n");
     tal = clone_object("players/kbl/objs/ridge_cr");
      tal->set_tim(random(5)+1);
      transfer(tal,this_player());
      num_c+=1;
      return 1;
   }
   else
   {
     write("No more loose crystal on ridge to break off.\n");
     say(this_player()->query_name()+" fails to find any loose crystal.\n");
     return 1;
   }
 }
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at walls" || str == "walls")
  {
    say(this_player()->query_name()+" looks at walls.\n");
    write("The three walls faces are radically different from one another.\n");
    write("The one opposite the hole is spire type crystal, the east wall\n");
    write("has crumbly rock type crystal and the west wall is fused.\n");
    write("Spire crystal on north wall looks the best here.\n");
    return 1;
  }
  if(str == "at hole" || str == "hole")
  {
    say(this_player()->query_name()+" looks at hole.\n");
    write("Not much to see but smooth fused walls and some hand holds\n");
    write("leading upward.\n");
    return 1;
  }
  if(str == "at alcove" || str == "alcove")
  {
    say(this_player()->query_name()+" looks around alcove.\n");
    write("The alcove has three wall faces and a opening to the hole.\n");
    write("Maybe you can jump down from here, to where you have no idea\n");
    write("tho.\n");
    return 1;
  }
}
