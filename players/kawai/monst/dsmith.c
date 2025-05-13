inherit "obj/monster";
#include <lw.h>

object a, w;
int busy;

int id(string str) 
  {return str=="smith"||str=="dwarf";}

void reset(int arg)
  {::reset(arg);
  busy=0;
  if(!arg)
    {set_level(19);
    set_hp(1800);
    set_name("smith");
    set_race("dwarf");
    set_alias("smith");
    set_alt_name("dwarf");
    set_gender(1); 
    set_al(500); 
    set_short("An old smith");
    set_long(lw("The smith, although old, is strong and stocky, and is a "+
    "master of his profession.  As you sit and watch, he "+
    "skillfully hammers away at metal and shapes it in to "+
    "fine items.  If you were nice enough, you could probably "+
    "get him to fix something up for you too.\n"));
    set_wc(30);
    set_ac(11);
    set_size(2);
    set_aggressive(0);
    set_whimpy(-1);
    w=clone_object("obj/weapon");
    w->set_name("hammer");
    w->set_alt_name("smith's hammer");
    w->set_class(18);
    w->set_weight(6);
    w->set_value(1800);
    w->set_short("A smith's hammer");
    w->set_long("It's a heavy hammer used to fashion metal objects.\n");
    transfer(w,this_object());
    command("wield hammer",this_object());}}

void init()
  {::init();
  call_out("gripe",2,0);}

void gripe()
  {writelw("The smith says: Welcome to my shop!  If there is "+
  "anything i can do for you, perhaps sharpen a weapon or "+
  "something, just let me know!\n");}

void catch_tell(string arg)
  {object list, who, what, item_o;
  mixed names;
  string w, fill, item, pre;
  if(busy)
    {return;}
  busy=1;
  if((sscanf(arg,"%ssays:%ssharpen %s\n",pre,fill,item)==3))
    {names=explode(pre," ");           /* seperate pretitles */
    w=names[sizeof(names)-2];    
    if(!who=find_player(lower_case(w)))
      {busy=0;
      return;}
    if(! (item=="axe" || item=="pickaxe"))
      {if(!(what=present(item,who)))
        {tell_object(who,
        "The smith tells you: Sorry, chap, but you don't have one of those.\n");
        busy=0;
        return;}
      tell_object(who,"The smith tells you: Hmm....it looks fine to me.\n");
      busy=0;
      return;}
    item_o=present("kq1-axe",who);
    if(!item_o)
      {tell_object(who,
      "The smith tells you: Sorry, chap, but you don't have one of those.\n");
      busy=0;
      return;}
    if(item_o->query_sharp())
      {tell_object(who,"The smith tells you: What!  It's sharp as a razor!\n"); 
      busy=0;
      return;}
    tell_object(who,lw("The smith looks over the pickaxe then sits down at his anvil.  "+
    "After carefully pounding away for several minutes, he dips "+
    "it in a bucket of water and lets it cool.  He hands you the "+
    "axe and says:  There you go!  Perfect!  In fact, may be my "+
    "best work yet!\n"));
    item_o->set_sharp();
    busy=0;
    return;}
  busy=0;}

      
