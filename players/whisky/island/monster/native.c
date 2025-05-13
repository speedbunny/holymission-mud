
inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("native");
    set_level(8); 
    set_hp(80);
    set_ac(4);
    set_dex(14);
    set_al(-10); 
    set_whimpy(30);
    set_race("human"); 
    set_short("A native");
    set_long("An aggressive looking native\n"); 
    set_gender(1+random(2));
    set_ac(4); 
    set_aggressive(1);
    move_object(clone_object("players/whisky/island/obj/spear"),
    this_object()); 
    move_object(clone_object("players/whisky/island/obj/native_jacket"),
    this_object());
    init_command("wield spear"); 
}
}

