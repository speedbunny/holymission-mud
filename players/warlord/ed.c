inherit"obj/monster";
reset(arg) {
::reset();
if (arg) return;
set_name("ed");
set_short("Ed");
set_long("This is Ed, he wants to be your friend.\n");
set_level(10);
set_gender(1);
load_chat(20,({
"Ed says: I have long hair.\n",
"Ed says: I love to play instruments",
}));
set_aggressive(1);
return 1;
}
