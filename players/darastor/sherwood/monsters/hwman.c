inherit "/obj/monster";

reset(arg)
 {
 ::reset(arg);
 if (arg) return;
set_name("highwayman");
set_alt_name("man");
set_race("troll");
set_short("Dangerous highwayman");
set_long("This is dangerous highwayman.\n"
        + "He is member of Saliman's guild.\n"
        +"Don't desturb him.\n");
set_wc(12);
set_ac(3);
set_gender(1);
set_spell_mess1("\nThe highwayman throws an earth into enemy eyes.");
set_spell_mess2("\nThe highwayman throws an earth into your eyes.");
set_chance(18);
set_aggressive(0);
set_level(19);
set_size(4);
add_money(500+random(500));  /* was too much before */
move_object(clone_object("/players/goldsun/sherwood/obj/club"),
             this_object());
command("wield club");
}

query_plural(){ return "men"; }

