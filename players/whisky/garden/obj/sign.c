id(str) { return str=="sign"; }
short() { return "There is a little garden to the north"; }
init() { add_action("north","north");add_action("n","n");
n() {
call_other(this_player(), "move_player", "north#players/whisky/garden/room/garden1");
}
north() {
call_other(this_player(), "move_player", "north#players/whisky/garden/room/garden1");
}
