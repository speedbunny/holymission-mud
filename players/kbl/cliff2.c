/* Inslope on cliff */
int num_c;

reset(arg)
{
  if(arg)
   return;
  num_c = 3;
}

short()
{
  return "Beautiful view of Long valley";
}

long()
{
  write(short()+".\n");
  write("The view from here is outstanding. The pocket in the cliff here\n");
  write("shields you from the wind. You can see carved handholds all the\n");
  write("up and out of sight over the ledge face. Thats the only way up\n");
  write("from the this ledge you are currently standing on. 700 feet down\n");
  write("you can see barely see water coming out from the cliff, but you\n");
  write("cannot hear a sound. The way down looks easy enough if you not\n");
  write("intoxinated. The valley before you stretches out to the horizon,\n");
  write("filled with soft blue trees, broken by patches of crimson. Your\n");
  write("view right is blocked by a wall of quartz and left you can see\n");
  write("cliff goes very far north beyond the Giant pines, which brush\n");
  write("their tallest branches against the quartz cliffs.\n");
  write("Obvious exits are up and down.\n");
}

init()
{
  set_light(1);
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("down","down");
  add_action("up","up");
  add_action("break_it","break");
}

up()
{
  int val;

  val = this_player()->query_dex()+this_player()->query_str()
        -(this_player()->query_intoxination()/2);
  if(val > 39)
  {
    write("You leave up using handholds.\n");
    this_player()->move_player("climbing up#players/kbl/cliff3");
    return 1;
  }
  write("You do not feel like climbing that!\n");
  command("shiver",this_player());
  return 1;
}

down()
{
  write("You leave climbing down to...\n");
  this_player()->move_player("climbing down#players/kbl/cliff1");
  return 1;
}

look_it(str)
{
  if(!str)
   return;
  if(str == "up")
  {
    say(this_player()->query_name()+" looks up.\n");
    write("You see the ledge above you is clearly marked with handholds.\n");
    write("The natural designs in the quartz, make you think of times\n");
    write("in some other past. Why?\n");
    return 1;
  }
  if(str == "down")
  {
    say(this_player()->query_name()+" looks down.\n");
    write("Looking down you see water coming from the cliff, at its base.\n");
    write("You also see the many soft blue tree tops in the immediate\n");
    write("foreground. You think of ancient elfs climbing this cliff.\n");
    return 1;
  }
  if(str == "at valley" || str == "valley")
  {
    say(this_player()->query_name()+" looks out over valley.\n");
    write("The valley is beautiful. Stretching to the horizon are the\n");
    write("soft blue trees. The valley widens the farther you look\n");
    write("towards the horizon. You notice a small river winding its\n");
    write("way through the valley. Near the horizon you see a smoking\n");
    write("volcano.\n");
    return 1;
  }
  if(str == "at cliff" || str == "cliff")
  {
    say(this_player()->query_name()+" looks at the cliff.\n");
    write("The cliffs look looser in this region and outcroppings of pure\n");
    write("quartz crystal nearby look loose also, maybe you can break\n");
    write("some off.\n");
    return 1;
  }
}

break_it(str)
{
  object tal;

  if(!str)
   return;
  if(str == "off quartz from cliff" || str == "quartz from cliff")
  {
   if(num_c > 0)
   {
    say(this_player()->query_name()+" breaks a white crystal off cliff.\n");
    write("You break a white crystal from cliff.\n");
    tal = clone_object("players/kbl/objs/white_cr");
    tal->set_tim(random(50)+20);
    transfer(tal,this_player());
    num_c -=1;
    return 1;
   }
   write("There are no more white crystals.\n");
   return 1;
  }
}
