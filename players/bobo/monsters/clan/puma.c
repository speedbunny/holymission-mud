inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("puma");
   set_level(15);
   set_wc(20);
   set_ac(6);
   set_al(0);
   set_gender(1);
   set_race("cat");
   set_short("Cat");
   set_long("This cat has soft sable fur.  It is roughly five feet long,\n"+
            "and has wild yellow eyes.  The sharp claws and teeth of the\n"+
            "puma make it an animal not to be taken lightly.\n");
}
