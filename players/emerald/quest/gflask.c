#define TPN   this_player()->query_name()
#define TO this_object();
inherit "obj/soft_drink";


reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("flask of green liguid");
    set_alias("green liquid");
    set_alt_name("flask");
    set_short("A flask of green liquid");
    set_long("A flask filled with thick green liquid.\n");
    set_value(12);
    set_strength(1);
    set_drinking_mess(" drinks the vile green liquid.\n");
    set_drinker_mess("Your throat burns as the liquid goes down.\n");
    set_empty_container("flask");
  }
}
init () {
  ::init();
  add_action ("pour","pour");
  add_action ("pour","fill");

}
int pour(string str) {
  object tray;

  switch(str) {
    case "liquid in tray" :
    case "green liquid in tray" :
    case "flask in tray" :
      tray = present("tray",this_player());
      if(!tray) {
        write ("You'd spill the liquid on the floor if you did that.\n");
        return 1;
      }
      write("Glug...glug...glug.\n");
      say(TPN + " pours green liquid into the tray.\n");
      full = 0;
      food = 0;
 
      move_object(clone_object("players/emerald/quest/gliquid"),tray);;

      return 1;
    case "liquid" :
    case "green liquid" :
    case "flask" :
      notify_fail("Pour the green liquid where?\n");
      return 0;
    default :
      notify_fail("Pour what?\n");
      return 0;
  }
}
