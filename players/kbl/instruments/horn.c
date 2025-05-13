inherit "players/kbl/inherit/music";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("horn");
    set_short("A fine horn");
    set_long("It looks as if it could make a deafening noise.\n");
    set_write_snd("You blow your lungs out in the horn.\n");
    set_say_snd("evokes a deafening noise from a horn.\n");
    set_spell(18,7);
    set_2nd_com("blow");
  }
}

do_spell() {
  write("You here a distant echo from your blow.\n");
  shout("You here the sound of a powerful horn blowing in the distance.\n");
  return;
}
