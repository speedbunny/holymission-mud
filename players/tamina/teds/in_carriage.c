object ob, dest;
int test_time, moving;
status town;
string what;

void reset(int arg)
{
  if (!arg)
  {
    set_light(1);
    town = 1;  
    moving = 0;
  }
}

set_find(obj) 
{ 
  ob = obj; 
}

string short() 
{
  return "Inside Carriage";
}

int id(string str) 
{
 return (str=="window" || str=="windows" || str=="cushion" || str=="cushions");
}

int long(string str) 
{
  write("You are inside a plush carriage. Cushions and soft pillows make\n"+
        "the seats very comfortable. The windows let in enough light to\n"+
        "see by. The Driver is waiting for you to type 'ride'.\n"+
        "       The only exit is out.\n");
  if (str == "window" || str == "windows") 
  {
    if (town) 
      write("You see the village streets through the window.\n");
    else
      write("You see a cobblestone path through the window.\n");
    return 1;
  }
  if (str == "cushion" || str == "cushions") 
  {
    write("They look quite comfortable. You lose interest in them.\n");
    return 1;
  }
  return 1;
}

void init() 
{
  add_action("_ride", "ride");
  add_action("_out", "out");
}

int _out() 
{
  if (!moving) 
  {
    if (town)
      this_player()->move_player("out of the carriage#/room/vill_road1");
    else
      this_player()->move_player("out of the carriage#/players/tamina/teds/path/path1");
    return 1;
  }
  write("The carriage is moving right now!\n");
  return 1;
}

int _ride() 
{
  if (moving) 
  {
    write("The Driver says: We are already on our way.\n");
    return 1;
  }
  write("The carriage lurches into motion.\n");
  say("The carriage lurches into motion.\n");

  test_time = 3;
  tell_room(environment(ob),"The horses pull the carriage away.....\n");
  move_object(ob, "/room/void");

  moving = 1;
  set_heart_beat(1);
  return 1;
}

heart_beat() 
{
  if (!moving) 
  {
    set_heart_beat(0);
    return 1;
  }
  if (test_time >= 0) 
  {
    tell_room("/players/tamina/teds/in_carriage", 
        "The carriage continues....\n");

    test_time -= 1;
    return 1;
  }
  if (town) 
  {
    town = 0;   moving = 0;

    tell_room("/players/tamina/teds/in_carriage", 
        "The carriage comes to a halt....\n");
    move_object(ob, "/players/tamina/teds/path/path1");
    tell_room(environment(ob),
        "A horse drawn carriage arrives.....\n");
    tell_room("/players/tamina/teds/in_carriage", 
        "You see a cobblestone path through the window.\n");
    set_heart_beat(0);
    return 1;
  }
  else
  {
    town = 1;    moving = 0;

    tell_room("/players/tamina/teds/in_carriage", 
        "The carriage comes to a halt....\n");
    move_object(ob, "/room/vill_road1");

    tell_room(environment(ob),
        "A horse drawn carriage arrives.....\n");
    tell_room("/players/tamina/teds/in_carriage", 
        "You see the familiar sights of the village streets through the window.\n");
    set_heart_beat(0);
    return 1;
  }
}
