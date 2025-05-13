/* Edited by Colossus 022494 */

inherit "room/room";

reset(arg) {

    if (arg) return;
    set_light(1);
    short_desc = "In front of an old chapel";
    long_desc=
    "In this part of the graveyard there are lots of tracks on the\n"+
    "ground, not to mention some claw marks. The stench of death is\n"+
    "stronger here than in other parts of the graveyard. The very\n"+
    "smell of it is sickening and makes you want to regurgitate. There\n"+
    "is a small building towards the north and it looks like it was\n"+
    "once white but now is browned with age and decaying greatly.\n";
    items=({
      "building", "The building is a small shack that is brown and falling\n"+
      "apart. Time has not been kind to this building",
      "claw marks", "The claw marks do not look so much like animal marks\n"+
      "but those of long sharp human talons",
    });
    smell = "Foul stench of dead and decaying is so overpowering that\n"+
    "it makes you simply want to regurgitate.";
    dest_dir=({
      "/players/sherman/grave8","south",
      "/players/sherman/grave12","east",
      "/players/sherman/church1","north",
      "/players/sherman/grave10","west"
    });
    clone_list = ({1,5, "skeleton", "/players/sherman/skelleton", 0 }),
    ({2,5, "zombie", "/players/sherman/zombie", 0 });
    ::reset();
    replace_program("/room/room");
}
