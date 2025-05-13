inherit "obj/treasure";
init() {
   ::init();
   add_action("bean","bean");
}
reset(arg){
   if(!arg) {
      set_id("koosh");
      set_alias("ball");
      set_short("Koosh Ball");
      set_long("A brightly colored Koosh that you can bean someone with.\n");
      set_weight(1);
      set_value(0);
   }
}
bean(arg) {
      if(find_player(arg)) {
      write("You bean the Koosh at " + capitalize(arg) + ".\n");
      say(this_player()->query_name() + " beans " + capitalize(arg) + " with a Koosh.\n");
      tell_object(find_player(arg), this_player()->query_name()+ " hits you in the head with a Koosh.\n");
      move_object(this_object(), find_player(arg));
      log_file("meph_obj", this_player()->query_name()+ " beaned "+ capitalize(arg)+".\n");
      return 1;
   }
}
