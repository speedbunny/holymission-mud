inherit "obj/treasure";
 
get()
{
  write("It's nailed DEEP into the ground!\n");
  return 0;
}
 
reset(arg)
{
  string text;
  
  text = "NO CONDOS LEFT BUB!\n";
  set_id("billboard");
  set_short("A large billboard");
  set_long("There is some text written on it:\n"+text);
  set_read(text);
}

