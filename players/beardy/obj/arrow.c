inherit "obj/treasure";


reset(int arg)
{ ::reset(arg);
  if(arg) return 0;

  set_name("arrow");

  set_short("arrow");
  set_long("This is a normal arrow.\n");

  set_value(4);
  set_weight(1);
}

int get()
{ object bag;

  bag=present("arrowbag",this_player());

  if(bag)
  {
    bag->add_arrows(1);
    call_out("des_arrow",1);
  }
  return 1;
}

int des_arrow()
{ destruct(this_object());
  return 1;
}
