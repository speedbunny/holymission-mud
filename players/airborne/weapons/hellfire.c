/* Baal-rog's Axe.*/

#define TP	this_player()
#define TPN	TP->query_name()

inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_id("hellax_quest");
  set_name("battle axe");
  set_weight(1);
  set_alias("hellfire");
  set_class(19);
  set_light(5);
  set_value(7500);
// 230498: Sauron: Changed so that the axe id's to axe. :)
  set_alt_name("axe");
  set_short("Hellfire Battle Axe");
  set_long("The battle axe glows with the blueish hellfire that\n"+
           "surrounds it. The blade seems to be made from a metal\n"+
           "that is hard to indentify. Must be a strong metal to\n"+
           "withstand the hellfire.\n");
  set_hit_func(this_object());
}
query_quest_obj() {return 1;}

#define	obn	ob->query_name()
weapon_hit(attacker) {
 int i;
i =  random(5);

if (i==0) {
	write("The hellfire appears to be contained.\n");
	return 10;
	}
if (i==1){
	write("The Hellfire flares.\n");
	return 15;
		}
if (i==2){
	write ("The Hellfire flashes before you.\n");
	return 20;
		}
if (i==3){
	write("The Hellfire strikes a mighty blow.\n");
	return 30;

		}
if (i==4){
	write ("The Hellfire leaps from the axe and strikes with great force.\n");
	return 40;
		}
	return 1;
}
give() { return 1; }
