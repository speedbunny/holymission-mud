inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("tapir");
   set_level(10);
   set_wc(12);
   set_ac(3);
   set_al(0);
   set_gender(1);
   set_race("tapir");
   set_short("Tapir");
   set_long("This is a large creature that looks vaguely like an ant eater.\n"+
            "It stands two and a half feet tall and is six feet long.  It\n"+
            "looks like a very hearty animal.\n");
}
