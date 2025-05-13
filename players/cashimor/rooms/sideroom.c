/* SIDEROOM.C - Programmed by Ethereal Cashimor */
/* 300993: Started programming */

inherit "room/room";

object wheel;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Side room of the church";
    long_desc="This is a side room, containing a kind of elevator to move you "
            + "up and down. There is a shaft leading upward and downward to "
            + "the west.\n";
    items=({"elevator","It can be used to move you up and down"});
    smell="A cold, wood-like smell hangs here.";
    dest_dir=({"room/church","east"});
    set_light(1);
  }
  if(!wheel) {
    wheel=clone_object("players/cashimor/objects/wheel");
    wheel->set_level(4);
    move_object(wheel,this_object());
  }
}
