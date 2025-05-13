inherit "/obj/monster";
#define NAME ({"zzx",18,"qwerty",25,"syntax",38,"rekcuf",26,"phocus",24,\
               "zadrienka",33,"demolish",45,"zucker",15,"silabus",34})

void reset(int arg)
 {
int i;

 ::reset(arg);
if (arg) return;
i=random(sizeof(NAME)/2)*2;
set_name(NAME[i]);
set_race("creature");
set_short("A "+name+" creature");
set_long("You see a strange creature.\n"+capitalize(query_pronoun())+" looks "+
	 "very hungry and thirsty.\n");
set_level(NAME[i+1]);
set_wc(9+level);
set_ac(4);
set_hp(query_hp()+1000);
set_size(3);
set_al(30);
set_spell_mess1(capitalize(name)+" snatches your leg.\n");
set_spell_mess2(capitalize(name)+" opens its mouth.\n");
set_chance(50);
set_spell_dam(level*2);
add_money(level*50);
}

