inherit "obj/monster";
 
reset(arg) {
::reset(arg);
if (arg) return;
 set_name("guard");
 set_short("A Faun-guard");
 set_long("The Faun-guard is a tough faun.\n");
 set_ac(8);
 set_race("faun");
 set_size(3);
 set_male();
 set_level(15);
 set_al(500);
 set_ep(131687);
 set_wc(15);
 set_aggressive(0);
 
}
