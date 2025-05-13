inherit "obj/monster";
#include <lw.h>
int busy;

void reset(int arg)
  {::reset(arg);
  busy=0;
  if(!arg)
    {set_level(19);
    set_hp(1800);
    set_name("dwarven farmer");
    set_race("dwarf");
    set_alias("farmer");
    set_alt_name("dwarf");
    set_gender(1);
    set_al(500);
    set_short("An old farmer");
    set_long(lw("The farmer is a well built and stocky man, probably the main "+
    "consumer of his products.  @@chk_boy@@\n"));
    set_wc(30);
    set_ac(12);
    set_size(2);
    set_aggressive(0);
    set_whimpy(-1);
    add_money(500);}}

void init()
  {::init();
  call_out("worry",2,0);}

int cb()
  {object list;
  if(!list=present("kq1-list",this_player()))
    {return 0;}
  return list->query_boy();}

void worry() 
  {if(!cb())
    {write("Farmer panics and screams: My boy!  My boy!\n");}
  else
    {write("The farmer bounces around the room in joy.\n");}}

string chk_boy()
  {if(!cb())
    {return "He looks worried.";}
  return "He is quite happy.";}

void long()
  {printf("%s%s",process_string(long_desc),tell_health());}

void catch_tell(string str)
  {object list,who,what;
  mixed names;
  string w, item, x, pre;
  if(busy)
    {return;}
  busy=1;
  if(sscanf(str,"%ssays:%s",pre,x)==2)
    {names=explode(pre," ");           /* seperate pretitles */
    w=names[sizeof(names)-2];
    if(!who=find_player(lower_case(w)))
      {busy=0;
      return;}  
    if(sscanf(x,"%sboy%s",w,item)==2) 
      {if(!cb()) 
        {tell_object(who,
        lw("Farmer says: My boy has been lost in the field!  I'll do anything if "+
        "you could find him and tell him to come home.\n"));
        busy=0;
        return;}
      tell_object(who, "Farmer says: Thank god he's safe now!\n");
      busy=0;   
      return;}
    if(sscanf(x,"%sking%s",w,item)==2)
      {if(!cb())
        {tell_object(who,
        "Farmer says: I'll put in a good word with you if you find my boy!\n");
        busy=0;
        return;}
      tell_object(who,lw("Farmer says: Thank god he's safe now!  I'll let the King "+
      "know of your great service!\n"));
      busy=0;
      return;}}
  busy=0;
  return;}

