inherit "room/room";
int locked;
string dest, ans, con, launch, arg, viri, tank;
reset(arg)
{
    if (!arg)
	set_light(1);
}

init()
{
    add_action("out"); add_verb("out");
    add_action("go"); add_verb("go");
    add_action("view"); add_verb("view");
    add_action("read"); add_verb("read");
    add_action("lock"); add_verb("lock");
    add_action("unlock"); add_verb("unlock");
    add_action("pa"); add_verb("pa");
    add_action("snag"); add_verb("snag");
    add_action("eject"); add_verb("eject");
    add_action("nquit"); add_verb("quit");
con = present("console");
ans = (call_other(con, "am_i_con"));
if (ans != "damnstraight") {
destruct(con);
}
}

out()
{
    if (locked == 0) {
	write("You exit the Panzer.\n");
dest = find_living("panzer");
if (!dest) {
dest = clone_object("players/silas/private/panzer");
move_object(dest, "players/silas/workroom");
}
say(call_other(this_player(), "query_name") + " exits through the hatch.\n");
move_object(this_player(), environment(dest));
	say(call_other(this_player(), "query_name") + " hops out of the Panzer.\n");
call_other(this_player(), "look");
	return 1;
    }
write("The hatch seems to be locked.\n");
    return 1;
}

long()
{
    write("This is the inside of roaring WWII Panzer.  The noise is deafening and you can\n");
    write("feel the power.  It would be a good idea to 'read'.\n");
}

short() {
    return "Inside the Panzer";
}

go(arg) {
string envi;
dest = find_living("panzer");
viri = environment(dest);
if ( arg == "north" || arg == "n") {
    call_other(dest, "init_command", "north");
}
if ( arg == "south" || arg == "s") {
    call_other(dest, "init_command", "south");
}
if ( arg == "east" || arg == "e") {
    call_other(dest, "init_command", "east");
}
if ( arg == "west" || arg == "w") {
    call_other(dest, "init_command", "west");
}
if ( arg == "up" || arg == "u") {
    call_other(dest, "init_command", "up");
}
if ( arg == "down" || arg == "d") {
    call_other(dest, "init_command", "down");
}
if ( arg == "enter" || arg == "enter") {
    call_other(dest, "init_command", "enter");
}
if ( arg == "in" || arg == "in") {
    call_other(dest, "init_command", "in");
}
if ( arg == "out" || arg == "out") {
    call_other(dest, "init_command", "out");
}
if (arg == "exit") {
    call_other(dest, "init_command", "exit");
}
if (arg == "temple") {
    call_other(dest, "init_command", "temple");
}
if (arg == "nw" || arg == "northwest") {
    call_other(dest, "init_command", "northwest");
}
if (arg == "ne" || arg == "northeast") {
    call_other(dest, "init_command", "northeast");
}
if (arg == "sw" || arg == "southwest") {
    call_other(dest, "init_command", "southwest");
}
if (arg == "se" || arg == "southeast") {
    call_other(dest, "init_command", "southeast");
}
if (arg == "board" || arg == "board panzer") {
    arg == "yeahright";
}
if (viri == environment(dest)) {
write("You seem to have bumped into something.\n");
return 1;
}
dest = find_living("panzer");
envi = environment(dest);
tell_room("players/silas/private/inpanzer", call_other(this_player(), "query_name") + " moves the panzer " + arg + ":\n");
tell_room("players/silas/private/inpanzer", call_other(envi, "short") + "\n");
return 1;
}

view() {
int max;
string enfi, tank, it, ob;
tank = find_living("panzer");
enfi = environment(tank);
tell_room(enfi, "The Panzer surveys its surroundings.\n");
write("You see:\n");
write(call_other(enfi, "long") + "\n");
     ob = first_inventory(enfi);
        max = 20;
        while(ob && max > 0) {
            if (ob != tank) {
                string short_str;
                short_str = call_other(ob, "short");
                if (short_str) {
                    max -= 1;
                    write(short_str + ".\n");
                    it = short_str;
                }
            }
            ob = next_inventory(ob);
        }
return 1;
}
lock() {
  if (locked) {

write("Panzer hatch is already locked!\n");
return 1;
}
tank = find_living("panzer");
call_other(tank, "lock");
tell_room("players/silas/private/inpanzer", call_other(this_player(), "query_name") + " locks the hatch.\n");
locked = 1;
return 1;
}
unlock() {
  if (!locked) {
write("The hatch is already unlocked!\n");
return 1;
}
tank = find_living("panzer");
call_other(tank, "unlock");
tell_room("players/silas/private/inpanzer", call_other(this_player(), "query_name") + " unlocks the hatch.\n");
locked = 0;
return 1;
}

pa(arg) {
if (!arg) {
write("Must type: pa <message>.\n");
return 1;
}
tell_room("players/silas/private/inpanzer", "The PA system fires up:" + arg + "\n");
tank = find_living("panzer");
tell_room(environment(tank), "The Panzer PA blares: " + arg + "\n");
return 1;
}

snag(arg) {
string item_o;
  if (!arg) {
write("What do you want to snag?\n");
return 1;
}

if (locked) {
write("You can't activate the tractor beam when the hatch is locked.\n");
return 1;
}
tank = find_living("panzer");
item_o = present(arg, environment(tank));
if (item_o == tank) {
return 0;
}
if (!item_o) {
write("There is no "+arg+" outside of the panzer!\n");
return 1;
}
  if (call_other(item_o, "query_npc")) {
write("The monster eludes the tractor beam!\n");
return 1;
}

if (call_other(item_o, "is_player") == 0) {
if (call_other(item_o, "get") == 0 && call_other(item_o, "can_put_and_get") == 0) {
write("You cannot snag that!\n");
return 1;
}
}
tell_room("players/silas/private/inpanzer", call_other(item_o, "short") + " is grabbed by the tractor beam and hauled aboard!\n");
  move_object(item_o, "players/silas/private/inpanzer");
tell_room(environment(tank), call_other(item_o, "short") + " is grabbed by the Panzer's tractor beam and hauled inside!\n");
tell_object(item_o, "You are grabbed by the Panzer's tractor beam and hauled inside!\n");
tank = find_living("panzer");
return 1;
}
eject(arg) {
string item_o;
if (!arg) {
write("Eject what?\n");
return 1;
}
if (locked) {
write("You cant eject something when the hatch is locked!\n");
return 1;
}
tank = find_living("panzer");
item_o = present(arg, find_object("players/silas/private/inpanzer"));
if (!item_o) {
write("There is no "+arg+" in the Panzer!\n");
return 1;
}
if (call_other(item_o, "am_i_con") == "damnstraight") {
return 0;
}
tell_room(environment(tank), call_other(item_o, "short") + " is ejected from the Panzer!\n");
tell_object(item_o, "You are ejected from the Panzer!\n");
move_object(item_o, environment(tank));
tell_room("players/silas/private/inpanzer", "HOORAY!!  "+call_other(item_o, "short") + " is ejected from the Panzer!\n");
return 1;
}
read() {
write("These are the instructions for the Panzer:\n");
write("To grab a player or object:  type snag <object>\n");
write("To eject a player or object:  type eject <object>\n");
write("To move:  go <dir>\n");
write("To see environment:  view\n");
write("To exit:  out\n");
write("To close/open hatch, type lock/unlock\n");
write("To activate the external PA system, type pa <message>\n");
write("It would also be a good idea to 'look at console'\n");
return 1;
}
realm() { return "NT"; }

nquit() {
write("You can't quit inside the Panzer!\n");
return 1;
}
