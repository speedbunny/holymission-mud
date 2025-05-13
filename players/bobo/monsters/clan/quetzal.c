inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("quetzal");
   set_level(3);
   set_wc(6);
   set_ac(1);
   set_al(0);
   set_gender(1);
   set_race("bird");
   set_short("Quetzal");
   set_long("The quetzal is a small beautiful bird.  It has brilliant\n"+
            "bronze-green and red plumage.  Its tail is long and flowing.\n");
}
