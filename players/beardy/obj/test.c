inherit"room/room";
closure call;
#define TP this_player()

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    call = #'call_other;
    short_desc="",
    long_desc="";

    no_obvious_msg="";
    
  }
}


void init()
{ ::init();
  add_action("myleg","leg");
}

int myleg(int arg)
{
apply(call,TP,"add_property","mage_legend",150);
  return 1;
}
