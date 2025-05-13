#define TPN   this_player()->query_name()
#define TO this_object();
inherit "obj/soft_drink";


reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("beaker of Dark Dreamer");
    set_alias("beaker");
    set_alt_name("dreamer");
    set_short("A beaker of Dark Dreamer");
    set_long("This beaker of half mixed Dark Dreamer looks disgusting\n");
    set_value(12);
    set_strength(1);
    set_drinking_mess(TPN+" drinks the half mixed Dark Dreamer.\n");
    set_drinker_mess("You realise that Wintar hadn't finished mixing that one.\n");
    set_empty_container("beaker");
  }
}

init () {
  ::init();
  add_action ("_pour1","pour");
  add_action ("_pour1","fill");
}

int _pour1(string str) {
  object flask;

  switch(str) {
    case "dark in flask" :
    case "dark into flask" :
    case "dark dreamer into flask" :
    case "dark dreamer in flask" :
    case "liquid in flask" :
    case "liquid into flask" :
    case "dreamer in flask" :
    case "dreamer into flask" :
    case "flask with dreamer" :
    case "flask with dark" :
    case "flask with dark dreamer" :
    case "flask with liquid" :
    case "flask with beaker" :
    case "beaker into flask" :
    case "beaker in flask" :

      flask = present("flask",this_player());
      if(!flask) {
        write ("You haven't got a flask, have you?\n");
        return 1;
      }

      write("The Dark Dreamer runs smoothly into the flask.\n");
      say(TPN + " pours Dark Dreamer into the flask.\n");
      move_object(clone_object("players/redsexy/areas/cantina/wep/dark"),flask);;
      full = 0;
      food = 0;
      return 1;
    case "liquid" :
    case "dreamer" :
    case "flask" :
    case "jar" :
      notify_fail("Pour the Dark Dreamer where?\n");
      return 0;
    default :
      notify_fail("Pour what?\n");
      return 0;
  }
}

