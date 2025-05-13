inherit "players/kbl/inherit/music";
#define CTPRN capitalize(this_player()->query_real_name())
int spell_done;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("organ");
    set_short("An enourmous organ");
    set_long("It seems someone has been working a long time finding the\n"
           + "proper materials for this giant organ.\n");
    set_write_snd("You play a tune on the organ.\n");
    set_say_snd("sits down behind the organ and starts to play a tune.\n");
    set_value(0);
    set_weight(0);
    set_can_get(0);
    set_spell(100,29);
    spell_done=0;
  }
}

do_spell() {
  if(spell_done) {
    write("You get a very disappointing feeling, as the organ drains you.\n"
        + "Maybe it was used by someone already.\n");
    say("It sounds good, but exhausts the Bard playing.\n");
    return;
  }
  spell_done=1;
  shout("A well known, ghostly tune from the great composer Bach is being\n"
     + "played upon an organ. You shiver as you think what might happen.\n");
  if(file_name(environment(this_object()))!="room/church") return;
   if(this_player()->query_guild() == 6 &&
      this_player()->query_level() > 26 &&
      this_player()->query_level() < 30)
   {
     log_file("kbl.organ",CTPRN+" played the organ on "+ctime(time())+"\n");
     shout(CTPRN+" plays a organ that stirs the very heart of Holy Mission.\n");
   }
    else
   {
     log_file("kbl.organ",CTPRN+" tried to play organ on "+ctime(time())+"\n"); 
     write("You fail to play the tune completely.\n");
     shout(CTPRN+" failed to play the tune completely.\n");
     spell_done = 0;
     return;
   }
  this_player()->add_exp(20000);
  "players/kbl/guild/shut"->shut(10);
  command("south",find_living("little armageddon"));
  return 1;
}
