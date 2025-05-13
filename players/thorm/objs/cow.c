inherit "/obj/thing";

#define SCREEN_WIDTH 79

reset(arg)
 {
   ::reset(arg);
   if (!arg)
   {
     set_name("cow");
     set_short("A cow");
     set_long("This is the Cow of Power, the Symbol of Truth and Justice.\n");
   }
 }

void init()
{
  ::init();
  add_action("do_muh","muh");
}

status do_muh (string str)
{
  if (!str)
  {
  lsay ("says:","Muhhhhhhhhh...\n",this_player(),0);
  write("You say: Muhhhhhhhhh...\n");
  }
  else  
  { 
    write ("This version of cow can't say anything but Muhhhhhhhhh...\n");
  }
  return 1;
}

int drop (int silently)
{
  
  if (this_player()->query_real_name() != ("thorm"))
  {
    write ("The cow disappears like hell.\n");
    destruct (this_object());
    return 1;  
  }
}

