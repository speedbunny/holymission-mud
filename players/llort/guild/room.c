/* Mangla: Who ever changed this file. If you are going to change it
    again do not. Give me a reason to change it. This is this way
    to remove some bugs.
 */

inherit "/players/saffrin/area/tower/room/oldstart";

reset(arg) {
}

init() {
  this_player()->move_player("quickly#players/saffrin/area/tower/room/oldstart");
}
