
inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("carapace");
    set_alt_name("river carapace");
    set_level(12); 
   set_has_gills();
    set_hp(200);
    set_al(10); 
    set_race("fish"); 
    set_short("A big river carapace"); 
    set_long("You see a big brown river carapace.\n");
    set_wc(15);
    set_ac(2); 
    set_whimpy();
    move_object(clone_object("players/whisky/lake/obj/shield"),this_object());
}
}

