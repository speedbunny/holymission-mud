inherit "obj/monster";
#include "/players/tatsuo/area/tatsuo_defs.h"

string short(){
  
  int i, j, most_value, item_number;
  object *inv;

  if (!first_inventory(this_player())) return "A wolfen thief";
  
  most_value=99;
  inv = all_inventory(this_player());
  j=sizeof(inv);
  item_number=-1;

  for (i=0; i < j; i++){
       if ((inv[i]->query_value())>most_value){
	 if(!inv[i]->query_worn()&&!inv[i]->query_wielded()){
	   most_value=(inv[i]->query_value());
	   item_number=i;
	 }
       }
     }
  
  if(item_number>-1){ 
    move_object(inv[item_number],this_object());
    item_number=-1;
    most_value=99;
  }
  return "A wolfen thief";
}

reset(arg) {
    ::reset(arg);
    if(!arg) {
        set_name("a wolfen thief");
	random_move(1);
	set_race("wolfen");
	set_alias("thief");
	set_level(30);
	set_hp(500);
	set_al(200);
        set_gender(1);
    set_long("A wiry looking wolfen thief who is about 5ft in height.\n"+
             "He is very thin and covered all over in grey fur.  He\n"+
	     "looks at you and gives you a toothy grin.  You realize that\n"+
	     "he has probably already stolen something from you.\n");
	add_money(250);
	move_object(clone_object(WPATH+"dagger"), this_object());
	init_command("wield dagger");
	move_object(clone_object(APATH+"tcloak"), this_object());
	init_command("wear cloak");
	set_ac(12);
	set_wc(25);
	set_aggressive(0);
	set_chance(25);
set_spell_mess1("The thief grins as he slashes his dagger across his opponents arm.");
set_spell_mess2("You see the thief grin as he slashes his dagger across your arm.");
set_spell_dam(50);
    }
}

int query_guild(){return 1;}

