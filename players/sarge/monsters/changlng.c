inherit "obj/monster";


#define _tp this_player()
#define _tpl _tp->query_level()

int id(string str)
  {return str=="denizen"||str=="human"||str=="the denizen";}

void reset(int arg) 
  {::reset(arg);
  if(arg!=0) return;
  set_name("The Denizen");
  set_race("human");
  set_gender(1);
  set_alias("denizen");
  set_short("The Denizen");
  set_long(
  "The Denizen is grotesque, yet lacking in any defining features.  You\n"+
  "sense what may be as close to true evil as imaginable, and your body\n"+
  "quakes as horrid pictures of your mutilated body flash through your\n"+
  "mind;  pictures of what may be to come should you be its next victim.\n");
  set_al(-100);
  set_level(1);
  set_no_ears(1);
  set_whimpy(0);
  add_money(1000);}

void init() 
  {::init();
  add_action("no_way", "north");}

varargs mixed hit_player(int dam,int kind,mixed elem) 
  {if(this_object()->query_level()<(_tpl *2))
    this_object()->set_level(_tpl * 2);
  return ::hit_player(dam,kind,elem);}

status no_way() 
  {write("The Denizen grabs hold of you and throws you back, keeping\n"+
  "you from passing through.\n");
  return 1;}
