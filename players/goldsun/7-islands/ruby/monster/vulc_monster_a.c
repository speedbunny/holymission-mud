inherit "/obj/monster";

  //  name, lvl,  race 

#define NAME ({"striker",40,"striker","lightning bolter",20,"bolter",\
	       "red troll",18,"troll","fire orc",10,"orc","lava wasp",\
	       7,"wasp"})

void reset(int arg)
 {
int i;

 ::reset(arg);
if (arg) return;
i=random(sizeof(NAME)/3)*3;
set_name(NAME[i]);
set_race(NAME[i+2]);
set_alias("vmona");
set_gender(random(3));
set_short("A "+name);
set_long("A "+name+". "+capitalize(query_pronoun())+" is watching angrily at\n"+
	  "you and mumbles: Sniff. Sniff. I smell a well toasted dinner.\n");
set_level(NAME[i+1]);
set_wc(level);
set_ac(2);
set_hp(query_hp()+100);
set_size(3);
set_al(30);
set_spell_mess1(capitalize(name)+" breathes a cloud of fire at you !!!\n");
set_spell_mess2(capitalize(name)+" breathes a cloud of fire.\n");
set_chance(20);
set_spell_dam(15);
set_aggressive(1);
}

