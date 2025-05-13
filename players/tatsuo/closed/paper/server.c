
#include "/players/tatsuo/closed/paper/defines.h"
mapping paper;

void add_paper(object x, string y)
{
  if(!mappingp(paper)) paper = ([]);
  paper[y] = x;
}

void remove_paper(string x) { if(!paper) return; paper = m_delete(paper, x); }
 
int paper_sort(object x, object y) { 
  return(x->query_level() < y->query_level()); 
}
 
void paper_mesg(string y)
{
  object o;
  string *t;
  int i;

  if(!mappingp(paper)) return;
  t = m_indices(paper);

  for(i = 0; i < sizeof(t); i++)
    if((o = paper[t[i]]) && interactive(environment(o)) && o->query_chat_off())
 /*   if (environment(o)->query("term") == "ansi")
     tell_object(environment(o),ANSI_PURPLE + y + ANSI_NORMAL);
    else */
        tell_object(environment(o), y);
}
  
string *get_paper()
{
  string *t, n, blah, title, guild;
  object *o, z;
  int i, j, k, l;

  if(!mappingp(paper)) return 0;
  t = m_indices(paper);
  o = ({ });
  l = sizeof(t);

  for(i = 0; i < l; i++)
    if((z = find_player(t[i])) && interactive(z) && paper[t[i]])
    {
      if(z->query_invis() < 10 || 
      z->query_level() <= TP->query_level())
        o += ({ z });
    }
    else remove_paper(t[i]);

  o = sort_array(o, "paper_sort", this_object());
  t = ({ });
  for(i = 0; i < sizeof(o); i++)
  {
    blah = "";
    j = o[i]->query_level();
    k = o[i]->query_invis();
    n = capitalize(o[i]->query_real_name());
    guild = MEMBERS[lower_case(n)];
    if (!guild || guild == " ") guild = "Intruding Wiz";

    if (j>99)  blah += sprintf("[Wiz] ");
    else       blah += sprintf("      "); 

    blah += sprintf("%-20.20s",k?"("+n+")":n);    

    blah += sprintf("%-12.12s",CP(guild));

    blah += sprintf("%-15s Enquirer line: %s", " ",
                    (paper[lower_case(n)]->query_chat_off()?"on":"off"));

    t += ({ sprintf("%s",blah) });
  }
  return t;
}

