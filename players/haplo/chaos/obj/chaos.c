/* Portal book for traveling to Parallel Plane of Chaos */

int current_page;

reset(arg)
{
  if (arg)
    return;
  current_page = 0;
}

short()
{
  return "The Book of CHAOS";
}

long()
{
  write("This book has a shiny black cover and it feels very chaotic.\n");
  write("Title is: " + short() + ".\n");
}

init()
{
  add_action("open","open");
  add_action("close","close");
  add_action("read","read");
}

id(str)
{
  return str == "chaos" || str == "CHAOS";
}

open(str)
{
  if(!id(str))
   return 0;
  if (current_page > 0)
  {
    write(short() + " is already open a page " + current_page + ".\n");
    return 1;
  }
  else
  {
  current_page = 1;
  write("You open " + short() + ".\n");
  say(this_player()->query_name() + " opens " + short() + ".\n");
  return 1;
  }
}

close(str)
{
  if (!id(str))
    return 0;
  if (current_page == 0)
  {
    write(short() + " is already closed.\n");
    return 1;
  }
  else
  {
  current_page = 0;
  write("You close " + short() + ".\n");
  say(this_player()->query_name() + " closes " + short() + ".\n");
  return 1;
  }
}

read(str)
{
  if (!id(str) && str != "page")
    return 0;
  if (current_page == 0)
  {
    write(short() + " is closed.\n");
     return 1;
  }
   if (current_page == 1)
   {
  write("You feel drained.\n");
/* Kasgaroth, 6.28.95: This can't be fair
  switch(random(6)){
  case 0: this_player()->set_str(this_player()->query_str()-random(20)); break;
  case 1: this_player()->set_int(this_player()->query_int()-random(20)); break;
  case 2: this_player()->set_wis(this_player()->query_wis()-random(20)); break;
  case 3: this_player()->set_dex(this_player()->query_dex()-random(20)); break;
  case 4: this_player()->set_con(this_player()->query_dex()-random(20)); break;
  case 5: this_player()->set_chr(this_player()->query_dex()-random(20)); break;
   }
*/
 write("\n");
     write("You see a dark mist rush up and pull you into what looks like\n");
     write("the gates of hell! You travel at high velocity, you see a grid\n");
     write("coming up fast. You hit it and explode into a million pieces\n");
     write("swirling and spinning you finally merge together.\n");
     this_player()->move_player("into gates of chaos#players/kbl/chaos/cho1");
     return 1;
   }
}

get()
{
  return 1;
}

query_weight()
{
  return 1;
}

query_value()
{
  return 5000;
}

query_alias()
{
  return "CHAOS";
}
