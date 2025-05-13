inherit "obj/weapon";
#include <lw.h>

static int tin;

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {tin=0;
    set_alt_name("kq1-sword");
    set_alias("sword");
    set_name("gleaming sword");
    set_weight(5);
    set_value(8000);
    set_class(17);
    set_short("A spectacular gleaming sword");
    set_long(lw("The sword you hold is undoubtedly a very special item.  It's "+
    "blade is unscratched and gleams with perfection.  Inscribed "+
    "on the blade are various runes, which, if you can recall, signify "+
    "the power of the gods.\n"));}}

int query_quest_obj()
  {return 1;}

int query_quest_item()
  {return 1;}


int drop()
  {if(!tin)
    {tin=1;
    write("As you let go of the sword, it fades into nothing more than a flimsy tin sword.\n");
    set_name("sword");
    set_short("A cheap tin sword");
    set_long("The sword is probably the worst you've ever seen.\n");
    set_alt_name("sword");
    set_value(5);
    set_class(2);}
    if(::drop())
      return 1;
    return 0;}


