inherit "/obj/thing";

#define CD "sys/chatd"
#define GM "guild/master"
#define GUILD environment(this_object())->query_guild()

string m_prefix,m_postfix;

reset(arg)
 {
   ::reset(arg);
   if (!arg)
   {
     set_name("diamond");
     set_short("A beautiful blue diamond");
     set_long("This is a marvelous blue diamond shining brightly.\n");
   }
 }

void init()
{
  ::init();
  add_action("m_say","diamond");
  add_action("m_set","set_diamond");
  
  m_prefix = "[*";
  m_postfix = "*]";
}

status m_set (string str)
{
  if (str)
  {
    sscanf(str,"%s %s",m_prefix,m_postfix);
    if (m_prefix=="~") m_prefix = "";
    if (m_postfix=="~") m_postfix = "";
    if (m_prefix=="`") m_prefix = " ";
    if (m_postfix=="`") m_postfix = " ";
  }
  else
  {
    m_prefix = "[*";
    m_postfix = "*]";
  }
  return 1;
}

status m_say (string str)
{
  if (str)
  {
    return CD->do_chat(GUILD,m_prefix+capitalize(GM->query_name(GUILD))+
                             m_postfix+" "+str+"\n");
  } 
  return 1;
}

int drop (int silently)
{
  if (!silently) write ("The diamond falls into pieces...\n");
  destruct (this_object());
  return 1;  
}

