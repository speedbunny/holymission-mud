inherit "room/room";
#include "/players/mangla/defs.h"
object obj;
int read(string str) {
    if(str!="sign") return 0;
    write("It reads: Due to bad business we only repair and convert armours.\n");
    return 1;
}
int search(string str) {
  if(str!="shelves" && str!="shelf") return 0;
  write("They are totally empty.\n");
  say(TP->NAME + " searches in the shelves.\n");
  return 1;
}
int repair(string str) {
object obj;
int cost;
if (!present("myclerk",TO)) {
        write("There is no one here at this time to do that.\n");
        return 1;
    }
if(str!="boots" && str!="gloves") {
        write("The man says: I cannot repair those items.\n");
        return 1;
    }
    obj = present(str,TP);
    if(!obj) {
        write("The man says: You don't own such a item.\n");
        return 1;
    }
    cost = TP->LEVEL/TP->CHA*100+2000;
    if(TP->query_money() < cost) {
        write("The man says : I would charge you " + cost + " coins, but you don't have them.\n");
        return 1;
    }
    else {
        write("You pay " + cost + " coins for repairing " + obj->NAME + ".\n");
        TP->add_money(-cost);
        obj->recharge();
        return 1;
    }
}
int convert(string str) {
    string what,size;
    object obj;
    int cost,i;
    if (!present("myclerk",TO)) {
        write("There is no one here at this time to do that.\n");
        return 1;
    }
    if(!str) {
        write("The man says: Convert what to which size?\n");
        return 1;
    }
    if(sscanf(str,"%s to %s",what,size)!=2) {
        write("The man says: Convert what to which size?\n");
        return 1;
    }
    if(size!="small" && size!="medium" && size!="large") {
        write("The man says: I do not know that size!\n" +
              "Available sizes are: small, medium, large.\n");
        return 1;
    }
    obj = present(what,TP);
    if(!obj) {
        write("The man says: You don't have such an item.\n");
        return 1;
    }
    if(!obj->armour_class()) {
        write("The man says: We can only convert armours.\n");
        return 1;
    }
    i=1;
    switch (size) {
        case "large"  : i++;
        case "medium" : i++;
        case "small"  : i++;
    }
    if(!obj->query_size()) {
        write("The man asks : Why do you want to change this armour?\n");
        return 1;
    }
/*
    if(obj->query_size()-i<0) {
        write("The man says: Sorry, I can't make an armour bigger.\n");
        return 1;
    }
*/
    if(!obj->query_size()-i) {
        write("The man grins and says: Always at your service.\n"+
              "Hope I'll see you soon again.\n");
    }
    cost = 500 + (obj->query_size() - i) * 1000;
    if (cost<0) cost =- cost;
    cost = cost + 50 / TP->CHA;
    if(TP->query_money() < cost) {
        write("The man shakes his head in disagreement.\n" +
              "He says: I charge " + cost + " coins for that.\n" +
              "         You do not have enough money!\n");
        return 1;
    }
    obj->set_size(i);
    write("You pay " + cost + " coins to the man.\n");
    TP->add_money(-cost);
    return 1;
}
void reset(int arg) {
    if (arg) return;
    set_light(1);
short_desc="The Armoury.";
long_desc=
  "You have entered the local armoury. It is quite busy and there "+
  "are hot fires, massive bellows, a sign, and shelves filled "+
  "with objects scattered throughout the room. It is "+
  "extremely hot in here\n";
    dest_dir=({
               "players/kelly/rooms/vill/road3","west",
             });
    items=({
            "sign","It reads: Due to bad business we only repair and convert armours",
            "shelves","They are made of wood and completly empty",
            "shelf","The shelves are made of wood and completely empty",
	"bellows","The massive bellows are there to make the fire scortching hot",
	"fires","The fires need to be very hot so that the armourer can change the armours",
          });
    if(!present("myclerk",TO)) {
        MOVE(clone_object("players/kelly/monster/myclerk"),TO);
        }
}

init() {

    ::init();
    add_action("search","search");
    add_action("read","read");
    add_action("convert","alter");
    add_action("convert","convert");
    add_action("repair","repair");
}


