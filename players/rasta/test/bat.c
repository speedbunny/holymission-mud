
inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

  set_name("bat");
    set_level(2);
    set_al(2);
    set_race("animal");
set_short("An ice cave bat ");
    set_whimpy(); 
}
}
