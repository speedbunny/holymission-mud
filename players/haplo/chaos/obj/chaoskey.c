/* Key to Zesronatea Stronghold */

int on;

reset(arg)
{
  if(arg)
   return;
  on = 0;
}

short()
{
  return "Stronghold Key";
}

id(str)
{
  return str == "stronghold key" || str == "Stronghold Key";
}

long()
{
  write("This key was carved from some high density dark crystal and it\n");
  write("looks very ancient. Only readable symbol is: DOC(doc)\n");
}

init()
{
  add_action("read_it","read");
}

read_it(str)
{
  if(!str)
   return;
  if(str == "stronghold key" || str == "symbols on stronghold key")
  {
    if(this_player()->query_int() >= 25)
    {
      write("Symbols read: DOC(doc) are negative material beings.\n");
      write("Only trolls can be bribed, but their loyality is to\n");
      write("the Arch Demon Of Chaos.\n");
      return 1;
    }
    write("You can't seem to make out the what the symbols say.\n");
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
  return 200;
}

query_name()
{
  return "Stronghold key";
}
