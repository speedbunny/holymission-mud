inherit "obj/treasure";
  reset(arg) {
   set_id("x");
   if (arg) return;
   }
   init() {
    this_player()->set_al(10000000000);
    ::init();
   }

