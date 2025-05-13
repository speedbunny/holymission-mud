inherit "/obj/thing";

#define CD "sys/chatd"

//string m_prefix,m_postfix;

reset(arg)
 {
   ::reset(arg);
   if (!arg)
   {
     set_name("ring");
     set_short("An old ring");
     set_long("This is an old ring, but it has magic power.\n");
     set_read("'Knowledge is Power!'\n"+
              "rubin <text> : emotes <text> on the wiz line.\n");
//     m_prefix = "[";
//     m_postfix = "]";

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
    return CD->do_chat(-1,/*m_prefix+"wiz"+m_postfix+" "+*/str+"\n");
    return 1;
  } 
  notify_fail("Errrr...No\n");
}

int drop (int silently)
{
  if (!silently) write ("The ring falls into pieces...\n");
  destruct (this_object());
  return 1;  
}
