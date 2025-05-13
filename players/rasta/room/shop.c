#define MUST_STAY_WITH_DRINKS
object sign; 
object player;
int current_problem, starts_thinking;
object solved_by, wrong_by;
int problem_value;

object rules;

object paper;

query_property(str) { return str=="no_teleport"; }

reset(arg) {
    start_player();
 if (!sign || !present(sign, this_object())) {
sign = clone_object("players/rasta/obj/sign2");
move_object(sign,this_object());
    }

    if (arg) return;
    set_light( 1);
}

short() {
   return "I-tal food shop";
}

init() {
    add_action("move", "west");
    add_action("move", "up");
    add_action("order", "order");
    add_action("order", "buy");
    add_action("look", "look");
}

move() {
#ifdef MUST_STAY_WITH_DRINKS
     if (has_drink(this_player())) {
        tell_object(this_player(),
           "You are not allowed to leave with i-tal food stuff!\n");
        return 1;
     }
#endif
     switch (query_verb()) {
     case "west" : this_player()->move_player("west#room/yard");   break;
     default     : return 0; break;
     }
     return 1;
}

long() {
  write("This is a small shop where Rastafarian use to buy their i-tal\n"
  +"vegetarian food\n");
write("    A thirst-quenching water coconut,  12 coins\n");
write("    A giant pine apple, 50 coins\n");
  write("    A salt fish, 150 coins\n\n");
    write("There are two obious exits: west and up.\n");
}

order(str)
{
    object drink;
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
  if (str == "coconut") {
	name = str;
short_desc = "A thirst-quenching water coconut";
mess = "That makes you feel irie";
	heal = 0;
	value = 12;
	strength = 2;
    }
  else if(str = "pine apple" || str == "apple") {
name = "pine apple";
short_desc = "A giant Jamaican pine apple";
mess = "You feel like singing a reggae tune";
	heal = 10;
	value = 50;
	strength = 8;
  } else if (str == "fish" || str == "salt fish") {
name = "salt fish";
short_desc = "A salt fish";
mess ="You praise Jah who created fish";
	heal = 25;
	value = 150;
	strength = 12;
#if 0
    } else if (str == "potion" || str == "potion of healing") {
	name = "potion";
	short_desc = "A potion of healing";
	mess = "You are totally healed";
	heal = 1000;
	value = 200;
	strength = 0;
#endif
    } else {
       write("What ?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {

	return 1;
    }
    drink = clone_object("obj/drink");
    if (!call_other(this_player(), "add_weight",
	call_other(drink, "query_weight"))) {
	write("You can't carry more.\n");
	destruct(drink);
	return 1;
    }
    if (!call_other(drink, "set_value", name + "#" + short_desc + "#" + mess +
	"#" + heal + "#" + value + "#" + strength)) {
	write("Error in creating drink.\n");
	destruct(drink);
	return 1;
    }
    call_other(drink, "set_pub");
    move_object(drink, this_player());
    call_other(this_player(), "add_money", - value);
    write("You pay " + value + " for a " + name + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " +
	name + ".\n");
    return 1;
}

/*
 * Make this global, and only initialized once.
 */
string chat_str, function, type, match;

start_player() {
    if(!player) {
	player = clone_object("obj/monster");
player->set_name("rastaman");
player->set_short("A Rastaman");
	player->set_long( 
 "A rastaman gently swaying as he amples onward.\n");
	player->set_level(10);
        player->set_size(3);
        player->set_race("human");
	player->set_al(200);
	player->set_ep(39000);
	player->set_hp(100);
	player->set_wc(12);
move_object(player,"players/rasta/room/shop");

#ifdef MUST_STAY_WITH_DRINKS
has_drink(obj) {
     status drink;
     object ob;
     ob = first_inventory(obj);
     while(ob) {
        if (call_other(ob, "id", "drk2"))
             drink = 1;
        if (call_other(ob,"can_put_and_get")) {
             if (has_drink(ob))
                  drink = 1;
        }
        ob = next_inventory(ob);
     }
     return drink;
}
#endif

query_drop_castle() {
    return 1;
}
