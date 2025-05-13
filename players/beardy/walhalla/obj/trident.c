inherit"obj/weapon";

reset(arg)
{ ::reset(arg);
  if(!arg)
  {
    set_name("trident");
    set_alt_name("trident");

    
    set_short("Poseidon's trident");
    set_long("It's the famous three peaked trident of god Poseidon.\n" +
             "The several peaks look very sharp and lot's of cuts \n" +
             "are made in the stick.\n");

    set_class(17);
    set_value(13000);

    set_weight(2);
    
  }
}

init()
{ add_action("look","look");
  ::init();
}

look(str)
{ if(str == "at cuts")
  { write("Oops. Every cut for a kill and there are many ....\n");
    return 1;
  }
  else
  return 0;
}
