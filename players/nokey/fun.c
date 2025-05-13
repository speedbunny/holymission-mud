/* an object for a bit of fun */
#pragma strict_types

string guild, persname;

int whohas()
  {
  int a;
  object *recipient;
  recipient = users();
  for(a=0; a<sizeof(recipient); a++)
    {
    if(present(guild +"soul",recipient[a]))
      write(recipient[a]->query_real_name() +"\n");
    }
  return 1;
  }

int get()
  { return 1; }

int id(string str)
  { return str=="fun"; }

int funem(string str)
  {
  int a;
  object *recipient;
  string p1, p2;
  if(!str) return whohas();
  recipient = users();
  if (sscanf(str,"%s$N%s",p1,p2) == 2)
    {
    for(a=0; a<sizeof(recipient); a++)
      {
      if(present(guild +"soul",recipient[a]))
        tell_object(recipient[a],
        "[*"+ capitalize(guild) +"*] "+ persname +" "+
        p1 +
        capitalize((string)recipient[a]->query_real_name()) +
        p2 +
        "\n");
      }
    return 1;
    }
  for(a=0; a<sizeof(recipient); a++)
    {
    if(present(guild +"soul",recipient[a]))
      tell_object(recipient[a],
      "[*"+ capitalize(guild) +"*] "+ persname +" "+ str +
      "\n");
    }
  return 1;
  }

int fun(string str)
  {
  int a;
  object *recipient;
  string p1, p2;
  if(!str) return whohas();
  recipient = users();
  if (sscanf(str,"%s$N%s",p1,p2) == 2)
    {
    for(a=0; a<sizeof(recipient); a++)
      {
      if(present(guild +"soul",recipient[a]))
        tell_object(recipient[a],
        "[*"+ capitalize(guild) +" "+ persname +"*] "+
        p1 +
        capitalize((string)recipient[a]->query_real_name()) +
        p2 +
        "\n");
      }
    return 1;
    }
  for(a=0; a<sizeof(recipient); a++)
    {
    if(present(guild +"soul",recipient[a]))
      tell_object(recipient[a],
      "[*"+ capitalize(guild) +" "+ persname +"*] "+ str +
      "\n");
    }
  return 1;
  }

int guild(string str)
  {
  guild = str;
  return 1;
  }

int name(string str)
  {
  persname = str;
  return 1;
  }

void init()
  {
  add_action("whohas","whohas");
  add_action("fun","fun");
  add_action("funem","fun/");
  add_action("guild","soul");
  add_action("name","name");
  }

void reset(int arg)
  {
  if(arg) return;
  guild = "jedi";
  persname = "Ben";
  }
