
inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

  set_name("mosquito");
    set_level(2);
    set_al(2);
    set_race("animal");
set_short("A biting gnat");
    set_whimpy(); 
}
}
