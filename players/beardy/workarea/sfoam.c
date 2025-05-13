inherit "obj/treasure";

int x;

reset(arg)
{ if(!arg)
  { set_name("foam");
    set_alias("sudsy");
    set_alt_name("bottle");
    set_short("A bottle of shaving foam");
    set_long("It's a bottle filled with shaving foam.\n" +
             "Type 'spray' to use it ...\n");
    set_value(1000);
    x=0;
        set_weight(1);
  }
}

init()
{ add_action("spray","spray");
  add_action("give","give");
 // add_action("drop","drop");
  ::init();
}


spray(str)
{ string monster;

  if (!str)
  { write("Where do you want to spray ?\n");
    return 1;
  }
  else
  { monster=present(str,environment(this_player()));
    if (!living(monster))
    {
        write("No such living.\n");
        return 1;
    }
    write("You spray !\n");
    monster->hold(this_player(),6);
    tell_object(monster,"Schaum.\n");
    x++;
    if(x==3)
    { write("The bottle is empty and fades away.\n");
      destruct(this_object());
    }
    return 1;
  }
  return 1;
}

give(str)
{ write("The bottle crumbles to dust.\n");
  destruct(this_object());
  return 1;
}
