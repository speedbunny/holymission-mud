inherit"obj/treasure";
reset(arg) {
if (arg) return;
set_id("quest_key");
set_alias("golden key");
set_short("Golden key");
set_long("This is a small golden key. What's it for?\n");
set_weight(0);
set_value(10);
return;
}
