inherit "/obj/monster";

reset(arg)
 {
 ::reset(arg);

  load_chat(5,({"Bee\n"}));
  load_a_chat(40,({"Beeeeeeeeee\n"}));

if (arg) return;
 set_name("sheep");
 set_race("animal");
 set_short("A little sheep");
 set_long("A little sheep.\n"
         +"It jumps around you.\n");
 set_wc(3);
 set_ac(1);
 set_aggressive(0);
 set_al(100);
 set_level(4);
 set_size(1);
}
