/* Parallel Plane Of Light */

inherit "room/room";
#define ELEM "/players/kbl/objs/elemental"
int num_c;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(3);
    num_c = 3;
    short_desc = "Light Elementals Palace";
    long_desc = "Bright light just about blinds you! The Light Suit\n"+
                "protects your eyes. This place is shooting displays of\n"+
                "light dancing everywhere. You look around at the fantastic\n"+
                "arrays of light and realize now why the Light Elemental is\n"+
                "sad. You see a fountain in the center of the room and a\n"+
                 "white crystal bench to the left side of the fountain.\n";
    dest_dir = ({"players/kbl/kblroom","escape"});
    items = ({"shooting displays","These light patterns dance around in\n"+
                                  "wild patterns. You can see something\n"+
                                  "in the patterns",
                 "patterns","You look closely at the patterns and see then\n"+
                            "contain reflections of something, but your not\n"+
                            "thinking about those yet",
                 "bench","You look closer at the bench and see its more\n"+
                         "like a box",
                 "reflections","These are from what looks like a door",
                 "this area","This looks to be a Palace of some sort"});
    smell = "Ionized air, super fresh ... Ahhhh!";
    property = "no_hide","no_steal","no_fight";
    transfer(clone_object(ELEM),this_object());
  }
}


init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("get_it","get");
  add_action("drink","drink");
}


look_it(str)
{
  if(!str)
   return;
  if(str == "at box" || str == "box")
  {
    say(this_player()->query_name()+" looks at box.\n");
    if(num_c > 0)
    {
      write("You see some white crystal. "+num_c+" remaining in the box.\n"); 
      write("Maybe you should get a crystal. The glow with bright internal\n"); 
      write("power. The box radiates warmth.\n");
      return 1;
    }
    write("There is no more white crystal in box.\n");
    say(this_player()->query_name()+" finds there's no more crystal in box.\n");
    return 1;
  }
  if(str == "at fountain" || str == "fountain")
  {
    say(this_player()->query_name()+" looks at energy fountain.\n");
    write("This fountain flows with a water that smells sweet and the\n");
    write("spray is refreshing!\n");
    this_player()->heal_self(5);
    return 1;
  }
  if(str == "at water" || str == "water")
  {
    say(this_player()->query_name()+" looks at the water in the fountain.\n");
    write("You look closer and see the water is very pure and it is\n");
    write("very drinkable, by the smell of it. Jummmmm.\n");
    return 1;
  }
}

drink(str)
{
  if(!str)
   return;
  if(str == "water from fountain" || str == "water in fountain")
  {
    say(this_player()->query_name()+" drinks a healthy gulp of water from fountain.\n");
    write("You drink the water of the fountain.\n");
    this_player()->heal_self(50);
    return 1;
  }
}


get_it(str)
{
  object tal;
  if(!str)
   return;
   if(str == "white crystal from box" || str == "crystal from box")
  {
    if(num_c > 0)
    {
      say(this_player()->query_name()+" gets a white crystal from box.\n");
      write("You take a white crystal from box.\n");
      tal = clone_object("players/kbl/objs/white_cr");
      tal->set_tim(random(50)+90);
      transfer(tal,this_player());
      num_c-=1;
      return 1;
    }
    say(this_player()->query_name()+" finds there's no more crystal in box.\n");
    write("There's no more white crystal in box.\n");
    return 1;
  }
}

