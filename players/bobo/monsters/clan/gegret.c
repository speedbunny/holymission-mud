inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("great egret");
   set_alias("egret");
   set_level(7);
   set_wc(9);
   set_ac(2);
   set_al(0);
   set_gender(1);
   set_race("bird");
   set_short("Great Egret");
   set_long("This bird stands nearly three feet tall and has downy white\n"+
            "feathers.  It has a long neck and a pointy beak designed to\n"+
            "spear its prey.\n");
}
