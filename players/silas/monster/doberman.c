inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("doberman");
  set_alias("dog");
  set_short("doberman");
  set_long("A huge doberman who intends to keep any adventurers from passing through the\nportal. Given its size and sharp teeth you think that he has been successful\nwith this task so far.\n");
  set_level(8);
  set_al(-100);
  set_hp(200);
  set_ep(15000);
  set_wc(10);
  set_ac(2);
  set_aggressive(1);
  return 1;
}

init() {
 ::init();
 add_action("enter","enter");
}

enter(str) {
  if (str=="portal") {
   write("The doberman lunges at your throat and knocks you to the ground.\n"+
         "It looks as if you'll have to kill it first before you can enter\n"+
         "the portal.\n");
   return 1;
   }
}

query_moncreator() { return "silas"; }

query_monmaker() { return 1; }
