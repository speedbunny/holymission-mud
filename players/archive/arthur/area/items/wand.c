/*Code by Arthur for Holy Mission - 140.78.3.1 Date Done 11.4.94 */
inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h"

int amount;

reset (arg) {
if (arg) return;
   set_id("Wand");
   set_short("A very deadly looking wand");
   set_alias("wand");
   set_long("The wand is black with faded text on it which says:\n"+
   "'?h??t ?is? a?', unfortunately you are not sure of all the characters.\n");
   set_value(1700);
   amount=10;
   set_weight(4);
}
init() {
     add_action("disk_hit", "shoot");
}
disk_hit(str){
    object ob;
    string enm;
    if(!str) return 0;
    sscanf(str,"disk at %s",enm);
    if (!enm) return 0;
        ob = present(lower_case(enm), environment(this_player()));
    if (!ob || !living(ob)) {return 0;}
    if (ob == TP()) {
        write("Why would you want to throw that at yourself?\n");
        return 1;
    }
    if (ob->query_npc() != 1) {
        write("You wouldn't want to shoot a disk at another player!\n");
        return 1;
    }
    write("You shoot a disk at "+capitalize(enm)+" causing an emense amount of damage!\n");
    say(TPN+" shoots "+capitalize(enm)+" with a disk.");
    
   CO(ob,"hit_player",random(100000));
    
    amount=amount-1;
    if(amount==0) {write("The wand fades out of distance.\n");
    destruct(this_object());}
    return 1;
}
