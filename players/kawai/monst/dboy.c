inherit "obj/monster";
#include <lw.h>

#define db(str) tell_object(find_player("kawai"),str)

object w;
int busy;

void reset(int arg)
  {::reset(arg);
  busy=0;
  if(!arg)
    {set_level(7);
    set_hp(200);
    set_name("A lost dwarven boy");
    set_alias("dwarf");
    set_race("dwarf");
    set_alt_name("boy");
    set_al(10);
    set_gender(1); 
    set_short("Boy dwarf");
    set_long("The young dwarf looks scared and lost...\n");
    set_wc(8);
    set_ac(3);
    set_size(2);
    set_aggressive(0);
    set_whimpy(1);
    w=clone_object("obj/weapon");
    w->set_name("A stick");
    w->set_alias("stick");
    w->set_alt_name("long stick");
    w->set_class(8);
    w->set_weight(2);
    w->set_short("A long stick");
    w->set_long("Just a big, long, firm stick...\n");
    transfer(w,this_object());
    command("wield stick",this_object());}}


int id(string str)
  {return str=="dwarf"||str=="boy";}


void init()
  {::init();
  call_out("gripe",2,0);}


void gripe()
  {writelw("The boys says: Hi there!  Didn't expect to find anyone "+
  "way out here!  I've been wandering around so long I don't know "+
  "what to do!\n");}


void catch_tell(string arg)
  {object list, who;
  mixed names;
  string w, w2, w3, pre;
  if(busy)
    {return;}
  busy=1; 
  if((sscanf(arg,"%ssays:%sgo home%s",pre,w2,w3)==3))
    {names=explode(pre," ");           /* seperate pretitles */
    w=names[sizeof(names)-2];
    if(!who=find_player(lower_case(w)))
      {busy=0;
      return;}    
    list=present("kq1-list",who);
    if(!list) 
      {transfer(list=clone_object("/players/kawai/obj/chklist"),who);}
    if(list->query_boy())
      {tell_object(who,"The boy ignores you.\n"); 
      busy=0;
      return;}
    tell_object(who,
    lw("The boy tells you: Thank you for finding me!  I was lost, but now "+
    "I'll just follow your path home!\nThe dwarf disappears into the field.\n"));
    list->set_boy(1);
    destruct(this_object());
    busy=0; 
    return;}
  busy=0;}

      
