inherit "/obj/monster";

  //  name, lvl,  race 

#define NAME ({"golemus",45,"golem","fire demon",52,"demon","lava monster",55,\
  	       "monster","fire giant",55,"giant","lava element",58,"element",\
   	       "ghost of Fire",60,"ghost"})

void reset(int arg)
 {
int i;

 ::reset(arg);
if (arg) return;
i=random(sizeof(NAME)/3)*3;
set_name(NAME[i]);
set_alias("vmon");
set_race(NAME[i+2]);
set_gender(random(3));
set_short("A "+name);
set_long("A "+name+". "+capitalize(query_pronoun())+" is build from fire and\n"+
	 "likes fighting.\n");
set_level(NAME[i+1]);
set_wc(level-10);
set_ac(8);
set_hp(query_hp()+1000);
set_size(3);
set_al(30);
set_spell_mess1(capitalize(name)+" breathes a cloud of fire at you !!!\n");
set_spell_mess2(capitalize(name)+" breathes a cloud of fire.\n");
set_chance(50);
set_spell_dam(level*2);
add_money(level*500);
}

