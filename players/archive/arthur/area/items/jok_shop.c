#include "room.h"
#include "/players/arthur/defs/ardefs.h"
init() {
      add_action("joke", "joke");
      add_action("list", "list");
	::init();
       }
object plyr,tpn;
int i,JKN;

ONE_EXIT(AAREA+"alley_3", "south",
	"The shop",
"You are standing in Arthur's joke shop, where you can play a joke on\n" +
"just about anyone. Type 'list' to get a list of the joke's.\n", 1)


joke(str) {
string who; 
int value;

    if (!str)
      return 0;
    else if (sscanf(str, "%d on %s", JKN, who) != 2) {
	write("What joke on whom ?\n");
	return 1;}

   plyr = find_living(lower_case(who));
    if (!plyr) {
	write("No player with that name.\n");
	return 1;}
    if (JKN == 1) {value = 1000;}
    if (JKN == 2) {value = 2000;}
    if (JKN == 3) {value = 3000;}
    if (!value) {
    write("INVALID JOKE NUMBER.\n");
    return 1;}
    if (call_other(this_player(), "query_money", 0) < value) {
    write("You don't have enough money.\n");
    return 1;}

    if (call_other(TP(), "level") > 30) {
    call_other(this_player(), "add_money", 0 - value);}
    else {write("Since you are a wizard you are charged twice as much.\n");}

    write(TPN + " buys joke number: " + 
    JKN + "\n");
    tpn = TPN;
    if (tpn == "Someone") {write("You lose your money because you are invisible.\n");
    return 1;}
    i = 0; set_heart_beat(1); return 1;}

heart_beat(){
 i += 1;
 if (JKN == 1) {joke_1();}
 if (JKN == 2) {joke_2();}
 if (JKN == 3) {joke_3();}
}

joke_1() {
    if (i == 2) {
    tell_object(plyr, "Holy Mission sings: Happy birthday to you.\n");}
    if (i == 4) {
    tell_object(plyr, "Happy birthday to you!.\n");}
    if (i == 5) {
    tell_object(plyr, "Happy Birthday dear "+capitalize(plyr->query_real_name())+".\n");
}
    if (i == 6) {
    tell_object(plyr, "Happy Birthday to You!!!!!\n");}
    if (i == 7) { 
    tell_object(plyr, "A cake arrives for you!\n");}
    if (i == 8) {
    tell_object(plyr, "The cake starts to move around and with a loud BOOM!\n");
}
    if (i == 9) {
    tell_object(plyr, "Gambit jumps out!\n");}
    if (i == 10) {
    tell_object(plyr, "As fast as Gambit arrives he leaves!\n");}
    if (i == 14) { }
    if(i == 14) {}
    if (i == 15) {set_heart_beat(0); return 1;}
    }
   
joke_2() {
    tell_object(plyr, "Joke 2 test\n");
    return 1;}
joke_3() {
    tell_object(plyr, "joke 3 test\n");
    return 1;}

list() {
    write("/players/arthur/area/text/jokelist");
    return 1;}
 
