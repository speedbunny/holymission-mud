/* Edited by Colossus 022494 */

#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if (!present("teeth")) {
	move_object(clone_object("/players/sherman/teeth2"),this_object());
    }
    if (arg) return;
    set_name("vampire guard");
    set_alt_name("guard");
    set_alias("vampire");
    set_level(20);
    set_str(40);
    set_dex(40);
    set_hp(600);
    set_al(-250);
    set_ac(15);
    set_wc(40);
    set_aggressive(1);
    set_race("undead");
    set_short("Vampire Guard");
    set_long(
      "The vampire guard growls as you approach and he advances upon\n"+
      "you with a determined stride. Though unarmed, he is very capable\n"+
      "of dealing with people who threaten his undead liege. He wears\n"+
      "a black suit but curiously has no flowing cape. Perhaps its\n"+
      "absence allows him more maneuverability. Red eyes glow as\n"+
      "he upons his mouth and bares his fangs.\n");
    add_money(500+random(500));
    command("wield teeth",this_object());
}

void init(){
    ::init();
    add_action("enter", "enter");
}

status enter(){
    write("The vampire guard glares at you as you attempt to enter and you realize that\n"+
      "you either have to sneak in somehow or kill them all first.\n");
    say(this_player()->query_name()+" attempts to enter the castle but "+
      "changes "+this_player()->query_possessive()+" mind.\n");
    return 1;
}
