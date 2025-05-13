inherit "obj/monster";
#include <lw.h>

object  w, list;
int busy;

void reset(int arg)
  {::reset(arg);
  busy=0;
  if(!arg)
    {set_level(19);
    set_gender(1);
    set_hp(1800);
    set_name("zoggo");
    set_race("dwarf");
    set_alt_name("alchemist");
    set_al(500);
    set_short("Zoggo the Alchemist");
    set_long(lw("The Alchemist is one of the wisest men in all the land!  His "+
    "powers are unmatched!  His knowledge unrivaled!  His lunacy "+
    "beyond comprehension!\n @@chk_boy@@\n"));
    set_wc(30);
    set_ac(12);
    set_size(2);
    set_aggressive(0);
    set_whimpy(-1);
    add_money(1000);
    w=clone_object("/players/kawai/ptools/cloak");
    transfer(w,this_object());
    command("wear cloak",this_object());}}


void long()
  {printf("%s%s",process_string(long_desc),tell_health());}


void init()
  {::init();
  call_out("worry",2,0);}

int cb()
  {if(!list=present("kq1-list",this_player()))
    {return 0;}
  return list->query_ore();}

void worry()
  {if(!cb())
    {write("Zoggo says: I wish I had a piece of ore to complete this experiment!\n");}
  else
    {write("Zoggo bounces around the room in joy.\n");}}

string chk_boy()
  {if(!cb())
    {return "He looks preoccupied.";}
  return "He is quite happy.";}

void catch_tell(string arg)
  {object list, who, ore;
  mixed names;
  string w, item, msg, pre, x ;
  if(busy)
    {return;}
  busy=1;
  if(sscanf(arg,"%ssays:%s",pre,msg)==2) 
    {names=explode(pre," ");           /* seperate pretitles */
    w=names[sizeof(names)-2];
    if(!who=find_player(lower_case(w)))
      {busy=0;
      return;}
    if(sscanf(msg,"%sore%s",w,item)==2)
      {if(!cb()) 
        {if(!ore=present("kq1-ore",who))
          {tell_object(who,
          lw("Zoggo tells you: I've been working on an experiment for the "+
          "King lately, but I need a piece of ore if I can finish it.  If "+
          "you would go back to the mine and get my one, I'm sure "+
          "the King would most appreciate it!\n"));
          busy=0;
          return;}
        tell_object(who,
        lw("Zoggo tells you: I see you got me my ore!  Thank you "+
        "very much!\n"+
        "Zoggo takes the ore and places it in an empty vial "
        "somewhere among a great contraption.  Moments "+
        "later, after a great deal of noise and smoke, a "+
        "cheese burger appears where the ore was.\n"+
        "Zoggo tells you: PERFECT!  And it's medium rare too!  "+
        "I'm sure the King will be most pleased!\n"));
        if(!list=present("kq1-list",who))
          {transfer(list=clone_object("players/kawai/obj/chklist"),who);}
        list->set_ore(1);
        destruct(ore);
        busy=0;
        return;}
      tell_object(who, "Zoggo exclaims: IT WORKS!  IT WORKS!!\n");
      busy=0;
      return;}
    if(sscanf(msg,"%sking%s",x,item)==2) 
      {if(!cb()) 
        {tell_object(who,
        "Zoggo says: I'll put in a good word with you if you get me some ore!\n");
        busy=0;
        return;}
      tell_object(who, lw("Zoggo says: It works!  It WORKS!!!!!  I'll let the King "+
      "know of your great service!\n"));
      busy=0;
      return;}}
  busy=0;
  return;}

void enter_inventory(object ob)
  {object who;
  who=previous_object();
  if(!ob->id("kq1-ore"))
    {tell_object(who,"Zoggo tells you: Thanks, but I don't think it will work...\n"); 
    return;}
  if(creator(ob)!="kawai")
    {tell_object(who,"Zoggo tells you: What!? This is no good!\n");
    destruct(ob);
    return;}
  if(!cb())
    {tell_object(who,
    lw("Zoggo tells you: I see you got me my ore!  Thank you "+
    "very much!\n"+
    "Zoggo takes the ore and places it in an empty vial "+
    "somewhere among a great contraption.  Moments "+
    "later, after a great deal of noise and smoke, a "+
    "cheese burger appears where the ore was.\n"+
    "Zoggo tells you: PERFECT!  And it's medium rare too!  "+
    "I'm sure the King will be most pleased!\n"));
    if(!list=present("kq1-list",this_player()))
      {transfer(list=clone_object("players/kawai/obj/chklist"),this_player());}
    list->set_ore(1);
    destruct(ob);
    return;}
  tell_object(who, "Zoggo exclaims: IT WORKS!  IT WORKS!!\n");
  return;}

