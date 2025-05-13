inherit "players/kbl/inherit/music";

int spell_done;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("gong");
    set_short("A large gong");
    set_long("It looks as if it's made from a shield.\n");
    set_write_snd("You bang the gong.\n");
    set_say_snd("bangs a gong.\n");
    set_2nd_com("bang");
    set_spell(5,1);
  }
  spell_done=0;
}

do_spell() {
object egg;

  if(random(2)) return;
  spell_done=spell_done+1;
  if(spell_done>10) return;
  write("A bird flies in, produces an egg, and leaves.\n");
  say("A bird flies in, produces an egg, and leaves.\n");
  egg=clone_object("players/kbl/guild/egg");
  move_object(egg,environment(this_player()));
  return;
}
