#define ME this_object()
int sleep,arg;
inherit "/obj/monster";
 
   reset(arg) {
    ::reset(arg);
     if(arg) return;
        move_object(clone_object("/players/alex/other/btoken"),ME);
 
 
    set_name("ghost");
    set_alias("guard");
    set_alt_name("commander");
    set_short("Ghost of a commander");
    set_long("A long dead ghost of a commander of the Wood elvs.\n");
    set_gender(1);
    set_level(12);
    set_aggressive(0);
    set_al(-1000);
}
 
init() {
 ::init();
 add_action("west","west");
}
 
 
west() {
  write("The guard grabs you stops you from entering.  \n"+
        "He then tries to separate you from your head.\n");
  set_aggressive(1);
  return 1;
}
 
