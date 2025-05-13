/*
 * This is a shut down deamon, that will take care of shutting down
 * the game.
 * Call the function "shut" with a number of seconds as an
 * argument.
 * Don't clone this object.
 */

#define SHOUT(x)  efun::shout(x)

int moved_yet;

inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg)
        return;
    set_name("armageddon");
    set_level(1);
    set_wc(1000);
    set_ac(1000);
    set_hp(10000);
    set_ep(0); /* Herp */
    set_spell_mess1("Armageddon crashes the game.");
    set_spell_mess2("Armageddon crashes the game on your head.");
    set_chance(75);
    set_spell_dam(500);
    set_short("Armageddon the game crasher");
    set_long("He seems to firmly concentrated on counting.\n");
    set_alias("shut");
    set_wimpy(-1);
    mmsgin = "arrives through a rift in the fabric of space";
    move_player("X#room/church");
    is_wizard=1; /* Herp */
}

init() {
   add_action("do_shut","shut");
}

do_shut(str) {
int time; 
 
  if (this_player()->query_level()<50) return ;
  if (!str || !sscanf(str,"%d",time)) return;
  shut(time);
  return 1;
}

shut(seconds)
{
    int i;
    
    if (!intp(seconds)) {
        write("Bad argument\n");
        return 1;
    }
    if (seconds == 0) {
        write("No time given\n");
        return 1;
    }
    set_long("He is firmly concentrated on counting.\n");
    i = remove_call_out("cont_shutting");
    if (i > 0) {
        i = (i + 10) * 4;
        if (i < seconds) {
            write("There was already a shutdown in process, " + i +
                  " seconds.\n");
            seconds = i;
        }
    }
    call_out("cont_shutting", 0, seconds * 60);
    return 1;
}

int transport_offer;

cont_shutting(seconds) {
    string delay;
    int new_delay;

    if (seconds <= 0) {
        SHOUT(cap_name + " shouts: I will reboot now.\n");
        shutdown();
        return;
    }
    if (seconds <= 10 && !moved_yet) {
        moved_yet=1;
        SHOUT(cap_name + " shouts: Come to the shop and sell your stuff!\n");
        move_all_players();
    } 
    if (seconds <= 240 && !transport_offer) {
        SHOUT(cap_name +
            " shouts: Tell me if you want a trip to the shop!\n");
        transport_offer = 1;
    }
    new_delay = seconds * 3 / 4 - 10;
    call_out("cont_shutting", seconds - new_delay, new_delay);
    delay = "";
    if (seconds > 59) {
        delay = seconds / 60 + " minutes";
        seconds = seconds % 60;
    }
    if (seconds != 0)
        delay += " " + seconds + " seconds";
    SHOUT(cap_name + " shouts: Game reboot in " + delay + ".\n");
}

move_all_players() {
object list;
int i;

        list = users();
        for (i=0; i<sizeof(list); i++)
            if (list[i]->query_level()<30) {
            tell_object(list[i],"You are magically transferred to the shop.\n");
            move_object(list[i],"room/main_shop");
/*
	    command("sell all",list[i]);
*/
            }
}
 
query_name()
{
  return "armageddon";
}
catch_tell(str) {
    string who, what;
    object ob;

    if (!transport_offer)
        return;
    if (sscanf(str, "%s tells you: %s", who, what) != 2)
        return;
    this_player()->move_player("X#room/main_shop");
}
