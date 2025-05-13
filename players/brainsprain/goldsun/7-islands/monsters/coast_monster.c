inherit "/obj/monster";

  //  name, lvl, race 

#define NAME ({"turtle",30,"turtle","seal",32,"seal","vulcano turtle",35,\
  	       "turtle","mutant crab",21,"crab","sea giant",38,"giant",\
   	       "sea snake",23,"snake"})


void add_stuff()
{
 object ob;
 ob=clone_object("obj/weapon");
 ob->set_name(name+" tooth");
 ob->set_weight(2);
 ob->set_class(15);
 ob->set_value(2100);
 ob->set_short("A "+name+" tooth");
 ob->set_long("A "+name+" tooth. It looks sharp.\n");
 transfer(ob,this_object());

 ob=clone_object("obj/armour");
 ob->set_name(name+" tooth");
 ob->set_weight(2);
 ob->set_type("ring");
 ob->set_class(1);
 ob->set_value(100);
 ob->set_short("A "+name+" ring");
 ob->set_long("A "+name+" lucky ring.\n");
 transfer(ob,this_object());
}

void reset(int arg)
 {
int i;

 ::reset(arg);
if (arg) return;
i=random(sizeof(NAME)/3)*3;
set_name(NAME[i]);
set_race(NAME[i+2]);
set_alt_name("coast_monster");
set_gender(random(3));
set_short("A "+name);
set_long("A "+name+". "+capitalize(query_pronoun())+" lies here and looks "+
	 "peaceful.\n");
set_level(NAME[i+1]);
set_wc(level-10);
set_ac(9);
set_hp(query_hp()+1000);
set_size(3);
set_al(-15+random(120));
add_money(level*50);
add_stuff();
}

