inherit "obj/monster";
 
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("toad");
 set_level(5);
 set_hp(50);
 set_al(-10);
 set_race("frog");
 set_size(1);
 set_short("A toad");
 set_long("A ugly toad. You see nothing special about it.\n");
 set_ac(3);
 set_wc(4);
 set_aggressive(0);
}
get() { return 1; }
 
 
 
