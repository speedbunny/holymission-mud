#include "../../../room/std.h"
int i, charges, price;
object targetloc;
string pointo;
int me;
 
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
            otherplayer = find_living(pointo);
            if(otherplayer == 0) {
               write("The victim is not among the living...\n");
               return 1;
               }
            /* Matt 3-20-94: added to check up on pkillers */
  /* 3.22.94 Airborne: Changed to query_real_name to see more than someone */
            targetloc = environment(otherplayer);
              if(interactive(otherplayer)) {
		write_file("/players/animal/summon.log",
			 this_player()->query_real_name() + " summoned a reaper " +
			 "against " + otherplayer->query_real_name() + " at " +
			 ctime(time()) + "\n");
	      }
            /* End Matt's edit */
                write("You summon the reaper to do your bidding.\n");
                say(call_other(this_player(),"query_name") +
                " sings the death tune.\n");
                tell_room(targetloc,
                "A dark robbed figure appears in a" +
                "blinding flash of red mist.\n");
                if (me==1)
                   write("The reaper madly grins at you.\n"); 
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
                if (me==1)
                {
                    if (otherplayer->query_level() < 33)
                       death->set_level(otherplayer->query_level()*3);
                    else 
                       death->set_level(100);
                    death->set_follower(otherplayer);
                }
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
      if (random(10))
      {
        pointo = this_player()->query_real_name();
        me = 1;
      } 
      else 
      {
        pointo = lower_case(arg);
        me = 0;
       }
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
