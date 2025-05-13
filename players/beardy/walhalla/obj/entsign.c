inherit"obj/treasure";

reset(arg)
{ if(!arg)
  { set_name("sign");
    set_id("sign");

    set_short("NEW sign");
    set_long("  Walhalla castle contains :\n" +
             "         Ground floor\n"+
             "         First floor\n"+ 
             "         Catacombs\n"+
             "         Party room\n"+
             "         Hall of Justice\n"+
             "         Treasury room\n"+
             "         Prison area and many prisons\n"+
             "\n  Under construction :\n"+
             "         Advanced catacombs\n" +
             "         Stairhouse\n");

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
  { command("look at sign",this_player());
    return 1;
  }
  return 0;
}
