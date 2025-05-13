inherit "obj/thing";

reset(arg)
{ ::reset(arg);
  { set_name("sign");
    set_short("sign");
    set_long("Take this as a waring: There is a nice happening in the north.\n");

    set_weight(100000);
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
