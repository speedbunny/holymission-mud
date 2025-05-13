inherit "/obj/thing";

reset(arg)
 {
   ::reset(arg);
   if (!arg)
   {
     set_name("mouth");
     set_short("A magic mouth");
     set_long("This is the fascinating magic mouth.\n");
   }
 }

void init()
{
  ::init();
  add_action("m_say","mouth");
  add_action("bm_say","bmouth");
}

status m_say (string str)
{
  if (strlen(str) != 0)
  {
    say(str+"\n");
    say("[1A[30D"+str+"                  -\n");
    say("[1A[30D"+str+"                  -\n");
    say("[1A[30D"+str+"                 --\n");
    say("[1A[30D"+str+"                 --\n");
    say("[1A[30D"+str+"                ---\n");
    say("[1A[30D"+str+"                ---\n");
    say("[1A[30D"+str+"               ----\n");
    say("[1A[30D"+str+"               ----\n");
    say("[1A[30D"+str+"              -----\n");
    say("[1A[30D"+str+"              -----\n");
    say("[1A[30D"+str+"             ------\n");
    say("[1A[30D"+str+"T            ------\n");
    say("[1A[30D"+str+"Th          -------\n");
    say("[1A[30D"+str+"Tho         -------\n");
    say("[1A[30D"+str+"Thor       --------\n");
    say("[1A[30D"+str+"Thorm      --------\n");
    say("[1A[30D"+str+"Thorm a   ---------\n");
    say("[1A[30D"+str+"Thorm ar  ---------\n");
    say("[1A[30D"+str+"Thorm arr----------\n");
    say("[1A[30D"+str+"Thorm arri---------\n");
    say("[1A[30D"+str+"Thorm arriv--------\n");
    say("[1A[30D"+str+"Thorm arrive-------\n");
    say("[1A[30D"+str+"Thorm arrived------\n");
  }
  return 1;
}

status bm_say (string str)
{
  if (strlen(str) != 0)
  {
    say("[1m"+str+"[0m \n");
  }
  return 1;
}

int drop (int silently)
{
  if (!silently) write ("The magic mouth fades into the darkness...\n");
  destruct (this_object());
  return 1;  
}
      