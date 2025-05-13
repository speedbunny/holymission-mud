inherit"obj/monster";

object pike,armor;

reset (arg){
  ::reset(arg);
  if(!arg) {
set_name("Guard");
set_level(20);
set_gender(1);
set_race("human");
set_alias("guard");
set_al(100);
set_short("Avalonian Guard");
set_long("This hard looking guard is well equipped and stands before ready\n"+
         "to defend Avalon from all attackers.  He seems friendly, try\n"+
         "saying hi to him!\n");
set_wc(15);
set_aggressive(0);
load_chat(20,({
"The guard says: Hello stranger!\n",
"The guard says: The border to Avalon is closed with the troubles.\n",
"The guard looks around and whispers: I've heard Lord Oblivion is back.\n",
"The guard looks you over and says: Can I help you?\n",
"The guard says:These are the gates to Avalon!\n"}));
pike=clone_object("players/ambrose/avalon/weapons/pike");
armor=clone_object("players/ambrose/avalon/armour/platemail");
move_object(pike,this_object());
move_object(armor,this_object());
init_command("wield pike");
init_command("wear platemail");
set_dead_ob(this_object());
set_ac(15);
}
}
monster_died(ob){
  write("You have slain one of the righteous guards of avalon!\n"+
        "You truly must be a evil person!\n");
  return 0;
}
