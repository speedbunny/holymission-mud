inherit "/obj/monster";

string chat_str;
reset(arg) {
  ::reset(arg);
chat_str=({"ARF\n"});
  if (arg) return 1;
  set_name("dog");
  set_alias("small");
  set_alt_name("dog");
set_short("small dog");
set_long("This is a small stray.  He seems lost.\nI wonder if he bites.\n");
set_level(5);
  set_al(-500);
set_hp(100);
  set_wc(8);
  set_ac(3);
  set_aggressive(0);
load_chat(20,chat_str);
  set_whimpy();
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
