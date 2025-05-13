/* Black Heart of the Drow (Dark Elfs soul) */


reset(arg)
{
  if(arg)
   return;
}

short()
{
  return "Black Heart";
}

long()
{
  write("The "+short()+" jem is a large ruby with a heart of black onyx\n");
  write("naturally formed inside. You can feel a strange power within it.\n");
  write("You can see a inscription on this 'jem', maybe you should read it?\n");
}

id(str)
{
  return str == "blackheart" || str == "black heart" || str == "Blackheart";
}

init()
{
  add_action("read","read");
}

read(str)
{
  if(!str)
   return;
  if(id(str))
  {
    say(this_player()->query_name()+" reads Blackhearts inscription.\n");
    write("You who possess this, possess the very soul of the Drow\n");
    write("Elvin race. We were conceived by the Dark One from beyond\n");
    write("this mortal realm and we will seek to bring back the CHAOS\n");
    write("that is rightfullly ours! Die, mortal scum. May a scourge\n");
    write("of fire burn your flesh off.\n");
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
  return 2000;
}

query_name()
{
  return short();
}

query_alias()
{
  return "jem";
}

query_alt_name()
{
  return "jem";
}

