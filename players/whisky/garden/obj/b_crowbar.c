inherit "obj/treasure";
  reset(arg) {
    if (arg) return;

    set_id("crowbar");
    set_alias("crowbar");
    set_short("A broken crowbar");
    set_long("A broken iron crowbar, you wonder how this could happen.\n");
    set_weight(2);
    set_value(20);
  }

  init() {
   add_action("use","use");
   add_action("use","break");
   ::init();
  }

  use(arg) {
   if (present("okbar",this_player())) return;
   write("You try to use the crowbar,\n"+
         "but the crowbar is broken and worthless.\n"+
         "It's a pity you shouldn't have dropped it.\n");
   return 1;
   }
  
