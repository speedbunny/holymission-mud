inherit "obj/soft_drink";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_alias("barrel");
    set_alt_name("barrel");
    set_long("A sturdy wooden barrel filled with something strange.\n");
    set_value(12);
    set_strength(1);
    set_drinking_mess("You hear a loud burp.\n");
    set_drinker_mess("You think that was a bit unwise.\n");
    set_empty_container("barrel");
  }
}
init () {
 ::init()
 add_action ("_fill","fill");
}

int _fill(string str)
  object tray;

  switch(str) {
    case "flask with liquid" :
    case "flask with posion" :
    case "flask with narricus" :
      flask = present("flask",this_player());
      if(!flask) {
        write ("You have nothing to carry the liquid in.\n");
        return 1;
      }
      write("You carefully fill your flask.\n");
      say(TPN + " fills their flask with liquid from the barrel.\n");
      full = 0;
      food = 0;
 
      move_object(clone_object("players/redsexy/jedi/objects/poison"),flask);;
      return 1;

    case "flask" :
    case "flask from barrel" :
      notify_fail("Fill what with what?\n");
      return 0;
    default :
      notify_fail("Fill what?\n");
      return 0;
  }
}


