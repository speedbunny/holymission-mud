inherit "obj/monster";
#include "/players/wilbie/def.h"

object monst;

reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("sheankala");
    set_alias("goddess");
    set_number_of_arms(6);
    set_alt_name("high");
    set_level(90);
    set_al(-999);
    set_hp(100000);
    set_gender(2);
    set_race("diety");

    set_short("The Goddess Sheankala");
    set_long("This is the Goddess Sheankala, diety of the Dark Order. "+
    "She flexes her six arms in a rather threatening manner, and "+
    "she glares at you with a smug look of power.\n");
 set_wc(8);
 set_ac(8);
 set_dead_ob(this_object());
    set_size(3);
    add_money(10000);
    set_aggressive(0);

 set_spell_mess1("The Goddess conjures a wave of dark power!");
 set_spell_mess2("You scream in agony as darkness fills your soul!");
 set_chance(99);
 set_spell_dam(10+random(70));
}

int monster_died()
{
shout("Sheankala swears vengeance as she falls in battle to "+
this_player()->query_name()+" the "+
("/guild/master"->query_name(this_player()->query_guild()))+
"!\n");
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
                        dam = 130;
                	break;
                case 1: str="a bolt of power through your wretched body!\n";
                	dam = 75;
                	break;
 case 2: str="a curse that sends you to another place!\n";
                        dam = 50;
write("The goddess teleports her foe away!\n");
 ob[i]->move_player("somewhere","/players/wilbie/graveyard/doom10");
 this_player()->look();
                	break;
 case 3: str="a curse that sends you to another place!\n";
                        dam = 30;
write("The goddess teleports her foe away!\n");
 ob[i]->move_player("somewhere!","/players/wilbie/graveyard/doom6");
 this_player()->look();
                	break;
                case 4: str="a bolt of lightning at you!\n";
                        dam = 60;
                	break;
                case 5: str="a hellish inferno that engulfs you!\n";
                        dam = 80;
                	break;
 case 6: str="a wave of dark mist into the air.  Sudden pain fills you\n"+
             "You feel you life being suked away...\n"+
             "Sheankala breathes the mist in deeply to heal herself!\n";
 heal_self(100+random(300));
                	dam = 20;
                	break;
                 case 7: str="a burst of freezing wind at you!\n";
                	dam = 10;
                	break;
       		default:str="arcane words of power in your direction.\n";
                 	dam = 0;
	    }
            TELL(ob[i], "The goddess hurls "+str);
     	   say("The goddess hurls her magicks at "+ob[i]->NAME+"\n",ob[i]);
       	    ob[i]->hit_player(dam);



 if(random(100)<10){


 say("Sheankala utters some arcane words and a Narguhl forms in her hands!\n");
 monst=CO("/players/wilbie/graveyard/monsters/narguhl2.c");
 MO(monst,this_object());
 init_command("drop narguhl");
}
	}
    }
    return 1;
}

int attack() {
    if(::attack()) {
	if(TO->query_attack())
      	hitter();
    }
load_chat(30,({
"The Goddess smirks at you.\n",
"The Goddess checks you for power and looks unimpressed.\n",
"The Goddess stares at you and licks her lips.\n",
}));
load_a_chat(40,({
"The Goddess bellows in anger!\n",
"The Goddess cackles with glee!\n",
}));
}
