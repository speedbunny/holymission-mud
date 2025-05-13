inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("jaguar");
   set_level(15);
   set_wc(20);
   set_ac(6);
   set_al(0);
   set_gender(1);
   set_race("cat");
   set_short("Jaguar");
   set_long("This cat is six feet long and very powerful.  It is yellow\n"+
            "with black circular dots lining its body.  It is definitely\n"+
            "a powerful predator.\n");
}
