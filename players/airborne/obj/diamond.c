#include "../../../room/std.h"
int i, charges, price;
object targetloc;
string pointo;
 
id(str)
{
 return str == "diamond" ||  str == "black diamond";
}
 
reset(arg) {
    if (!arg) charges= random(1)+1;
}
 
long() {
    write("This is a black diamond shaped in the form of a heart.\n");
    write("It is unusually cold to the touch.\n");
    write("You can make out a small word in the diamond.\n");
    write("The word says <call> There is also a figure in the\n"+
          "diamond that looks like the grim reaper!\n");
}
 
short() {
     return "A black diamond";
}
 
query_value()
{
    return 5000;
}
 
init() {
    add_action("summon"); add_verb("call");
    add_action("set"); add_verb("death");
    add_action("stat"); add_verb("stat");
}
 
summon(arg) {
    string realm, destrealm;
    object otherplayer;
    object death;
 
    if (arg != "reaper" && arg != "grim reaper") {
     write("Whom are you calling.....\n");
        return 1;
    }
     if(i != 1) {
          write("You hear an EVIL laugh inside your head: "+
               "Who needs death?\n");
               return 1;
               }

/*     Updated 4/28/93 to locate and go after invis players as:  */ 
/*          otherplayer = find_living(pointo);                   */
/*     Does not locate invisable players and returns             */
/*     "The victim is not among the living...".                  */
/*                          --Renegade                           */

           otherplayer = find_player(pointo);
            if(otherplayer == 0) {
               write("The victim is not among the living...\n");
               return 1;
               }
            targetloc = environment(otherplayer);
                write("You summon the reaper to do your bidding.\n");
                say(call_other(this_player(),"query_name") +
                " sings the death tune.\n");
                tell_room(targetloc,
                "A dark robbed figure appears in a" +
                "blinding flash of red mist.\n");
                tell_room(targetloc,
                "The reaper is here to claim "+capitalize(pointo)+".\n");
                death = clone_object("obj/monster");
                call_other(death, "set_name", "grim reaper");
                call_other(death, "set_alt_name", "death");
                call_other(death, "set_alias", "reaper");
                call_other(death, "set_short", "Grim reaper");
                call_other(death, "set_level", 19);
                call_other(death, "set_ep", 10000);
                call_other(death, "set_al", -1000);
                call_other(death, "set_wc", 26);
                call_other(death, "set_ac", 10);
                call_other(death, "set_aggressive", 0);
                call_other(death, "set_can_kill", 1);
                move_object(death, targetloc);
                death->attack_object(otherplayer);
                if (charges == 1) {
                    destruct(this_object());
                    write("You watch as the diamond crumbles to dust.\n");
                    tell_room(targetloc, "The diamond has vanished!\n");
                    call_other(this_player(),"add_weight", -1);
                }
                charges=charges-1;
                return 1;
}
 
set(arg) {
 
    if (!arg) {
        return 0;
    }
    else {
 
        pointo = lower_case(arg);
        write("The reaper understands.\n");
        i = 1;
    }
   return 1;
}
 
get() {
    return 1;
}
 
query_weight() {
    return 1;
}
 
stat(arg) {
    if (!arg || arg != "black diamond" ||
        !this_player()->query_wizard()) return 0;
    write("Diamond stats:\ncharges: "+charges+"\nsetting: "+pointo+"\n");
    return 1;
}
