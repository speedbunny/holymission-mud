/* Hanging by a thread from High Cliffs */

short()
{
  return "Under ledge overhang";
}

long()
{
  write(short()+".\n");
  write("You hang by your hands here. Straight down below you is a water\n");
  write("pool that is the size of a large dot. Maybe you should let go?\n");
  write("Heck no because its got to be 2500 feet/800 meters to the bottom\n");
  write("of the cliffs! The view is breath taking and your grip on life\n");
  write("is thin. You feel if you fall, you die. The wind whips at you\n");
  write("with a rhythmical sound. You mind wanders.\n");
  write("Obvious exits are up and down.\n");
}

init()
{
  set_light(1);
  add_action("look_it","look");
  add_action("up","up");
  add_action("down","down");
  add_action("think","think");
  add_action("look_it","scan");
  add_action("let","let");
}

up()
{
  int val;

  val = this_player()->query_dex()-this_player()->query_intoxination()/2;
  if(val < 20)
  {
    write("You lucky to be where your at! You had better wait.\n");
    say(this_player()->query_name()+" is to drunk to climb up!\n");
    return 1;
  }
  write("You leave up by climb over ledge face to...\n");
  this_player()->move_player("climbing up#players/kbl/clifftop");
  return 1;
}

down()
{
  int val;
  val = this_player()->query_dex()-this_player()->query_intoxination()/2;
  if(val < 18)
  {
    write("You are lucky to be here at all. DO you drink everywhere?\n");
    say(this_player()->query_name()+" looks to drunk to climb down.\n");
    return 1;
  }
  write("You climb down slowly to...\n");
  this_player()->move_player("climbing down#players/kbl/cliff2");
  return 1;
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at ledge" || str == "ledge")
  {
    say(this_player()->query_name()+" looks at the ledge.\n");
    write("The ledge is very solid here and the handholds you currently\n");
    write("grip are very strong. The ledge is made from granite and is not\n");
    write("breakable.\n");
    return 1;
  }
  if(str == "left")
  {
    say(this_player()->query_name()+" looks left.\n");
    write("You can see that the tops of the giant pines, nearly grow as\n");
    write("tall as the cliff. The cliff seems to stretch all the way\n");
    write("to the left horizon, as far as you can see.\n");
    return 1;
  }
  if(str == "right")
  {
    say(this_player()->query_name()+" looks right.\n");
    write("You view right is blocked by a bowing out in the cliff face here.\n");
    return 1;
  }
  if(str == "down")
  {
    say(this_player()->query_name()+" looks down.\n");
    write("You hang directly above the pool of water. Let go!\n");
    return 1;
  }
  if(str == "up")
  {
    say(this_player()->query_name()+" looks up.\n");
    write("Just look at the ledge!\n");
    return 1;
  }
}

think(str)
{
  if(!str)
   return;
  if(str == "about cliffs")
  {
    if(this_player()->query_int() > 25)
    {
      say(this_player()->query_name()+" seems to meditate on something.\n");
      write("You see a person falling and falling and falling.........\n");
      write("then a flash of light appears below them and they vanish!\n");
      write("In your mind you hear: Let go!\n");
      return 1;
    }
    if(this_player()->query_int() > 20)
    {
      say(this_player()->query_name()+" seems to meditate for a moment.\n");
      write("You see a person falling and falling and falling.........\n");
      return 1;
    }
    say(this_player()->query_name()+" thinks about something.\n");
    write("You see the cliffs.\n");
    return 1;
  }
  if(str == "about water pool")
  {
    say(this_player()->query_name()+" thinks about something.\n");
    write("You see a pool of water fed by a flow of water from the cliff.\n");
    return 1;
  }
}

let(str)
{
  if(!str)
   return;
  if(str == "go")
  {
    if(this_player()->query_con() > 25)
    {
      write("You let go of the handhold and are falling rapidly!\n");
      write("Falling and falling and falling, the ground is comming\n");
      say(this_player()->query_name()+" lets go of the handhold and is falling!\n");
      say(this_player()->query_name()+" is falling and falling and falling.\n");
      write("up quickly, then a bright flash of light and you are somewhere\n");
      write("else.\n");
      say("A bright flash of light appears below "+this_player()->query_name()+"!\n");
     this_player()->move_player("by falling into flash of light below you#players/kbl/kblroom");
      write("Soon that will go somewhere else! :-)\n");
      return 1;
    }
    write("You think to yourself, are you crazy!!\n");
    return 1;
  }
}
