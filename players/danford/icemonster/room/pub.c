object top_list, box;
reset(arg) {
if (!top_list || !present(top_list,this_object())) {
top_list = clone_object("obj/level_list");
move_object(top_list,this_object());
if (!box) {
	box = clone_object("/players/jason/obj/echobox");
	move_object(box, this_object());
}
}
if (arg) return;
set_light(1);
}
init() {
add_action("move");add_verb("north");
add_action("emote");add_verb(":");
add_action("emote",":",1);
add_action("order");add_verb("order");
add_action("order");add_verb("buy");
add_action("read");add_verb("read");
}
move() {
call_other(this_player(),"move_player","north#players/randyandy/beach/path2");
return 1;
}
short() {
return "Randyandy's Beach Pizzeria & Pub";
}
long() {
write("You are standing in Randyandy's Beach Pizzeria & Pub.\n");
write("There are various drinks and pizza's available. To see what you\n");
write("can order, just type 'read menu'.\n");
write("\n");
write("You can emote here by typing ':<action>' (for instance :smiles\n");
write("will return 'You smile')\n");
write("\n");
write("The exit lies to the north.\n");
}
order(str) {
string name,short_desc,mess,type;
int value,cost,strength,soak,heal;
if (!str) {
write("Order what?\n");
return 1;
}
if (str == "beer") {
mess = "That feels good";
heal = 1;
value = 5;
strength = 3;
type = "alcohol";
}
else if (str == "champagne") {
mess = "That was a very good champagne!";
heal = 10;
value = 80;
strength = 6;
type = "alcohol";
}
else if (str == "red wine" || str == "wine" || str == "red") {
mess = "It tastes delicious";
heal = 10;
value = 50;
strength = 10;
type = "alcohol";
}
else if (str == "white wine" || str == "wine" || str == "white") {
mess = "It tastes delicious";
heal = 10;
value = 50;
strength = 11;
type = "alcohol";
} else if (str == "vodka") {
mess = "You feel a shiver run through you";
heal = 15;
value = 100;
strength = 20;
type = "alcohol";
} else if (str == "80% rum" || str == "rum") {
mess = "A shock wave runs through your body";
heal = 35;
value = 250;
strength = 30;
type = "alcohol";
} else if (str == "coffee" || str == "cup of coffee") {
mess = "YUCK! That tastes awful!";
heal = 0;
value = 25;
strength = -4;
soak = 4;
type = "alcohol";
} else if (str == "expresso") {
mess = "It really warms you up";
heal = 0;
value = 50;
strength = -7;
soak = 7;
type = "alcohol";
} else if (str == "pizza margherita" || str == "margherita") {
mess = "You are served a small Pizza Margherita";
heal = 5;
value = 15;
strength = 5;
type = "food";
} else if (str == "pizza funghi" || str == "funghi" ) {
mess = "Your Pizza Funghi is not very big but tastes O.K";
heal = 9;
value = 35;
strength = 9;
type = "food";
} else if (str == "pizza vulcano" || str == "vulcano") {
mess = "Your Pizza Vulcano tastes hot but very satisfying";
heal = 20;
value = 100;
strength = 15;
type = "food";
} else if (str == "pizza maximo" || str == "maximo") {
mess = "You are served the biggest Pizza and feel extremly satisfied";
heal = 30;
value = 250;
strength = 20;
type = "food";
} else if (str == "pizza") {
write("The bartender says: What kinda Pizza do you want?\n");
return 1;
} else {
write("The bartender says: What do you want?\n");
return 1;
}
if (call_other(this_player(),"query_money",0)<value) {
write("That costs " + value + " gold coins, which you don't have.\n");
return 1;
}
if (type == "alcohol") {
/* soak handling added by Schlumpf at 25th July 1991   */
if(soak){
 if(!call_other(this_player(),"drink_soft",soak)){
 return 1;
 }
}
if (strength < 0) {
call_other(this_player(),"add_intoxication",(strength / 2));
} else {
int drink;
drink = strength / 2;
    if (drink > (call_other(this_player(), "query_level") + 2)) {
        if (drink > (call_other(this_player(), "query_level") + 5)) {
            /* This drink is *much* too strong for the player */
            say(call_other(this_player(), "query_name", 0) + " orders a " +
                str + ", and immediately throws it up.\n");
            write("You order a " + str + ", try to drink it, and throw up.\n");
        } else {
            say(call_other(this_player(), "query_name", 0) + " orders a " +
                str + ", and spews it all over you!\n");
 write("You order a " + str + ", try to drink it, and sputter it all over the room!\n");
        }
        call_other(this_player(), "add_money", - value);
        return 1;
    }
   if (!call_other(this_player(), "drink_alcohol", strength)) {
        write("The bartender says: I think you've had enough.\n");
        say(call_other(this_player(), "query_name", 0) + " asks for a " +
                str + " but the bartender refuses.\n");
        return 1;
    }
}
} else if (type == "food") {
int fill;
fill = (strength / 2) + 2;
if (fill > (call_other(this_player(), "query_level") + 2)) {
if (fill > (call_other(this_player(), "query_level") + 5)) {
say(call_other(this_player(), "query_name", 0) + " orders a " +
str + ", and immediately throws it up.\n");
write("You order a " + str + ", try to eat it, and throw up.\n");
} else {
say(call_other(this_player(), "query_name", 0) + " orders a " +
str + ", and gags on it!\n");
write("You order a " + str + ", try to eat it, and gag on it!\n");
}
call_other(this_player(), "add_money", - value);
return 1;
}
if (!call_other(this_player(), "eat_food", strength)) {
write("The bartender says: I don't think you can eat anymore.\n");
say(call_other(this_player(), "query_name", 0) + " asks for a " +
str + "but the bartender won't give it to him.\n");
return 1;
}
}
 write("You pay " + value + " coins for a " + str + ".\n");
say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
call_other(this_player(), "add_money", - value);
call_other(this_player(), "heal_self", heal);
write(mess + ".\n");
return 1;
}
read(str) {
if (str && str != "menu") {
write("Read what?\n");
return 1;
}
write("==========================================================\n");
write("            Randyandy's Beach Pizzeria & Pub              \n");
write("==========================================================\n");
write(" Pizza                                    Drink\n");
write("\n");
write(" Pizza Margherita  :15gp            Beer            :5gp\n");
write(" Pizza Funghi      :35gp            Champagne       :80gp\n");
write(" Pizza Vulcano     :100gp           Red Wine        :50gp\n");
write(" Pizza Maximo      :250gp           White Wine      :50gp\n");
write("                                    Vodka           :100gp\n");
write("                                    80% Rum         :250gp\n");
write("\n");
write("                    Cup of Coffee  :25gp\n");
write("                    Expresso       :50gp\n");
write("\n");
write("==========================================================\n");
return 1;
}
emote(str) {
string verb;
verb=query_verb();
if (str == 0) {str="";
str=extract(verb,1);}
else str=extract(verb,1)+" "+str;
write(this_player()->query_name()+" "+str+"\n");
say(this_player()->query_name()+" "+str+".\n");
return 1;
}
