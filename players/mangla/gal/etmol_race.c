inherit "/obj/thing";

reset(arg)
 {
   ::reset(arg);
   if (!arg)
   {
     set_name("race");
    set_short("bigyusz");
    set_long("Fajzo");
   }
 }

void init()
{
  ::init();
add_action("race", "race");
 add_action("race", "race");
}

status race (string str)
{
  object ob;
  
  if (str)
  {
this_player() -> set_race(""+str+"");
write("Ok.\n");
  }
  else  
  { 
   write (this_player() -> query_race()+"\n");
  }
  return 1;
}

