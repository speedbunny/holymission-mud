inherit "obj/monster";
#include "/players/wilbie/def.h"

reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("matriarch");
    set_alias("priestess");
    set_alt_name("high");
    set_level(65);
    set_al(-999);
    set_gender(2);
    set_race("human");
    set_hp(17000);
    set_short("The Matriarch");
    set_long("This is the Matriarch of the Dark Order.  She rules her "+
	     "lesser clerics with an iron fist to serve the powers of "+
	     "Darkness.  She chants her prayers of evil with no regard "+
	     "for your presence.\n");
  set_wc(6);
    set_ac(2);
    set_size(3);
    add_money(10000);
    set_aggressive(0);
}

int hitter() {
    int i,j,k,dam;
    string str;
    object *ob;

    ob = all_inventory(ENV(TO));
    j = random(3);
    while (!j){
	i = random(sizeof(ob));
	if(living(ob[i]) && ob[i] != TO && !ob[i]->query_npc()) {
   	    j-=1;
   	    k=random(8);
   	    switch(k) {
       		case 0: str="a wave of scorching fire upon you!!\n"+
                	    "The stench of your own flesh burning fills "+
			    "your nostrils!\n";
                	dam = 80;
                	break;
       		case 1: str="a spear of chilling ice straight into your "+
			    "heart!!\nYou feel your life failing fast...\n";
                	dam = 75;
                	break;
       		case 2: str="a spear of ice against your skull with a THUD!"+
                	    "\nYou feel like blacking out for a moment...\n";
                	dam = 10;
                        ob[i]->hold(TO,2);
                	break;
       		case 3: str="a phantasm of fear into your soul!!\n";
                	dam = 0;
                	ob[i]->run_away();
                	break;
                case 4: str="searing flames in your face!\n";
                	dam = 25;
                	break;
       		case 5: str="phantasmal chains that CRUSH you!!\nThe High"+
                	"Priestess cackles as you stand helpless!!\n";
                	dam = 0;
                        ob[i]->hold(TO,3);
                	break;
       		case 6: str="a wave of force that SMASHES you!\n"+
                	"You find yourself pinned to the ground!!\n";
                	dam = 20;
                	ob[i]->hold(TO,5);
                	break;
       		case 7: str="a shard of ice into your flesh...\n";
                	dam = 10;
                	break;
       		default:str="arcane words of power in your direction.\n";
                 	dam = 0;
	    }
            TELL(ob[i], "The priestess hurls "+str);
     	   say("The priestess hurls her magicks at "+ob[i]->NAME+"\n",ob[i]);
       	    ob[i]->hit_player(dam);
	}
    }
    return 1;
}

int attack() {
    if(::attack()) {
	if(TO->query_attack())
      	hitter();
    }
}
