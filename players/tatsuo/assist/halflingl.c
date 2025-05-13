inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("halfling leader");
   set_alias("leader");
   set_level(16);
   set_wc(22);
   set_ac(7);
   set_al(0);
   set_gender(1);
   set_race("halfling");
   set_short("Leader");
   set_long("The halfling leader is siting in the chair with his blank\n"+
            "stare.  He seems to see everything and nothing in the same\n"+
            "moment.  He eems to radiate confidence and power.\n");
   add_money(200);
}

void init() {
   ::init();
   add_action("_press","press");
}

_press(str) {
if (!str) return 0;
if (str != "eye") return 0;
      write("The leader says: Get the hell away from my chair.\n");
      return 1;
   }

