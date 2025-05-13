

#include "/players/waldo/clan/defines.h"
mapping clan;

void add_clan(object x, string y)
{
  if(!mappingp(clan)) clan = ([]);
  clan[y] = x;
}

void remove_clan(string x) { if(!clan) return; clan = m_delete(clan, x); }
 
int clan_sort(object x, object y) { 
  return(x->query_level() < y->query_level()); 
}
 
void clan_mesg(string y)
{
  object o;
  string *t;
  int i;

  if(!mappingp(clan)) return;
  t = m_indices(clan);

  for(i = 0; i < sizeof(t); i++)
    if((o = clan[t[i]]) && interactive(environment(o)) && o->query_chat_off())
 /*   if (environment(o)->query("term") == "ansi")
     tell_object(environment(o),ANSI_PURPLE + y + ANSI_NORMAL);
    else */
       tell_object(environment(o), y );
}
  
string *get_clan()
{
  string *t, n, blah, title, guild;
  object *o, z;
  int i, j, k, l;

  if(!mappingp(clan)) return 0;
  t = m_indices(clan);
  o = ({ });
  l = sizeof(t);

  for(i = 0; i < l; i++)
    if((z = find_player(t[i])) && interactive(z) && clan[t[i]])
    {
      if(z->query_invis() < 10 || 
      z->query_level() <= TP->query_level())
        o += ({ z });
    }
   else remove_clan(t[i]);

  o = sort_array(o, "clan_sort", this_object());
  t = ({ });
  for(i = 0; i < sizeof(o); i++)
  {
    blah = "";
    j = o[i]->query_level();
    k = o[i]->query_invis();
    n = capitalize(o[i]->query_real_name());
    guild = MEMBERS[lower_case(n)];
    if (!guild || guild == " ") guild = "Geigin";

    if (j>99)  blah += sprintf("[Wiz] ");
    else       blah += sprintf("      "); 

    blah += sprintf("%-20.20s",k?"("+n+")":n);    

    blah += sprintf("%-12.12s",CP(guild));

    blah += sprintf("%-15s Clan line: %s", " ",
                    (clan[lower_case(n)]->query_chat_off()?"on":"off"));

    t += ({ sprintf("%s",blah) });
  }
  return t;
}

