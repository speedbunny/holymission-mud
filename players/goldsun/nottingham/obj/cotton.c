inherit "/obj/treasure";

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("cotton");
 set_short("A heap of cotton");
 set_long("A heap of white cotton. It's good for sleeping or rope.\n");
 set_weight(1);
 set_value(12);
}

init()
{
 ::init();
 add_action("m_make","make");
}

int m_make(string str)
{
  if (str=="rope" || str=="rope from cotton")
  { 
   write("You make a rope from cotton.\n");
   say(this_player()->query_name()+" makes a rope.\n");
   transfer(this_object(),environment(this_player()));
   transfer(clone_object("/players/goldsun/nottingham/obj/rope"),this_player());
   destruct(this_object());
   return 1;
  }
}

