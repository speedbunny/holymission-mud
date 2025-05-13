#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if (!present("blood glass")) {
	move_object(clone_object("/players/sherman/bglass"),this_object());
    }
    if (arg) return;
    set_name("vampire guest");
    set_alt_name("guest");
    set_alias("vampire");
    set_level(25);
    set_hp(1500);
    set_al(-500);
    set_ac(18);
    set_wc(25);
    set_chance(20);
    set_spell_dam(40);
    set_spell_mess1("The vampire stares into his opponents eyes\n");
    set_spell_mess2("The vampire drains you\n");
    set_aggressive(0);
    set_race("undead");
    set_short("Vampire Guest");
    set_long(
      "The vampire wears the traditional black cape and carries\n"+
      "a small glass of red liquid in his hand. The liquid is blood\n"+
      "most likely. As you enter, he turns his blood-red gaze upon\n"+
      "you and prepares to attack you.\n");
    add_money(500+random(500));
}
