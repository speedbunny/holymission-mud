
inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

    set_name("bear");
    set_level(50); 
    set_al(-100); 
    set_alias("bear");
    set_race("bear"); 
    set_alt_name("hugebear");
    set_short("HUGE black bear");
    set_long("Huge black bear with yellow teeth and red staring eyes.\n"+
             "The long sharp claws look VERY sharp.\n");
    set_wc(19);
    set_ac(25);
    set_aggressive(random(2)); 
    load_chat(8,({
                  "Bear paces around looking at you.\n",
                  "Bear snorts loudly.\n", "Bear scratches its side.\n",
                  "Bear licks its front paws.\n","Bear growls at you.\n",
                  "Bear paces backwards and bumps into the wall.\n",
                  "Bear stretches its body out and gives a big yawn.\n",
                 }));
    set_dead_ob(this_object());
    set_spell_mess1("The bear bats you with its paws");
    set_spell_mess2("The bear hurts you with its claw");
                        
    set_chance(20); 
    set_spell_dam(40);
    add_money(random(500)+2500);

    move_object((clone_object("players/apollo/area2/weapons/bear_claw")),
	this_object());
    init_command("wield claw");

  }
}

