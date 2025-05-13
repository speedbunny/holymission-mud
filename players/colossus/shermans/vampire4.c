/* Edited by Colossus 030494 */

#pragma strict_types

inherit "obj/monster";

int ticks;
int fl;

void reset(int arg){
    ::reset(arg);
    if(environment() && environment()->id("coffin")) ticks++;
    if(ticks==2) {
	ticks=0;
	fl=666;
	set_aggressive(0);
	move_player("X#players/sherman/vtower7");
    }
    if (arg) return;
    set_name("vampire king");
    set_alt_name("vampire");
    set_alias("king");
    set_level(80);
    set_hp(7000);
    set_al(-1000);
    set_ac(25);
    set_aggressive(0);
    set_race("greatundead");
    set_short("Vampire King");
    set_long(
      "You come face to face with the Vampire King. Though in almost\n"+
      "every way he resembles a normal vampire, though who can really\n"+
      "call vampires normal... The difference that you cannot see but\n"+
      "feel, however, is his aura of power. The aura of fear and dread\n"+
      "all but smothers you and you cannot help but flinch. His gaze\n"+
      "penetrates to your very soul and drool drips off his fangs as\n"+
      "he regards you.\n");
    set_chance(20);
    set_spell_mess1("Vampire King stares in his victims eyes");
    set_spell_mess2("Vampire King drains you");
    set_spell_dam(120);
    set_dead_ob(this_object());
    move_object(clone_object("players/sherman/regring"),this_object());
    if(sizeof(explode(file_name(this_object()),"#"))>1)
	"players/sherman/swords/sword1"->xxx();
    command("wear ring",this_object());
    command("wield sword",this_object());
    ticks=0;
}

status monster_died(object ob){
    if(environment(this_object())==find_object("players/sherman/vtower9")) {
	say(this_object()->query_name()+" transforms into a cloud of gas\nand"+
	  " disappears through a crack in the northern wall.\n");
    } else {
	say(this_object()->query_name()+" transfroms into a cloud of gas and "+
	  "disappears.\n");
    }
    move_object(this_object(),"players/sherman/vtower10");
    move_object(this_object(),
      find_object("players/sherman/vtower10")->get_coffin(random(3)));
    return 1;
}

int *dump(){ return ({ ticks, fl }); }

void heart_beat(){
    heal_self(4);
    ::heart_beat();
}
