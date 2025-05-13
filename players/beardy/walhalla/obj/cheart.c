inherit "obj/food";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("heart");
    set_alt_name("cookie");

    set_short("cookie heart");
    set_long("Perhaps you should read before you munche it\n");

    set_value(500);
    set_weight(1);
  }
}

init()
{ add_action("drink","drink");
  add_action("read","read");
  ::init();
}

read(str)
{ if(!str) return 0;
  if(str=="cookie" || str == "heart" || str == "cookie heart" )
  { write("It says : _______       ___      _________  \n"+
          "         ( ______)     / _ \\    (____ ____)  \n" +
          "         ( )___       / /_\\ \\       ( )      \n"+
          "         (  ___)     / _____ \\      ( )      \n"+
          "         ( )_____   / /    \\ \\      ( )      \n"+
          "         (_______) (_)       (_)    (_)      \n");
    return 1;
  }
  else
  return 0;
}

drink()
{ write("");
  destruct(this_object());
  return 1;
}
