#define TP this_player()
#define TPN TP->query_name()
inherit"players/warlord/NEWSTUFF/room";
int i,j,k,l;
reset(arg) {
    i=0;j=0;k=0;l=0;
    if (arg) return;
    set_light(1);
    short_desc = "Plush forest";
    long_desc = "The forest is very dense with large trees and very pretty\n"
    +"flowers and a nice river flowing near you.\n";
    items = ({
      "flowers","The flowers are beautiful and smell nice. Pick one!\n"
      +"There are red and black roses, carnations and orchids",
      "roses","The roses are long and beautiful",
      "red roses","The red roses are have long stems and are swaying in the breeze",
      "black roses","The black roses are thorny and evil looking",
      "forest","The forest is green and dense with trees",
      "carnations","The carnations are pink and lond stemmed",
      "orchids","The orchids are long and beautiful",
      "trees","The trees look very green and large",
      "river","The river is beautiful. Although there are no fish in it",
    });
    dest_dir=({
      /*
	       "/players/warlord/quest/dungeon/for2","north",
      */
      "/players/warlord/quest/dungeon/room9","south",
    });
}
init() {
    add_action("pick","pick");
    ::init();
}
pick (arg) {
    object ro1,ro2,orc,car,sword;
    if (arg=="flowers") {
	write("Which flower? Look at them and choose.\n");
	return 1;
    }
    switch (arg) {
    case "red rose":
	if (i<3) {
	    ro1=clone_object("obj/treasure");
	    ro1->set_id("rose");
	    ro1->set_short("Red rose");
	    ro1->set_long("A long stem red rose.\n");
	    ro1->set_value(10);
	    ro1->set_weight(0);
	    move_object(ro1,(TP));
	    write("You have picked a red rose.\n");
	    say(TPN+" has picked a red rose.\n");
	    i=i+1;
	}
	else {
	    write("You have picked the red roses clean!\n");
	    say(TPN+" has picked the red roses clean!\n");
	}
	break;
	return 1;
    case "orchid":
    case "orchids":
	if (k<3) {
	    orc=clone_object("obj/treasure");
	    orc->set_id("orchid");
	    orc->set_short("Orchid");
	    orc->set_long("A beautiful multicolorful orchid.\n");
	    orc->set_value(0);
	    orc->set_weight(0);
	    move_object(orc,(TP));
	    write("You have picked an orchid.\n");
	    say(TPN+" has picked an orchid.\n");
	    k=k+1;
	}
	else {
	    write("You have cleaned out all the orchids.\n");
	    say(TPN+ " has cleaned out all the orchids.\n");
	}

	break;
	return 1;
    case "carnation":
    case "carnations":
	if (l<3) {
	    car=clone_object("obj/treasure");
	    car->set_id("carnation");
	    car->set_short("Carnation");
	    car->set_long("This is a long stemmed carnation.\n");
	    car->set_value(0);
	    car->set_weight(0);
	    move_object(car,(TP));
	    write("You picked a beautiful carnation.\n");
	    say(TPN+" has picked a carnation.\n");
	    l=l+1;
	}
	else {
	    write("You cleaned out all the carnations.\n");
	    say (TPN+ " has cleaned out all the carnations.\n");
	}
	break;
	return 1;
    case "black rose":
	if ( (present("scroll",this_player()))) {
	    if (j<3) {
		ro2=clone_object("obj/treasure");
		ro2->set_id("black rose");
		ro2->set_short("Black rose");
		ro2->set_long("This is an evil looking rose.\n");
		ro2->set_value(0);
		ro2->set_weight(0);
		move_object(ro2,(TP));
		write("You picked a black rose and you were pricked by a thorn\n");
                write("Ouch! That smarts!!\n");
		say(TPN+" pickes a black rose and is pricked.\n");
		j=j+1;
		TP->hit_player(random(40));
	    }
	    else {
		if (j<4) {
		    sword=clone_object("obj/weapon");
		    sword->set_name("black sword");
		    sword->set_alias("sword");
		    sword->set_short("Black sword");
		    sword->set_long("This sword is very powerful!\n");
		    sword->set_class(20);
		    sword->set_value(4000);
		    sword->set_weight(3);
		    sword->set_hit_func(this_object());
		    transfer(sword,this_object());
		    write("The ground suddenly shakes. Where the black roses used to be\n");
		    write ("there is a sword. You found a sword.\n");
		    say(TPN+ " has found a sword!\n");
		    j=j+1;
		}
		else {
		    write("You have cleaned the black roses out\n");
		    say(TPN+" has cleaned out all the black roses\n");
		}
	    }
	}
	else {
	    write("For some reason you can't pick a black rose.\n");
	    return 1;
	}
	break;
    default:
	write("There are none of those here.\n");
	return 1;
    }
    return 1;
}

weapon_hit(attacker) {
    if (attacker->query_race()=="questunicorn") {
	return 35;}
}
