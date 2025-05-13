
inherit "/obj/thing";

#define CD "sys/chatd"

string m_prefix,m_postfix;

reset(arg)
 { 
   ::reset(arg);
   if (!arg)
   {
     set_name("ben");
     set_short("The real Ben");
     set_long("This is the real Ben and he is tattoed!!!\n");
     set_read("ben <text> echos <text> on jediline\n");
     m_prefix = "[*";
     m_postfix = "*]";

  }
 }

void init()
{
  ::init();
  if (environment()==this_player())
  {
    if (this_player()->query_immortal() == 1)
    {
      add_action("line_say","ben");
    }
  }
}

status line_say(string str)
{
 if (str)
 {

  return CD->do_chat(4,m_prefix+"Jedi"+m_postfix+" "+str+"\n");
  return 1;
 }
 notify_fail("ACK\n");
}



