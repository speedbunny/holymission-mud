
inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

  set_name("buzzard");
    set_level(8); 
    set_al(10); 
    set_race("animal"); 
set_short("A giant turkey buzzard");
    set_whimpy(); 
}
}
