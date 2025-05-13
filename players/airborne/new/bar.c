inherit "room/room";
#define MUST_STAY_WITH_DRINKS
object bar;

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Complete newbie area - bar";
   long_desc = 
"    After some adventuring, your Hit Points and Spell Points will surely "+
"falter at some point. They will naturally return given enough time "+
"however drinking will replenish and speed in your healing. \n"+
"   You notice that this is a tavern and that there is a sign on the wall "+
"which reads as follows :\n "+
 "      **************************************      \n"+
"       Moe's beer                    10 coins    \n"+
"       Moe's wine                    50 coins    \n"+
"       Flaming Moe                  150 coins    \n"+
"       **************************************    \n\n"+
"   To order a drink, type 'order <name>' with the name being the name of "+
"the drink you wish to buy. "+
"You will be able to return to the bar at any time while you are still "+
"in this area by typing 'bar'.\n"+
"   Don't worry if you don't have enough money to buy a drink here, they will "+
"not cost you any money if you do not have it because Moe is a nice guy.\n";

   dest_dir = ({"players/airborne/new/newbie11", "south", });   

   items = ({ "bar", "Moe stands behind a wooden bar" });

   property = ({"no_teleport", "no_steal", "no_fight" });
   smell = "You smell wonderful scent of Moe's drinks";

if(!present("bartender", this_object())){
  bar=clone_object("obj/monster");
  bar->set_name("bartender");
  bar->set_alt_name("moe");
  bar->set_short("Moe the bartender");
  bar->set_long("A skinny little bartender named Moe.\n");
  bar->set_level(100);
  bar->set_ac(50);
  move_object(bar, this_object());
  }
	}
}

init(){
 ::init();
   add_action("order", "buy"); 	add_action("order", "order");
   add_action("leave", "leave"); 
	}

order(str){
object drink;
string name, short_desc, mess;
int value, cost, strength, heal, cash;

if(!str) { 
   	write("Order what?\n");
	return 1; }

if(str=="beer" || str=="Moe's beer") {
	name = "beer";
	short_desc = "A bottle of Moe's finest";
	mess = "That feels good";
	heal = 3;
	value = 10;
	strength = 1; }

else if(str=="wine" || str=="Moe's wine"){
	name = "wine";
	short_desc = "Wine from Moe's tavern";
	mess = "The wine feels good going down";
	heal = 10;
	value = 50;
	strength = 3;  }

else if(str=="flaming" ||str=="Flaming Moe" || str=="moe") {
	name = "moe";
	short_desc = "A flaming Moe";
	mess = "Ahh... now you know why its one of Moe's best";
	heal = 25;
	value = 150;
	strength = 7; }

else {
	write("Moe doesn't seem to have that in stock right now.\n");
	return 1; }

if(present("coins", this_object())){
	write("Moe says: Someone must have left me a tip!\n");
	write("Moe takes the coins.\n");
	destruct(present("coins", this_object()));
	 return 1; }

drink = clone_object("obj/drink");
 if(!call_other(drink, "set_value", name + "#" + short_desc + "#" + mess + "#" + heal + "#" + value + "#" + strength)){
	write("Moe must have made a mistake with the drink.\n");
	destruct(drink);
	 return 1; }

  call_other(drink, "set_pub");
  transfer(drink, environment(this_player()));	/*HERP 93-Sep-7*/
  call_other(this_player(), "add_money", - value);

cash = this_player()->query_money();
  if(cash < 0){
	cash = - cash;
	this_player()->add_money(cash); }

   write("You pay "+value+" for a "+name+".\n");
   say(this_player()->query_name()+" orders a "+name+".\n");
    destruct_bottle(this_player(), name);
	return 1; }

destruct_bottle(player, name){
object ob, next_ob;
string it;

  ob = first_inventory(player);
   while (ob) {
	next_ob = next_inventory(ob);
	it = call_other(ob, "query_name");
	 if(it == name){
		call_other(ob, "drink", name);
		destruct(ob);
             return 1; }
 	ob = next_ob;
	}
    }

leave(){
     write("You can leave from the room to the south.\n");
	return 1; }
                            
move(){
#ifdef MUST_STAY_WITH_DRINKS
   if(has_drink(this_player())){
        tell_object(this_player(), 
		"Moe will not let you leave with drinks.\n");
			return 1;
		}
#endif
	return ::move();
	}

#ifdef MUST_STAY_WITH_DRINKS
has_drink(obj){
  status drink;
  object ob;

     ob = first_inventory(obj);
     	while(ob){
	     if(call_other(ob, "id", "drk2"))
		drink = 1;
             if(call_other(ob, "can_put_and_get")){
		if(has_drink(ob))
		  drink = 1;
		}
	ob = next_inventory(ob);
	return drink;
	}
#endif 
}
