inherit "players/cashimor/inherit/ammo";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_number(3);
    set_power(10);
    set_long("This is a beautiful fletched arrow.\n");
  }
}
