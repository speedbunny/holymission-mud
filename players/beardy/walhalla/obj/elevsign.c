inherit"obj/treasure";

reset(arg)
{ if(!arg)
  { set_name("sign");
    set_id("sign");

    set_short("sign");
    set_long("  Walhalla's elevator :\n"+
             "  Advices :\n"+
             "        Get some useless stuff with you\n"+
             "        and 'put' it 'into' the 'box'.\n");
  }
}

get() {return 0;}

void init()
{ ::init();
  add_action("myread","read");
}

int myread(string str)
{ if(!str) return 0;
  if(str=="sign")
  { command("look at sign",this_player());
    return 1;
  }
  return 0;
}
