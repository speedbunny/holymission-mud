inherit "players/cashimor/inherit/music";

reset(arg) {
  ::reset(arg);
  if(!arg) {
set_name("guitar");
   set_short("A funky string guitar");
    set_weight(2);
  set_value(135);
   set_long("It's a red, green and gold string guitar.\n");
  set_write_snd("You play a fancy reggae tune.\n");
 set_say_snd("plays a fancy reggae tune.\n");
    set_spell(25,5);
  }
}

spell_target(who) {
  if(who==this_player()) return;
  who->hit_player(10);
write("The aggressive reggae tune hurts "+who->query_name()+"'s ears!\n");
say("The aggressive reggae tune hurts "+who->query_name()+"!\n");
  return;
}
