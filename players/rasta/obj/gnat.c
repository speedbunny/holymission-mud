
inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

  set_name("gnat");
    set_level(2); 
    set_al(12); 
    set_race("animal"); 
set_short("A biting gnat");
    set_whimpy(); 
    add_money(random(40)+15);
}
}
