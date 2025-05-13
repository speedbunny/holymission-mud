inherit "obj/thing";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("note");

    set_short("a note");
    set_long("It says :  \"Honey, I am in the pub today.\"\n");
    set_value(1);
    set_weight(1);
  }
}

void init()
{ ::init();
  add_action("myread","read");
}

int myread(string str)
{ if(!str) return 0;
  if(str=="note")
  { command("look at note",this_player());
    return 1;
  }
  return 0;
}
