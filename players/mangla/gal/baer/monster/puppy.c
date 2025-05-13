inherit "obj/monster";
string chats;

reset(arg) {
::reset(arg);
if (!arg) {
set_name("puppy");
set_level(10);
set_hp(100);
set_race("dog");
set_short("Puppy");
set_long("A lab puppy with a big red bow on it\n");
set_wc(10);
set_ac(10);
set_aggressive(0);
if (!chats) {
chats=allocate(2);
chats[0]="Puppy barks happily.\n";
chats[1]="Puppy wags its tail\n";
}
load_chat(5,chats);
}
}
