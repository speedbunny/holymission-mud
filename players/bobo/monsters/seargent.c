inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("seargent");
   set_level(6);
   set_wc(8);
    set_ac(2);
   set_al(10);
   set_gender(1);
   set_race("human");
   set_short("Seargent");
   set_long("This man looks very serious and duty bound.  He is standing\n"+
            "rigid and firm at his post.  He looks as if he will not let\n"+
            "you pass.\n");
   add_money(150);
}

void init() {
   ::init();
   add_action("_up","up");
}

_up() {
   write("The seargent will not allow you past him.\n");
return 1;
}
