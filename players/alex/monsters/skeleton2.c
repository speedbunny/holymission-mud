inherit "/obj/monster";
 
   reset(arg) {
    ::reset(arg);
     if(arg) return;
 
    set_name("skeleton");
    set_alias("skeleton2");
    set_short("skeleton");
    set_long("A long dead elf who will for ever serve it's master.\n");
    set_gender(1);
    set_level(4);
    set_aggressive(1);
    set_al(-200);
}
 
 
