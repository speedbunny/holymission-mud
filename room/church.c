/* Changed by Cashimor: added candles and has_fire */
/* 011092, 021092 */
#include "std.h"

inherit "room/room";

int lamp_is_lit, reboot_time, time_from_reset, last_reset_cycle;
int list_length;
// object wreath;

void reset(int arg) {
    if (time_from_reset)
        last_reset_cycle = time() - time_from_reset;
    time_from_reset = time();
    if (arg)
        return;

    short_desc = "Village church";

    long_desc = "You are in the local village church. " +
          "The church has the service of " +
          "reviving ghosts. Dead people come to church " +
          "and pray. There is a " +
          "huge pit in the center. An archway leads to " +
          "another chamber through " +
          "the west wall, back on the north wall is an entrance to the " +
          "Wedding Chapel of Illuvatar. In the east wall you notice " +
          "the entrance to a small side room, the church " +
          "portal opens to the " +
          "south. " +
          "You feel the peace and holiness of this place " +
          "and you are sure the " +
          "gods would punish the sacrilege of shedding blood here.\n";

    dest_dir = ({
                 "room/vill_green","south",
                 "players/cashimor/rooms/sideroom","west",
                 "players/herp/room/father","east",
                 "players/herp/room/pit","down",
                 "players/moonchild/wedding/chapel","north",
//                 "room/new_layout", "layout",
               });

    property = ({ "no_fight", "has_fire", "no_steal" });

    items = ({
              "candles","They are secured by your conscience",
              "pit","In the middle of the church is a deep pit.\n"+
                 "It was used for sacrifice in the old times, but\n" +
                 "nowadays it serves the rats for domicile",
              "altar","The altar is golden and is lit by long white candles",
              "wall","Choose a wall to look at",
              "walls","Choose a wall to look at",
              "portal","Daylight falls in from the south side",
              "west wall","There is an  archway in the west wall",
              "east wall","It has a small entrance to the east",
              "north wall","You see a beautiful golden altar and white " +
                 "candles burning on it.\n" +
                 "In the wall there is an entrance to the " +
                 "wedding chapel to the north.\n" +
                 "Over the altar you see a big church clock",
              "entrance","The north entrance leads to the wedding chapel.\n"+
                 "The east entrance leads to a praying room",
              "clock","@@_clock",
            });

    set_light(1);
    reboot_time = time();
    ::reset(arg);
}

int try_attack(object ob) {

  tell_object(ob,"Illuvatar is angry about your sacrilege. You feel bad.\n");
  say("A flash strikes "+ob->query_name()+".\n",ob);
  ob->reduce_hit_point(random(100)+1);
  return 1; /* HERP non-attacking areas will return 1, att. will return 0 */

}

init() {

    ::init();
    add_action("pray", "pray");
    add_action("pray", "regenerate");
    if(this_player() && this_player()->query_level() < 5) {
      write("Newbie map room s,s,u from church.\n");
    }
}

string _clock(string str) {

    int i, j;
    string current_time;

    current_time = "The clock shows ";
    i = time() - reboot_time;
    j = i / 60 / 60 / 24;
    if (j == 1)
        current_time += "1 day ";
    else if (j > 0)
        current_time += j + " days ";
    i -= j * 60 * 60 * 24;
    j = i / 60 / 60;
    if (j == 1)
       current_time += "1 hour ";
    else if (j > 0)
       current_time += j + " hours ";
    i -= j * 60 * 60;
    j = i / 60;
    if (j == 1)
       current_time += "1 minute ";
    else if (j > 0)
       current_time += j + " minutes ";
    i -= j * 60;
    if (i == 1)
       current_time += "1 second";
    else if (i > 0)
       current_time += i + " seconds";
    if (!this_player()->query_immortal())
       return current_time;
    current_time += ".\nTime since reset is " + (time() - time_from_reset) +
          " seconds.\n";
    if (last_reset_cycle)
       current_time += "Reset cycle: " + last_reset_cycle + "\n";
    current_time += "Free block list length: " + list_length;
    return current_time;
}

void xyzzy() {
    write("Everything shimmers.\n");
    write("You wake up elsewhere...\n");
    call_other(this_player(), "move_player", "elsewhere#room/test");
    return;
}

int pray() {

    if(this_player()->query_religion() == "Illuvatar")
        this_player()->remove_ghost();
    else if(!this_player()->query_religion()) {
        this_player()->remove_ghost();
        this_player()->set_religion("Illuvatar");
    }
    else
        write("You are not a follower of Illuvatar.\n" +
              "Return to your false god's shrine.\n");
    return 1;
}

int prevent_look_at_inv(string str) {
    return str != 0;
}

int query_drop_castle() {
    return 1;
}

void light_text(string str) {
    write("You hold the " + str +
          " into the holy candles of the altar to light it.\n");
    say(this_player()->query_name() + " lights a " + str + ",\n" +
        "using the holy candles of the altar.\n");
    return;
}
