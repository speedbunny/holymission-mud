inherit "obj/weapon";
id(str) {
    return str == "excalibur";
}

init() {
    add_action("drop_object"); add_verb("drop");
    add_action("give");        add_verb("give");
    ::init();
}


reset(arg) {
    ::reset(arg);
    if (!arg) {
        set_id("excalibur");
        set_class(15);
        set_weight(4);
        set_value(0);
        set_name("Excalibur");
        set_short("The legendary [1mExcalibur[m");
        set_long("A large, magical, two-handed broadsword\n");
    }
}

drop_object(str) {
    if (str != "excalibur") return 0;
    write("You can't drop Excalibur!\n");
    say(call_other(this_player(), "query_name") + " tries to drop Excalibur.\n");
    return 1;
}

drop() { return 1; }

give(str) {
   string one, two, three, four;
   int spot;
   object ob;
   if (sscanf(str, "%s %s %s", one, two, three) == 3)
      spot = 3;
   if (one == "excalibur") {
      if (spot == 3) ob = present(three, environment(this_player()));
      if (!ob) write("There is no one here by that name.\n");
      else {
         say(call_other(this_player(), "query_name") + " tries to give away Excalibur. It disappears.\n");
         write("Excalibur disappears!\n");
         destruct(this_object());
      }
      return 1;
   }
   return 0;
}


