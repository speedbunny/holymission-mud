inherit "players/cashimor/inherit/missile";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_short("A bow");
    set_long("This is an elven bow.\n");
    set_ammo_name("arrow");
  }
}
