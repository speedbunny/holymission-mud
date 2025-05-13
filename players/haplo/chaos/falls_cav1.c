/* Behind the water falls */

inherit "/room/room";
object ducky;

reset(arg)
{
  if(arg)
   return;
  if(!ducky)
  {
    ducky = clone_object("obj/armour");
    ducky->set_name("Rubber Ducky");
    ducky->set_short("A rubber ducky");
    ducky->set_long("A divers ducky. Sun flake emblem on the chest\n");
    ducky->set_alias("ducky");
    ducky->set_value(300);
    ducky->set_weight(1);
    ducky->set_ac(1);
    ducky->set_type("armour");
    transfer(ducky,this_object());
  }
}

short()
{
  return "Cave behind One Falls";
}

long()
{

  write(short()+".\n");
  write("There's water in puddles everywhere here. The sound of the falls\n");
  write("seems to drown you senses. You can't even think.\n");
  write("Obvious exits are east and west.\n");
}


init()
{
  set_light(0);
  add_action("south","west");
  add_action("east","east");
  add_action("look_it","look");
  add_action("look_it","look");
}

south()
{
  write("You leave around the falling water to...\n");
  this_player()->move_player("west around falls#players/kbl/falls2");
  return 1;
}

east()
{
  write("You go deeper into the One Falls cave.\n");
  this_player()->move_player("east into gloom of cave#players/kbl/fall_cav2");
  return 1;
}

look_it(str)
{

  if(!str)
   return;
  if(str == "at cave" || str == "cave")
  {
    write("This cave looks very old. The walls are smooth from years of\n");
    write("water running over them. Smells very musty in here.\n");
    return 1;
  }
  if(str == "at puddles" || str == "puddles")
  {
    say(this_player()->query_name()+" scans the puddles on the cave floor.\n");
    write("Shallow puddles of water collected in irregularities on the cave\n"+ 
          "floor. The water looks black, but so does the floor.\n");
    return 1;
  }
   if(str == "at floor" || str == "floor")
  {
    say(this_player()->query_name()+" looks at the cave floor.\n");
    write("The floor is some type of rock. Very rough and irregular.\n");
    return 1;
  }
}
