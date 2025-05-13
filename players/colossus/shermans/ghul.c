/* Edited by Colossus 022594 */

#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if (arg) return;
    set_name("Ghoul");
    set_alias("ghoul");
    set_level(4+random(5));
    set_hp(200);
    set_al(-150);
    set_ac(3);
    set_aggressive(1);
    set_wc(12);
    set_race("undead");
    set_short("Ghoul");
    set_long(
      "According to the legends, Ghouls are creatures of the night\n"+
      "that arise from graves with their decaying flesh clinging to\n"+
      "their bones and they crave the blood of living things to keep\n"+
      "them warm though the blood is never enough. Their long bony\n"+
      "talons that are actually sharpened fingerbones and the way they\n"+
      "look and slaver at the sight of you convince you that the legends\n"+
      "are indeed true.\n");
    add_money(50+random(50));
}

void init(){
    ::init();
    add_action("nogo", "east");
}

status nogo(){
    write("The ghoul bars your way and stops you dead in your tracks with\n"+
      "a swipe of its talons.\n");
    say(this_player()->query_name()+" is stopped by the ghoul.\n");
    return 1;
}
