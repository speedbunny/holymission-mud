#define TPN   this_player()->query_name()
#define TO this_object();
inherit "obj/soft_drink";


reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("A jar of Juri Juice");
    set_alias("jar");
    set_alt_name("juice");
    set_short("A jar of juri juice");
    set_long("A jar filled with juri juice that is fermenting.\n");
    set_value(12);
    set_strength(1);
    set_drinking_mess(TPN+" drinks the unfermented juri juice.\n");
    set_drinker_mess("The juri juice tastes weak!\n");
    set_empty_container("jar");
  }
}
init () {
  ::init();
  add_action ("_pour2","pour");
  add_action ("_pour2","fill");
}
int _pour2(string str) {
  object flask;

  switch(str) {
    case "flask with juri" :
    case "juri in flask" :
    case "juri into flask" :
    case "juri juice into flask" :
    case "juri juice in flask" :
    case "liquid in flask" :
    case "liquid into flask" :
    case "juice in flask" :
    case "juice into flask" :
    case "flask with juice" :
    case "flask with juri juice" :
    case "flask with jar" :
    case "jar into flask" :
    case "jar in flask" :
    case "flask with liquid" :

      flask = present("flask",this_player());
      if(!flask) {
        write ("You haven't got a flask, have you?\n");
        return 1;
      }
      write("The juri juice pours smoothly into the flask.\n");
      say(TPN + " pours juri juice into the flask.\n");
      full = 0;
      food = 0;
 
      move_object(clone_object("/players/redsexy/jedi/objects/juri"),flask);;

      return 1;
    case "liquid" :
    case "juice" :
    case "flask" :
      notify_fail("Pour the juice where?\n");
      return 0;
    default :
      notify_fail("Pour what?\n");
      return 0;
  }
}
