/* Axlrose - Human Army */
/* Soldier's Broad Sword */
inherit "obj/weapon";
object treasure, weapon;

reset(arg) {
::reset(arg);
if (arg) return;
set_name("steel broad sword");
set_alias("sword");
set_short("Steel military broad sword");
set_long
("A double-edged, heavy military sword forged from steel.  The three and \n"
+"a half foot sharp blade tapers to one side, while the leather wrapped \n"
+"hilt has an alloy shell guard on the prominent side.\n");
set_class(15);
set_value(100);
set_weight(3);
set_hit_func(this_object());
}

weapon_hit(attacker) {
int rnd;
if ( (rnd=random(5))>1) {
if (2>rnd)
return 0;
}
else {
write ("Glittering steel pieces sparkle through the air as the broad sword \n"
+"breaks in the midst of this battle!\n");
tell_room(environment(this_player()),"With a shattering sound and the sparkle of glittering steel through the \n"
+"air, " + (this_player()->query_name()) + " questions " + (this_player()->query_possessive()) + " life's future during this battle.\n");
command("unwield sword",(this_player()));
call_out("dest_me",0);
treasure = clone_object("/players/axlrose/objects/fragment_03");
transfer(treasure,this_player());
treasure = clone_object("/players/axlrose/objects/fragment_03");
transfer(treasure,environment(this_player()));
weapon = clone_object("/players/axlrose/weapons/sword_02");
transfer(weapon,this_player());
call_out("do_wield",1);
return 1;
}
}

void dest_me() 
{
destruct(this_object());
return;
}

do_wield()
{
command("wield sword",(this_player()));
}
