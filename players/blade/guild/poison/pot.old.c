//#include "/players/kasgaroth/defs.h"
#define TP	this_player()
#define POISON	"/players/blade/guild/poison/"
inherit "obj/container";

string name;
object poison;
int sem, temp, strength, damage, death, value;

reset(arg)
{
    ::reset(arg);
    if (arg)
	return;
    set_name("pot");
    set_alias("container");
    set_short("A lead pot");
    set_long("An alchemist's pot, for mixing powerful potions.\n"
      +"Simply stir the ingredients.\n");
    set_value(0);
    set_can_get(0);
    set_max_weight(15);
}

find_ingredient(i) {
    object ob;
    int there;
    ob = first_inventory(this_object());
    while(ob) {
	if (ob->id(i))
	    there++;
	ob = next_inventory(ob);
    }
    return there;
}


init() {
    ::init();
    add_action("_stir","stir");
}

_stir(str) {
    int i;
    object *inv;

    if (!str || str!="ingredients")
	return notify_fail("Stir what?\n");
    if (find_ingredient("blackthorn root") < 3)
	return notify_fail("There doesn't seem to be enough to brew anything.\n");
    if (!present("alchemy stick", TP))
	return notify_fail("You need an alchemist's stick to properly stir the ingredients.\n");

    write("You stir the ingredients around with your alchemy stick.\n");
    say(this_player()->query_name()
      + " puts a stick into the pot and stirs it around.\n");
    value = find_ingredient("eye of newt") * 175;
    value = value + find_ingredient("dragons' blood") * 290;
    value = value + find_ingredient("tail of cockatrice") * 430;
    value = value + find_ingredient("powdered unicorns' horn") * 600;
    switch(value) {
    case 175:
	name = "witches' bane";
	strength = 12;
	break;
    case 605:
	name = "scorpions' blood";
	strength = 20;
	break;
    case 1935:
	name = "dragons' venom";
	strength = 35;
	break;
    default:
	name = "basilisk's eye";
	strength = 5;
	break;
    }
    if (find_ingredient("blackthorn root") > 3) {
	switch(value) {
	case 755:
	    name = "dragons' breath";
	    strength = 22;
	    break;
	case 290:
	    name = "viper";
	    strength = 15;
	    break;
	}
    }
    if (find_ingredient("blackthorn root") > 4) {
	if (value == 1070) {
	    name = "hemlock";
	    strength = 25;
	}
    }
    if (find_ingredient("blackthorn root") > 6) {
	if (value == 1500) {
	    name = "mandrake";
	    strength = 30;
	}
    }
    if (find_ingredient("blackthorn root") > 7) {
	if (value == 2250) {
	    name = "nightshade";
	    strength = 45;
	}
    }
    inv = all_inventory();
    for (i=0; i<sizeof(inv); i++)
	destruct(inv[i]);
    local_weight = 0; /* damn well better */
    call_out("reaction", 3);
    return 1;
}

reaction() {
    tell_room(environment(this_object()),
      "Smoke begins to pour from the mixture in the pot.\n"
      +"The magical ingredients within the pot start to shimmer and trickle through\n"
      +"a glass tube into a vial.\n");
    damage = TP->query_hp() * strength/100;
    if (damage > 1) {
	TP->reduce_hit_point(damage);
	write("You feel weak from smoke inhalation.\n");
	say(this_player()->query_name() + " looks weak from smoke inhalation.\n");
    }
    death = strength - (TP->query_level()+TP->query_dex()+random(5)+
			thief->query_legend_level());
    if (random(100) <= (death)) {
	write("You are overcome by the smoke and collapse.\n");
	say(this_player()->query_name() + " collapses.\n");
	TP->HIT(TP->query_hp() + 1);
    }

    temp=1;
    while(temp!=0){
      temp=random((thief->query_level()/2)+thief->query_legend_level());
      write("You grab a vial and pour some poison into it.\n");
      say(TP->query_name()+" grabs a vial and pours some poison into it.\n");
      poison = clone_object(POISON + "poison");
      move_object(poison, environment(this_object()));
      poison->set_name(name);
      poison->set_alias("poison");
      poison->set_alt_name("vial");
      poison->set_short(capitalize(name));
      poison->set_long(capitalize(name)+" is a vial of powerful poison.\n");
      poison->set_alchemic_value(value);
      poison->set_strength(strength);
      call_out("delay",2);
    }
    value=0;
    return 1;
  }
     
void delay(){}
     
