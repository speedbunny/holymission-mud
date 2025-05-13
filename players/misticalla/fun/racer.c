inherit "/obj/thing";

reset(arg)
 {
   ::reset(arg);
   if (!arg)
   {
     set_name("racer");
     set_short("A racer");
     set_long("This is the ultimate power-racer by Thorm.\n");
   }
 }

void init()
{
  ::init();
  add_action("do_race","racer");
}

status do_race (string str)
{
  object ob;
  
  if (str)
  {
  this_player() -> set_race("[1m"+str+"[0m");
  write("Your race is changed to: "+"[1m"+str+"[0m"+"\n");
  }
  else  
  { 
    write (this_player() -> query_race()+"\n");
  }
  return 1;
}

int drop (int silently)
{
    write ("The racer turns into dust in no time.\n");
    destruct (this_object());
    return 1;  
}
