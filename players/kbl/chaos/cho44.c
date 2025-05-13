/* In behind the basin */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Narrow gap";
    long_desc = "You arrive at the source of the thumping. Its very LOUD\n"+
                "in here. You hold your ears! The north wall is the source\n"+
                "of the noise. Some force is continually beating on the wall\n"+
                "creating a beat of a very low octave. The bass is booming!!\n"+
                "It is VERY hot in here also. The north wall glows with a\n"+
                "reddish light and the wall flows VERY slowly east to west.\n"+
              "The odor of a acidity sulfur stench might overwelm you!\n";
    dest_dir = ({"players/kbl/chaos/cho43","east",
                 "players/kbl/chaos/cho36","west"});
    property = "no_steal","no_hide";
    smell = "Nasty rotten tomato stench!";
  }
}

pu()
{
  if(this_player()->query_con() > 11)
  {
    write("You supress a nauseous feeling.\n");
    say(this_player()->query_name()+" supresses a nauseous feeling.\n");
    return 1;
  }
  if(this_player()->query_con() < 11)
  {
    command("puke",this_player());
    return 1;
  }
  command("groan",this_player());
  return 1;
}


init()
{
  ::init();
  pu();
  add_action("look_it","scan");
  add_action("look_it","look");
}


look_it(str)
{
  if(!str)
   return;
  if(str == "at walls" || str == "walls" || str == "at wall" || str == "wall")
  {
    say(this_player()->query_name()+" looks around at walls.\n");
    write("The north wall is so hot you do not dare touch it! The south\n");
    write("is as cool as ice. The heat emissions seems to be completely\n");
    write("absorbed by the south wall. You try unsuccessfully to break\n");
    write("some crystal from the south wall. Its fused solid.\n");
    return 1;
  }
  if(str == "up")
  {
    say(this_player()->query_name()+" looks up.\n");
    write("You see where the north wall cools and meets the south wall.\n");
    write("Dust continually falls an hits the heat and creates the reddish\n");
    write("glow.\n");
    return 1;
  }
  if(str == "down")
  {
    say(this_player()->query_name()+" looks down.\n");
    write("Around your feet, dust swirls in the heat waves. Your feet are\n");
    write("covered in reddish dust.\n");
    return 1;
  }
}
