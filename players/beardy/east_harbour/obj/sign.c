inherit "obj/thing";

reset(arg)
{ ::reset(arg);
  { set_name("sign");
    set_short("sign");
    set_long("New port :\n"+
	     "         1. Only the old sailors can sell tickets.\n"+
	     "         2. There has to be a boat in the room to rent it.\n");

   set_can_get(0);
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
  {
    command("look at sign",this_player());
    return 1;
  }
  else
  return 0;
}
