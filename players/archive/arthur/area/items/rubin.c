inherit "/obj/thing";

#define CD "sys/chatd"

string m_prefix,m_postfix;

reset(arg)
 {
   ::reset(arg);
   if (!arg)
   {
     set_name("rubin");
     set_short("A beautiful red rubin");
     set_long("This is a marvelous red rubin shining brightly.\n"+
              "There is something written on the top of it.\n");
     set_read("'Knowledge is Power!'\n"+
              "rubin <text> : emotes <text> on the wiz line.\n");
     m_prefix = "[";
     m_postfix = "]";

   }
 }

void init()
{
  ::init();
  if (environment()==this_player())
  {
    if (this_player()->query_immortal() == 1)
    { 
      add_action("m_say","rubin");
    }
  }
}

status m_say (string str)
{
  if (str)
  {
    return CD->do_chat(-1,m_prefix+"wiz"+m_postfix+" "+str+"\n");
    return 1;
  } 
  notify_fail("Errrr...No\n");
}

int drop (int silently)
{
  if (!silently) write ("The rubin falls into pieces...\n");
  destruct (this_object());
  return 1;  
}
