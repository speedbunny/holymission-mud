/* WIZ_HALL.C */
/* 240693: Ethereal Cashimor: Old elevator introduced */
/* 280693: Ethereal Cashimor: Room below the elevator made */

inherit "room/room";

object leo,wheel;

reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc="wizards hall";
    long_desc="You are in the hall of the wizards. There is a shaft to the "
            + "west. Upward it extends to a great length, but downward it "
            + "ends quickly. Also there is a shimmering field to the north.\n";
    items=({"hall","It is very big",
            "field","You can't help but wonder what's behind it"});
    no_obvious_msg="";
    smell="The air is VERY cold here.";
    if(!wheel) {
      wheel=clone_object("players/cashimor/objects/wheel");
      move_object(wheel,this_object());
    }
  }
  if(!leo) {
    leo=clone_object("obj/leo");
    move_object(leo, this_object());
  }
}

init() {
    ::init();
    add_action("north","north");
}

north() {
  if(!this_player()->query_wizard()) {
    write("A strong magic force stops you.\n");
    return 1;
  }
  write("You wriggle through the force field...\n");
  this_player()->move_player("north#room/quest_room");
   return 1;
}
