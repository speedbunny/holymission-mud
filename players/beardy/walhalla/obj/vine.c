inherit "obj/food";


reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("vine");
    set_alt_name("bottle");

    set_short("bottle of vine");
    set_long("It's a bottle of divine vine.\n");

    set_value(300);

    set_weight(1);
  }
}

init()
{ add_action("drink","drink");
  ::init();
}

drink()
{ write("Ahhh... That was great !\n");
  destruct(this_object());
  return 1;
}
