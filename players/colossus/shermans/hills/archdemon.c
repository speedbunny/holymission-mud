/* Kbl Modified this file Oct 13, 93 - commented the fireshield out and the
				       set_hp(4000); statement out
*/
/* Edited by Colossus: 070994 */
#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    object o;
    ::reset(arg);
    if (arg) return;
    set_name("archdemon");
    set_alt_name("demon");
    move_object(clone_object("/players/sherman/hills/dplate"),this_object());
    move_object(clone_object("/players/sherman/hills/demonwhip"),this_object());
    move_object(o=clone_object("obj/armour"),this_object());
    o->set_name("cross");
    o->set_short("a silver cross");
    o->set_long("A beautiful worked silver cross.\n");
    o->set_weight(1);
    o->set_ac(0);
    o->set_type("cross");
    o->set_value(500);
    set_level(60);
    /*
	set_hp(4000);
    */
    set_al(-500);
    set_ac(20);
    set_aggressive(1);
    set_wc(50);
    set_race("demon");
    set_short("Archdemon");
    set_long(
      "The archdemon is a towering demon which stands 8 feet tall\n\
with an angry red complexion and bulging muscles. Its face\n\
is grotesque, with bull horns and a snarling muzzle which\n\
is full of teeth. Its hands cannot be properly called hands\n\
but razor sharp talons. It emits a howl of pure ecstasy and\n\
hate as it sees you.\n");
    set_chance(10);
    set_spell_mess1("The demon flames his opponent");
    set_spell_mess2("The demon burs you");
    set_spell_dam(80);
    command("wield whip",this_object());
    command("wear demonplate",this_object());
    /* Commenting this following two lines out... reason...
       fighters get killed by this item when a VICIOUS hit is generated.
       Already reimbursed Gerrit for dieing... thought it was a guild
       bug in fighters guild. Sherman, if you uncomment this out, please
       mail me.

							 Kbl
	o=clone_object("/players/llort/guild/obj/fireshield");
	o->start_shadow(this_object(),-1);
    */
}
