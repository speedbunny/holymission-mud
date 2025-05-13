#include "security.h"
#include "room.h"
 
 
int lamp_is_lit, reboot_time, time_from_reset, last_reset_cycle;
int list_length;
int wiz_lock, max_players;
 
reset(arg) {
    if (time_from_reset)
     last_reset_cycle = time() - time_from_reset;
    time_from_reset = time();
    "room/attic"->reset(1);
    if (arg)
    if (!present("rules", this_object())) {
     move_object(clone_object("obj/rule"),this_object());
     }
         if (!max_players)
                max_players = MAX_PLAYERS;
     /* The following code is needed to make wizlock shutdown-proof */
     restore_object("room/church");
    /* Next if-statement is to prevent against wizards. */
    if (reboot_time == 0)
               call_out("call_combine", 10);
    set_light(1);
    reboot_time = time();
}
 
init()
{
    add_action("west", "west");
    add_action("open", "open");
    add_action("push", "push");
    add_action("push", "press");
    add_action("spell"); add_verb("steal");
    add_action("spell"); add_verb("karate");
    add_action("spell"); add_verb("choke");
    add_action("spell"); add_verb("death");
    add_action("spell"); add_verb("kill");
    add_action("spell"); add_verb("but");
    add_action("spell"); add_verb("loose");
    add_action("spell"); add_verb("missile");
    add_action("spell"); add_verb("shock");
    add_action("spell"); add_verb("lightning");
    add_action("spell"); add_verb("hammer");
    add_action("spell"); add_verb("scare");
    add_action("spell"); add_verb("fireball");
    add_action("spell"); add_verb("throw");
    add_action("spell"); add_verb("blast");
    add_action("spell"); add_verb("backstab");
    add_action("do_read"); add_verb("read");
    add_action("up"); add_verb("up");
    add_action("close", "close");
    add_action("pray", "pray");
    add_action("pray", "regenerate");
    add_action("north"); add_verb("north");
    add_action("down"); add_verb("down");
    add_action("south", "south");
    add_action("east"); add_verb("east");
}
 
short() {
    return "Village church";
}
 
long(str)
{
    if (str == "clock") {
     int i, j;
     write("The clock shows ");
     i = time() - reboot_time;
     j = i / 60 / 60 / 24;
     if (j == 1)
    write("1 day ");
     else if (j > 0)
    write(j + " days ");
     i -= j * 60 * 60 * 24;
     j = i / 60 / 60;
     if (j == 1)
    write("1 hour ");
     else if (j > 0)
    write(j + " hours ");
     i -= j * 60 * 60;
     j = i / 60;
     if (j == 1)
    write("1 minute ");
     else if (j > 0)
    write(j + " minutes ");
     i -= j * 60;
     if (i == 1)
    write("1 second");
     else if (i > 0)
    write(i + " seconds");
     write("\n");
     if (!this_player()->query_wizard()) 
    return;
     write("Time since reset is " + (time() - time_from_reset) +
      " seconds.\n");
     if (last_reset_cycle)
    write("Reset cycle: " + last_reset_cycle + "\n");
     write("Free block list length: " + list_length + "\n");
     return;
    }
    if (str == "door") {
     if (!call_other("room/elevator", "query_door", 0) &&
    call_other("room/elevator", "query_level", 0))
    write("The door is open.\n");
     else
    write("The door is closed.\n");
     return;
    }
    if (str == "pit") {
     write("In the middle of the church is a deep pit.\n"+
      "It was used for sacrifice in the old times, but nowadays\n" +
      "it is only left for tourists to look at.\n");
          return;
    }
    write("You are in the main church of Realmsmud.\n"+ 
         "You see a set of stairs that go down to the healing waters of\n"+ 
  "the Realms. There is a huge pit in the center, and a door in\n"+ 
          "the west wall.\n"+ 
          "There is a button beside the door.\n");
   write("This church has the service of reviving ghosts. Dead people come\n");
    write("to the church and pray.\n");
     write("DON'T CAST SPELLS OR FIGHT IN THE CHURCH!\n");
     if (query_wiz_lock())
          write("A LARGE BLINKING SIGN SAYS \"GAME IS LOCKED TO LEVEL " + query_wiz_lock() + "!\"\n");
    write("There is a clock on the wall.\n");
    write("There are exits south, east, north, up and down.\n");
 
    if (lamp_is_lit)
        write("The lamp beside the elevator is lit.\n");
 
}
 
id(str) {
    return str == "door" || str == "pit" || str == "clock";
}
 
xyzzy() {
    write("Everything shimmers.\n");
    write("You wake up elsewhere...\n");
    call_other(this_player(), "move_player", "elsewhere#room/test");
}
 do_read(str) {
    cat("/open/player_rules");
   return 1;
 }
 spell(str) {
 call_other(this_player(), "hit_player",60);
 write("The gods strike you with a bolt of lightining!\n");
 return 1;
 }
 
west() {
    if (call_other("room/elevator", "query_door", 0) ||
          call_other("room/elevator", "query_level", 0) != 2) {
     write("The door is closed.\n");
     return 1;
    }
    call_other(this_player(), "move_player", "west#room/elevator");
    return 1;
}
 
open(str)
{
    if (str != "door")
     return 0;
    if (call_other("room/elevator", "query_level", 0) != 2) {
     write("You can't when the elevator isn't here.\n");
     return 1;
    }
    call_other("room/elevator", "open_door", "door");
    return 1;
}
 
close(str)
{
    if (str != "door")
     return 0;
    call_other("room/elevator", "close_door", "door");
    return 1;
}
 
push(str)
{
    if (str && str != "button")
     return 0;
    if (call_other("room/elevator", "call_elevator", 2))
     lamp_is_lit = 1;
    return 1;
}
 
elevator_arrives()
{
    say("The lamp on the button beside the elevator goes out.\n");
    lamp_is_lit = 0;
}
 
pray() {
    return call_other(this_player(), "remove_ghost", 0);
}
 
prevent_look_at_inv(str)
{
    return str != 0;
}
 
south() {
    call_other(this_player(), "move_player", "south#room/vill_green");
    return 1;
}
 
 down() {
    call_other(this_player(), "move_player", "down#room/clinic");
    return 1;
 }
  up() {
  this_player()->move_player("up#obj/guild/priest_guild");
    return 1;
 }
    east() {
     call_other(this_player(), "move_player", "east#players/powerslave/yard");
   return 1;
 }
 north() {
    call_other(this_player(), "move_player", "north#room/town_hall");
    return 1;
 }
 
/*
 * The next call of combine_free_list() is dependant of how long the free list
 * is. However, resorting the free list goes fast if the list is already
 * sorted.
 */
call_combine() {
    int tmp;
    tmp = time();
    list_length = combine_free_list();
    if (time() - tmp > 20)
     shout("Game driver shouts: Sorry for the delay. I had some garbage collection to do.\n");
    if (list_length < 1000)
     call_out("call_combine", 10);
    else if (list_length < 5000)
     call_out("call_combine", 30);
    else
     call_out("call_combine", 60 * 2);
}
 
query_drop_castle() {
    return 1;
}
 
query_property() { return 1; }
 
set_wiz_lock(arg) {
     if(!this_player()->query_wizard()) 
          return;
     wiz_lock = arg;
     save_object("room/church");
}
 
query_wiz_lock() {
     return wiz_lock;
}
 
set_max_players(arg) {
    if (this_player()->query_level() < SHUTDOWN)
      return;
    max_players = arg;
    save_object("room/church");
}
 
query_max_players() {
    return max_players;
}
 

